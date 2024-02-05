class Solution {
public:
    int sol(vector<string>& strs, int m, int n, int idx, vector<vector<vector<int>>> &dp)
    {
        if(idx >= strs.size())
        {
            return 0;
        }
        
        if(dp[m][n][idx] != -1)
        {
            return dp[m][n][idx];
        }
        
        int cnt_0 = count(strs[idx].begin(), strs[idx].end(), '0');
        int cnt_1 = strs[idx].size() - cnt_0;
        
        if(m-cnt_0 >= 0 && n-cnt_1 >= 0)
        {
            return dp[m][n][idx] = max(1+sol(strs, m-cnt_0, n-cnt_1, idx+1, dp), sol(strs, m, n, idx+1, dp));
        }
        
        return dp[m][n][idx] = sol(strs, m, n, idx+1, dp);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(strs.size()+1, -1)));
        return sol(strs, m, n, 0, dp);
    }
};