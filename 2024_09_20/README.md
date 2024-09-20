Hello

This is today's first coding practice. After failing to solve it on my own, I looked at LC users' solutions. I was able to guess we should sort the efficiency in decreasing order, but the **greedy** approach didn't cross my mind. Indeed the hard tag misled me. I coded in python and cpp after I woke up. Thanks to users like [Lee215](https://leetcode.com/u/lee215/) for their high quality coding practice.
```cpp
int maxPerformance(int n, vector<int>& sp, vector<int>& eff, int k) {
    vector<pair<int, int>> es(n);
    for (int i=0; i<n; i++){
        es.push_back({eff[i], sp[i]}); // es[i] = {eff[i], sp[i]};
    }
    sort(es.rbegin(), es.rend()); //sort(rbegin(es), rend(es));
    long long totSpeed = 0; 
    long long ans = 0; //long totSpeed = 0, ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    for (int i=0; i<n; i++){
        totSpeed += es[i].second;
        pq.push(es[i].second);
        if (pq.size()>k){
            totSpeed -= pq.top();
            pq.pop();
        }
        ans = max(ans, totSpeed*es[i].first);
    }
    return ans % (1000000007); // (int) (1e9+7)
}

```

Now let's code in Python:

```python
def maxPerformance(self, n: int, sp: List[int], eff: List[int], k: int) -> int:
    es = sorted(zip(eff, sp), reverse=True) // key=lambda x: -x[1]
    speed = []
    totSpeed = 0
    ans = 0
    for e, s in es:
        totSpeed += s
        heapq.heappush(speed, s)
        if len(speed) > k:
            totSpeed -= heapq.heappop(speed)
        ans = max(ans, totSpeed*e)
    return int(ans % (1000000000+7))
```
# Time/Space Complexity

Time: 
- O(NlogN) for sorting
- O(NlogK) for popping minimum speed from minheap/priority queue when we introduce a new engineer

Space:
- O(N)

# Bonus: Java practice

```java
public int maxPerformance(int n, int[] speed, int[] efficiency, int k) {
    List<int[]> es = new ArrayList<>();
    for (int i=0; i<n; i++)
        es.add(new int[]{efficiency[i], speed[i]});
    Collections.sort(es, (a,b) -> b[0]-a[0]);
    long totSpeed = 0, ans = 0;
    PriorityQueue<Integer> pq = new PriorityQueue<>(k);
    for (int[] elem: es){
        totSpeed += elem[1];
        pq.add(elem[1]);
        if (pq.size() > k)
            totSpeed -= pq.poll();
        ans = Math.max(ans, totSpeed*elem[0]);
    }
    return (int)(ans % (1000000007)); // using 1e9+7 can (will) introduce floating-point operation inaccuracies for some test cases! Lee215 uses (long)(1e9+7) as a cure.
}
```

Instead of list we can use array data structure (adopted from [Lee215](https://leetcode.com/u/lee215/) solution)
```java
public int maxPerformance(int n, int[] speed, int[] efficiency, int k) {
    int[][] es = new int[n][2]; // 2D array of primitive type int
    for (int i=0; i<n; i++)
        es[i] = (new int[]{efficiency[i], speed[i]});
    Arrays.sort(es, (a,b) -> b[0]-a[0]); // sort from Array class, in decreasing order of efficiency
    long totSpeed = 0, ans = 0;
    PriorityQueue<Integer> pq = new PriorityQueue<>(k); // PriorityQueue<>(k, (a,b) -> a-b)
    for (int[] elem: es){
        totSpeed += elem[1];
        pq.add(elem[1]);
        if (pq.size() > k)
            totSpeed -= pq.poll();
        ans = Math.max(ans, totSpeed*elem[0]);
    }
    return (int)(ans % (long)(1e9 + 7));
}
```
