class Solution {
public:
    int rec(int i, int j, vector<int>& num, vector<vector<int>> &dp)
    {
        // base case
        if(i+1>=j)
        {
            return 0;
        }
        
        // cache check 
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        // compute
        int ans = INT_MIN;
        for(int p=i+1; p<j; p++)
        {
            int temp = num[i]*num[p]*num[j]+rec(i,p, num, dp)+rec(p,j, num, dp);
            ans = max(ans, temp);
        }
        
        //save and return 
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {

        vector<int> num;
        num.push_back(1);
        for(int i=1; i<=nums.size(); i++)
        {
            num.push_back(nums[i-1]);
        }
        num.push_back(1);
        
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return rec(0, num.size()-1, num, dp);
    }
};