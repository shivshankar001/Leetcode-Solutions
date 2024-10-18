class Solution {
public:
    int dp[1005][1005];
    int countSquares(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
       for (int i = 0; i <= n; ++i) {
           for (int j = 0; j <= m; ++j) {
               dp[i][j] = 0;
           }
       }
       int ans = 0;
       for (int i = 1; i <= n; ++i) {
           for (int j = 1; j <= m; ++j) {
               if(grid[i-1][j-1]) {
                   dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
               }
               ans += dp[i][j];
           }
       }
       return ans;
    }
};