class Solution {
public:
    int rec(vector<pair<int, int>> adj[], int i, int dst, int n, int k, vector<vector<int>> &dp)
    {
        if(i == dst)
        {
            return 0;
        }
        if(k <= 0)
        {
            return 1e7;
        }
        
        if(dp[i][k] != -1)
            return dp[i][k];
        
        int x = 1e7;
        for(auto it : adj[i])
        {
            x = min(x, it.second+rec(adj, it.first, dst, n, k-1, dp));
        }
        
        return dp[i][k] = x;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int, int>> adj[n];
        for(int i=0; i<flights.size(); i++)
        {
            int fr = flights[i][0], to = flights[i][1], pr = flights[i][2];
            adj[fr].push_back({to, pr});
        }
        
        vector<vector<int>> dp(101, vector<int>(101, -1));
        int ans = rec(adj, src, dst, n, k+1, dp);
        
        if(ans == 1e7) return -1;
        return ans;
    }
};