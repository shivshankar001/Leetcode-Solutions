class Solution {
public:
    int n;
    bool check(int mid, vector<int> &dp)
    {
        for(int i=0; i<n && i+mid<n; i++)
        {
            cout<<mid<<" "<<dp[i]<<" "<<dp[i+mid]<<endl;
            if(dp[i]==mid && dp[i+mid]==mid)
            {
                return true;
            }
        }
        return false;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n, 1);
        dp[n-1] = 1;
        for(int i=n-2; i>=0; i--)
        {
            if(nums[i]<nums[i+1])
            {
                dp[i] = dp[i+1]+1;
            }
        }
        for(int i=0; i<n; i++)
        {
            cout<<dp[i]<<" ";
        }
        cout<<endl;
        int ans = 1;
        for(int i=0; i<n; i++)
        {
            if(i+dp[i]<n && dp[i]<=dp[i+dp[i]])
            {
                ans = max(ans, dp[i]);
            }
            ans = max(ans, dp[i]/2);
        }
        return ans;
    }
};