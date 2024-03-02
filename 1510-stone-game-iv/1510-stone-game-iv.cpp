class Solution {
public:
    bool rec(int n, vector<int> &dp)
    {
        if(n <= 0)
        {
            return 0;
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }
        int ans = 0;
        for(int i=1; i*i<=n; i++)
        {
            if(rec(n-i*i, dp) == 0)
            {
                ans = 1;
                break;
            }
        }
        
        return dp[n]=ans;
    }
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1, -1);
        return rec(n, dp);
    }
};