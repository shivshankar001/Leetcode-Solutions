class Solution {
public:
    vector<int> start;
    int rec(int i, vector<vector<int>>& intervals, vector<int> &dp)
    {
        //base case
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
        int take = 0, not_take = 0;
        
        auto it = lower_bound(start.begin()+1, start.end(), intervals[i][1]);
        int idx = it - start.begin();
        
        take = 1+rec(idx, intervals, dp);
        not_take = rec(i+1, intervals, dp);
        
        //save and return
        return dp[i] = max(take, not_take);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<int> dp(intervals.size()+1,-1);

        for(int i=0;i<intervals.size();i++)
        {
            start.push_back(intervals[i][0]);
            
        }
        return intervals.size()-rec(0,intervals,dp);
    }
};