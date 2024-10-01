It took a bit of time to translate python to cpp.
```cpp
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] || grid[m-1][n-1])
            return 0;
        vector<vector<int>> safe(m, vector<int>(n, -1));
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                if (grid[i][j]){
                    q.push({0, i, j});
                    safe[i][j] = 0;
                }
            }
        }
        vector<int> dir = {-1, 0, 1, 0, -1};
        int safety, r, c;
        while (!q.empty()){
            safety = q.front()[0], r = q.front()[1], c = q.front()[2];
            q.pop();
            for (int i=0; i<4; i++){
                int new_r = r + dir[i], new_c = c + dir[i+1];
                if (new_r >= 0 && new_r < m && new_c >=0 && new_c < n && safe[new_r][new_c]==-1){
                    safe[new_r][new_c] = safety + 1;
                    q.push({safety + 1, new_r, new_c});
                }
            }
        }
        priority_queue<vector<int>> pq;
        vector<vector<bool>> found(m, vector<bool>(n, false));
        pq.push({safe[0][0], 0, 0});
        while (!pq.empty()){
            safety = pq.top()[0], r = pq.top()[1], c = pq.top()[2];
            pq.pop();
            if (!found[r][c]){
                found[r][c] = true;
                if (r == m-1 && c == n-1)
                     break;
                for (int i=0; i<4; i++){
                    int new_r = r + dir[i], new_c = c + dir[i+1];
                    if (new_r >= 0 && new_r < m && new_c >=0 && new_c < n && 
                        !found[new_r][new_c]){
                        pq.push({min(safe[new_r][new_c], safety), new_r, new_c});
                    }
                }
            }
        }
        return safety;
    }
};
```
In second solution there is only a minor change in Dijkstra's inner loop where we update ```found[new_r][new_c] = true;```. In my opinion this can only work in this particular problem and I like my first code above.
```cpp
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] || grid[m-1][n-1])
            return 0;
        vector<vector<int>> safe(m, vector<int>(n, -1));
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                if (grid[i][j]){
                    q.push({0, i, j});
                    safe[i][j] = 0;
                }
            }
        }
        vector<int> dir = {-1, 0, 1, 0, -1};
        int safety, r, c;
        while (!q.empty()){
            safety = q.front()[0], r = q.front()[1], c = q.front()[2];
            q.pop();
            for (int i=0; i<4; i++){
                int new_r = r + dir[i], new_c = c + dir[i+1];
                if (new_r >= 0 && new_r < m && new_c >=0 && new_c < n && safe[new_r][new_c]==-1){
                    safe[new_r][new_c] = safety + 1;
                    q.push({safety + 1, new_r, new_c});
                }
            }
        }
        priority_queue<vector<int>> pq;
        vector<vector<bool>> found(m, vector<bool>(n, false));
        pq.push({safe[0][0], 0, 0});
        while (!pq.empty()){
            safety = pq.top()[0], r = pq.top()[1], c = pq.top()[2];
            pq.pop();
            // if (!found[r][c]){
                // found[r][c] = true;
            if (r == m-1 && c == n-1)
                    break;
            for (int i=0; i<4; i++){
                int new_r = r + dir[i], new_c = c + dir[i+1];
                if (new_r >= 0 && new_r < m && new_c >=0 && new_c < n && 
                    !found[new_r][new_c]){
                    pq.push({min(safe[new_r][new_c], safety), new_r, new_c});
                    found[new_r][new_c] = true;
                }
            }
        }
        return safety;
    }
};
```
And someone implemented 0-1 BFS (first time to hear it) using deque. I adapted it to my code.
```cpp
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        deque<vector<int>> q;
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] || grid[m-1][n-1])
            return 0;
        vector<vector<int>> safe(m, vector<int>(n, -1));
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                if (grid[i][j]){
                    q.push_back({i, j, 1});
                }
                --grid[i][j];
            }
        }
        vector<int> dir = {-1, 0, 1, 0, -1};
        int safety, r, c;
        while (!q.empty()){
            r = q.front()[0], c = q.front()[1], safety = q.front()[2];
            q.pop_front();
            for (int i=0; i<4; i++){
                int new_r = r + dir[i], new_c = c + dir[i+1];
                if (new_r >= 0 && new_r < m && new_c >=0 && new_c < n && grid[new_r][new_c]==-1){
                    grid[new_r][new_c] = safety;
                    q.push_back({new_r, new_c, safety + 1});
                }
            }
        }
        int min_safety = grid[0][0];
        q.push_back({0, 0, grid[0][0]});
        while (!q.empty()){
            r = q.front()[0], c = q.front()[1], safety = q.front()[2];
            q.pop_front();
            min_safety = min(min_safety, safety);
            if (r == m-1 && c == n-1)
                break;
            for (int i=0; i<4; i++){
                int new_r = r + dir[i], new_c = c + dir[i+1];
                if (new_r >= 0 && new_r < m && new_c >=0 && new_c < n && 
                    grid[new_r][new_c] != -1){
                    safety = grid[new_r][new_c];
                    grid[new_r][new_c] = -1;
                    if (safety < min_safety){
                        q.push_back({new_r, new_c, safety});
                    }
                    else {
                        q.push_front({new_r, new_c, safety});
                    }
                }
            }
        }
        return min_safety;
    }
};
```
If you want to learn more about 0-1 BFS:

- you can check this GFG [example](https://www.geeksforgeeks.org/0-1-bfs-shortest-path-binary-graph/) for shortest path in a binary weight graph. It's interesting that time complexity is O(E+V) instead of Dijkstra's O(E + VlogV).

- Also check out this codeforces [post](https://codeforces.com/blog/entry/22276).

  So, when we are at vertex
            u
            ,
            our queue contains elements of level
            L
            [
            u
            ] or
            L
            [
            u
            ] + 1
            .
            And we also know that
            for an edge
            (u,v)
            ,
            L
            [
            v
            ] is either
            L
            [
            u
            ] or
            L
            [
            u
            ] + 1
            .
            Thus , if the vertex
            v
            is
            relaxed and has the same level , we can push it to the front of our queue and
            if it has the very next level , we can push it to the end of the queue. This
            helps us keep the queue sorted by level for the
            BFS
            to work properly.   
```python
class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        safety = deque()
        r, c = len(grid), len(grid[0])
        visited = set()
        for i in range(r):
            for j in range(c):
                if grid[i][j]==1:
                    safety.append((i,j,0))
                    visited.add((i,j))
        safety_grid = [[0 for _ in range(c)] for _ in range(r)]
        dir = [-1, 0, 1, 0, -1]
        while safety:
            row, col, safeness = safety.popleft()
            safety_grid[row][col] = safeness
            
            for i in range(4):
                new_r, new_c = row + dir[i], col + dir[i+1]
                if 0 <= new_r < r and 0 <= new_c < c and (new_r, new_c) not in visited:
                    visited.add((new_r, new_c))
                    safety.append((new_r, new_c, safeness+1))
        
        max_heap = [(-safety_grid[0][0], (0,0))]
        visited = set()
        while max_heap:
            safety_factor, pos = heapq.heappop(max_heap)
            safety_factor *= -1
            visited.add(pos)
            if pos[0]==r-1 and pos[1]==c-1:
                return safety_factor
            for i in range(4):
                new_r, new_c = pos[0] + dir[i], pos[1] + dir[i+1]
                if 0 <= new_r < r and 0 <= new_c < c and (new_r, new_c) not in visited:
                    path_safety = min(safety_factor, safety_grid[new_r][new_c])
                    heapq.heappush(max_heap, (-path_safety, (new_r, new_c)))
                    visited.add((new_r, new_c))
```
