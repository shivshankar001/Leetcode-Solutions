class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n+1);
        dp[0] = nums[0];
        for(int i=1; i<n; i++)
        {
            dp[i] = dp[i-1] + nums[i];
            if(i-2 >= 0)
            {
                dp[i] = max(dp[i], dp[i-2] + nums[i-1]-nums[i]);
            }
            else
            {
                long long temp = nums[i-1]-nums[i];
                dp[i] = max(dp[i], temp);
            }
        }
        
        return dp[n-1];
    }
};