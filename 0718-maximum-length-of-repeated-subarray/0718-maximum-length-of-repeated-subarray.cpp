class Solution {
public:
    int ans1 = 0;
    int rec(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp)
    {
        if(i>=nums1.size() || j>=nums2.size())
        {
            return 0;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        int ans = 0;
        rec(i+1, j, nums1, nums2, dp);
        rec(i, j+1, nums1, nums2, dp);
        
        if(nums1[i] == nums2[j])
        {
            ans = max(ans, 1 + rec(i+1, j+1, nums1, nums2, dp));
        }
        else
        {
            ans = 0;
        }
        
        ans1 = max(ans1, ans);
        
        return dp[i][j] = ans;
        
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        int temp = rec(0, 0, nums1, nums2, dp);
        return ans1;
    }
};