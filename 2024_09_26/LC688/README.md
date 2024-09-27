I'm ashamed to share my wrong solution which ignored all probablity laws! Here is a good starting point (thanks to [LCuser](https://leetcode.com/u/kevincongcc/)):

```python
class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        def solver(n, k, r , c, dp):
            r_dir = [-1, -2, -2, -1, 1, 2, 2, 1]
            c_dir = [-2, -1, 1, 2, 2, 1, -1, -2]
            if (r < 0 or r >= n or c < 0 or c >= n):
                return 0
            if k==0:
                return 1
            if dp[r][c][k]!=0:
                return dp[r][c][k]
            prob = 0
            for i in range(8):
                prob += 1/8 * solver(n, k-1, r + r_dir[i], c + c_dir[i], dp)
            dp[r][c][k] = prob
            return prob

        dp = [[[0 for _ in range(k+1)] for _ in range(n)] for _ in range(n)]
        return solver(n, k, row, column, dp)
```

For cpp i had a hard time trying to use 3d array for dp. I had to declare the dimensions rather than letting them be dynamic(25, 101 instead of n,k+1).
```cpp
class Solution {
public:
    int r_dir[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int c_dir[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    

    double knightProbability(int n, int k, int row, int column) {
        double dp[25][25][101];
        memset(dp, 0, sizeof(dp));  // Set all elements of the array to 0
        return solver(n, k, row, column, dp);
    }
    double solver(int n, int k, int r, int c, double dp[][25][101]){
        if (r < 0 || r >= n || c < 0 || c >= n) return 0;
        if (k == 0) return 1;
        if (dp[r][c][k]) return dp[r][c][k];
        double ans = 0;
        for (int i=0; i<8; ++i){
            ans += 1.0/8 *solver(n, k-1, r + r_dir[i], c + c_dir[i], dp);
        }
        dp[r][c][k] = ans;
        return ans;
    }
};
```
Or this one:
```cpp
class Solution {
public:
    int r_dir[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int c_dir[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    double dp[25][25][101];

    double knightProbability(int n, int k, int row, int column) {
        memset(dp, 0, sizeof(dp));  // Set all elements of the array to 0
        return solver(n, k, row, column);
    }
    double solver(int n, int k, int r, int c){
        if (r < 0 || r >= n || c < 0 || c >= n) return 0;
        if (k == 0) return 1;
        if (dp[r][c][k]) return dp[r][c][k];
        double ans = 0;
        for (int i=0; i<8; ++i){
            ans += 1.0/8 *solver(n, k-1, r + r_dir[i], c + c_dir[i]);
        }
        dp[r][c][k] = ans;
        return ans;
    }
};
```
A user stored r+'firstname'+c+'lastname'+str(moves) as a key in dictionary rather than having 3d array or vector. pretty clever.
```cpp
string key = to_string(r) + "aryan" + to_string(c) + "mittal" + to_string(moves);
if(mp.find(key) != mp.end())
    return mp[key];
```
