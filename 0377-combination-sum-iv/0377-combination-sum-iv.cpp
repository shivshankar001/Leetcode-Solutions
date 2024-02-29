class Solution {
public:
    int rec(vector<int>& nums, int target, vector<int> &dp)
    {
        //base case
        if(target == 0)
        {
            return 1;
        }
        if(target < 0)
        {
            return 0; 
        }
        
        //cache check
        if(dp[target] != -1)
        {
            return dp[target];
        }
        
        //compute
        int ans = 0;
        for(int i=0; i<nums.size(); i++)
        {
            ans += rec(nums, target-nums[i], dp);
        }
        
        //save and return
        return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return rec(nums, target, dp);
    }
};