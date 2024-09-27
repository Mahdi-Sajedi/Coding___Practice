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
