class Solution {
public:
    int rec(vector<int> &rewardValues, int i, int sum, vector<vector<int>> &dp)
    {
        if(i>=rewardValues.size())
        {
            return 0;
        }
        
        if(dp[i][sum] != -1)
        {
            return dp[i][sum];
        }
        
        int t1 = 0;
        if(sum < rewardValues[i])
        {
            t1 = rewardValues[i] + rec(rewardValues, i+1, sum + rewardValues[i], dp);
        }
        
        int t2 = rec(rewardValues, i+1, sum, dp);
        
        return dp[i][sum] = max(t1, t2);
    }
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        sort(rewardValues.begin(), rewardValues.end());
        vector<vector<int>> dp(n+1, vector<int>(4001, -1));
        return rec(rewardValues, 0, 0, dp);
    }
};