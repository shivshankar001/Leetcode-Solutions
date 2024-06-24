class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        vector<long long> dp(nums.size()+1);
        dp[0] = nums[0];
        for(int i=1; i<nums.size(); i++)
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
        
        return dp[nums.size()-1];
    }
};