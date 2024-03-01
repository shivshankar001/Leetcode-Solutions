class Solution {
public:
    double dp[105][105];
    double rec(int i, vector<int>& nums, int k)
    {
        //base case
        if(i>=nums.size() || k<0)
        {
            return 0;
        }
        if(k==0)
        {
            return INT_MIN;
        }
        //cache check 
        if(dp[i][k] != 0)
        {
            return dp[i][k];
        }
        //compute
        double sum = 0;
        double ans = 0;
        for(int j=i; j<nums.size(); j++)
        {
            sum += nums[j];
            ans = max(ans, (sum/(j-i+1))+rec(j+1, nums, k-1));
        }
        //save and return
        return dp[i][k]=ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        // vector<vector<double>> dp(nums.size(), vector<double>(nums.size(), -1));
        memset(dp, 0, sizeof(dp));
        return rec(0, nums, k);
    }
};