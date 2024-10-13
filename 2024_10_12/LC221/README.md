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

## DP approach (thanks to [LCuser](https://jianchao-li.github.io/post/interpret-pytorch-models-with-captum/))
```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& g) {
        int m = g.size(), n = g[0].size(), ans=0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (int k=0; k<n; k++){
            dp[0][k] = (g[0][k] == '1'? 1: 0);
            ans = max(ans, dp[0][k]);
        }
        for (int k=0; k<m; k++){
            dp[k][0] = (g[k][0] == '1'? 1: 0);
            ans = max(ans, dp[k][0]);
        }
        for (int i=1; i<m; i++){
            for (int j=1; j<n; j++){
                if (g[i][j]=='1'){
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans*ans;
    }   
};
// beats 17%, 90 ms
```
## Space Optimized DP (2 vectors of size n for m by n grid)
```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& g) {
        int m = g.size(), n = g[0].size(), ans=0;
        vector<int> vec(n, 0), temp(n,0);
        for (int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (i==0 || j==0 || g[i][j]=='0')
                    temp[j] = g[i][j] - '0';
                else{
                    temp[j] = min(temp[j-1], min(vec[j], vec[j-1])) + 1;
                }
                ans = max(ans, temp[j]);
            }
            swap(temp, vec);
/*
            for(int j=0; j<n; j++)
                vec[j] = temp[j];
*/
        }
        return ans*ans;
    }   
};
```
## Space Optimized (1 vector of size n and one int)
```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& g) {
        int m = g.size(), n = g[0].size(), ans=0;
        vector<int> vec(n, 0);
        int pre;
        for (int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int temp = vec[j];
                if (i==0 || j==0 || g[i][j]=='0')
                    vec[j] = g[i][j] - '0';
                else{
                    vec[j] = min(pre, min(vec[j], vec[j-1])) + 1;
                }
                pre = temp;
                ans = max(ans, vec[j]);
            }
        }
        return ans*ans;
    }   
};
```

## [example](https://leetcode.com/problems/maximal-square/solutions/1632376/C++Python-6-Simple-Solution-w-Explanation-or-Optimizations-from-Brute-Force-to-DP/) of deep digging 

