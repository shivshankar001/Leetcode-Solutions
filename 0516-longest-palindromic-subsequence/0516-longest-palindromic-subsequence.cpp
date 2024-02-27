class Solution {
public:
    int rec(string &s, string &t, int i, int j, vector<vector<int>> &dp)
    {
        //base case
        if(i>=s.size() || j>=t.size())
        {
            return 0;
        }
        //cache check
        if(dp[i][j]  != -1)
        {
            return dp[i][j];
        }
        //compute
        int ans = 0;
        ans = max(ans, rec(s, t, i+1, j, dp));
        ans = max(ans, rec(s, t, i, j+1, dp));
        if(s[i] == t[j])
        {
            ans = max(ans, 1+rec(s, t, i+1, j+1, dp));
        }
        //save and return
        return dp[i][j]=ans;
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return rec(s, t, 0, 0, dp);
    }
};