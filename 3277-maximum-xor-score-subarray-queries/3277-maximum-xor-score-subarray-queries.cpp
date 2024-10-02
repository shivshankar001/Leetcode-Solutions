class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        for(int i=0; i<n; i++)
        {
            dp[i][i] = nums[i];
        }
        for(int j=1; j<n; j++)
        {
            for(int i=j-1; i>=0; i--)
            {
                dp[i][j] = dp[i+1][j]^dp[i][j-1];
            }
        }
        for(int j=1; j<n; j++)
        {
            for(int i=j-1; i>=0; i--)
            {
                dp[i][j] = max({dp[i+1][j], dp[i][j-1], dp[i][j]});
            }
        }
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<n; j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int sz = queries.size();
        vector<int> ans(sz);
        for(int i=0; i<sz; i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            ans[i] = dp[l][r];
        }
        return ans;
    }
};