class Solution {
public:
    int n;
    int rec(int i, vector<int>& days, vector<int>& costs, vector<int> &dp)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[i] != -1)
        {
            return dp[i];
        }
        int ans = INT_MAX;
        for(int j=0; j<costs.size(); j++)
        {
            if(j==0)
            {
                ans = min(ans, costs[j] + rec(i+1, days, costs, dp));
            }
            else if(j == 1)
            {
                auto it = upper_bound(days.begin(), days.end(), days[i]+6);
                int idx = (it - days.begin());
                ans = min(ans, costs[j] + rec(idx, days, costs, dp));
            }
            else
            {
                auto it = upper_bound(days.begin(), days.end(), days[i]+29);
                int idx = (it - days.begin());
                ans = min(ans, costs[j] + rec(idx, days, costs, dp));
            }
        }
        return dp[i] = ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        vector<int> dp(n, -1);
        return rec(0, days, costs, dp);
    }
};