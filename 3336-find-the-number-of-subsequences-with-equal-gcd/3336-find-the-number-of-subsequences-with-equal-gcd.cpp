class Solution {
public:
    int mod = 1e9+7;
    int n;
    int dp[205][205][205];
    int rec(int i, int g1, int g2, vector<int>& nums)
    {
        if(i>=n)
        {
            if(g1==g2)
            {
                return 1;
            }
            return 0;
        }
        if(dp[i][g1][g2] != -1)
        {
            return dp[i][g1][g2];
        }
        int ans = 0;
        ans = ((ans%mod) + (rec(i+1, __gcd(nums[i], g1), g2, nums)%mod))%mod;
        ans = ((ans%mod) + (rec(i+1, g1, __gcd(nums[i], g2), nums)%mod))%mod;
        ans = ((ans%mod) + (rec(i+1, g1, g2, nums)%mod))%mod;
        return dp[i][g1][g2] = ans%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, 0, nums)-1;
    }
};