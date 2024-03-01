class Solution {
public:
    int rec(int i, vector<pair<int, int>> &v, vector<int> &dp)
    {
        // base check
        if(i>=v.size() || i<0)
        {
            return 0;
        }
        //cache check
        if(dp[i] != -1)
        {
            return dp[i];
        }
        //compute
        int ans = v[i].second;
        for(int j=0; j<i; j++)
        {
            if(v[i].second>=v[j].second)
            {
                ans = max(ans, v[i].second+rec(j, v, dp));   
            }
        }
        //save and return
        return dp[i]=ans;
        
        
    }
    
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        vector<pair<int, int>> v;
        for(int i=0; i<scores.size(); i++)
        {
            v.push_back({ages[i], scores[i]});
        }
        
        sort(v.begin(), v.end());
        
        vector<int> dp(ages.size(), -1);
        
        int ans = 0;
        for(int i=0; i<ages.size(); i++) ans = max(ans, rec(i, v, dp));
        return ans;
    }
    
};