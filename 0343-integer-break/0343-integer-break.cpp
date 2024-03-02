class Solution {
public:
    int num;
    int rec(int n, vector<int> &dp)
    {
        if(n==0 && num>=1)
        {
            return 1;
        }
        if(n==0 && num==0)
        {
            return 0;
        }
        if(n==1)
        {
            return 1;
        }
        
        if(dp[n] != -1)
        {
            return dp[n];
        }
        //compute
        int ans = INT_MIN;
        for(int i=n; i>=1; i--)
        {
            ans = max(ans, i*rec(n-i, dp));
            num++;
        }
        
        return dp[n]=ans;
    }
    int integerBreak(int n) {
        vector<int> dp(n+1, -1);
        return rec(n, dp);
    }
};