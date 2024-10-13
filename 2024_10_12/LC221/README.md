First successful submission took more than I expected with only 13% beat rate.
```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& g) {
        int m = g.size(), n = g[0].size();
        int ans = 0, res;
        vector<int> prev(n, 0);
        for (int i=m-1; i>=0; i--){
            res = solver(prev, g[i]);
            cout << res;
            if (res > ans)
                ans = res;
        }
        return ans*ans;
    }

    int solver(vector<int>& prev, vector<char> curr) {
        int n = prev.size(), ans = 0;
        // update prev
        for (int i=0; i<n; i++){
            prev[i] = (curr[i] == '1' ? prev[i] + 1: 0); 
        }
        // find largest square with top side on current row
        if (n==1)
            return prev[0]==1;
        stack<int> st;
        vector<int> res(n, 1);
        st.push(0);
        for (int i=1; i<n; i++){
            int temp = 0;
            while(!st.empty() && prev[st.top()] >= prev[i]){
                res[st.top()] += temp;
                int width = min(res[st.top()], prev[st.top()]);
                ans = max(ans, width);
                temp = res[st.top()];
                st.pop();
            }
            if (st.empty())
                res[i] = i+1;
            else{
                res[i] += temp;
            }
            st.push(i);
        }
        while(!st.empty()){
            int last = st.top();
            int width = min(res[st.top()], prev[st.top()]);
            ans = max(ans, width);
            st.pop();
            if (!st.empty())
                res[st.top()] += res[last];
        }
        return ans;
        
    }   
};
```
