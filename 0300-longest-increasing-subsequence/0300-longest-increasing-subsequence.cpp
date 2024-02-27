class Solution {
public:
    int rec(int i, vector<int>& intervals, vector<int> &dp)
    {
        if(i<0 || i>=intervals.size())
        {
            return 0;
        }
        //cache check
        if(dp[i] != -1)
        {
            return dp[i];
        }
        //compute
        int ans = 1;
        for(int j=0; j<i; j++)
        {
            if(intervals[i]>intervals[j])
            {
                ans = max(ans, 1+rec(j, intervals, dp));
            }
        }
        
        //save and return 
        return dp[i] = ans;
    }
    int lengthOfLIS(vector<int>& intervals) {
        int ans = INT_MIN;
        vector<int> dp(intervals.size(), -1);
        for(int i=0; i<intervals.size(); i++)
        {
            ans = max(ans, rec(i, intervals, dp));
        }
        return ans;
    }
};