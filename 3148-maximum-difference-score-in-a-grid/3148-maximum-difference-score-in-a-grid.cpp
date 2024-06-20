class Solution {
public:
    int rec(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp)
    {
        int n = grid.size(), m = grid[0].size();
        if(i>=n || j>=m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        int p=INT_MIN, np=INT_MIN;
        if(i+1<n) p=(grid[i+1][j]-grid[i][j]) + rec(i+1, j, grid, dp);
        if(j+1<m) np=(grid[i][j+1]-grid[i][j]) + rec(i, j+1, grid, dp);
        
        return dp[i][j] = max(0, max(p, np));
    }
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int maxi = INT_MIN;
        int maxi1 = INT_MIN;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                maxi = max(maxi, rec(i, j, grid, dp));
                if(i+1<n) maxi1=max(maxi1, grid[i+1][j]-grid[i][j]);
                if(j+1<m) maxi1=max(maxi1, grid[i][j+1]-grid[i][j]);
            }
        }
        
        if(maxi==0) return maxi1;
        return maxi;
    }
};