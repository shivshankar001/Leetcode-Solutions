class Solution {
public:
    int n;
    int dp[100010][2];
    int rec(int i, char c, string &s)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[i][c-'0'] != -1)
        {
            return dp[i][c-'0'];
        }
        int ans1 = 1e9, ans2 = 1e9;
        if(c=='0')
        {
            if(s[i]=='0')
            {
                ans1 = rec(i+1, s[i], s);
                ans2 = 1+rec(i+1, '1', s);
            }
            else
            {
                ans1 = rec(i+1, s[i], s);
                ans2 = 1+rec(i+1, '0', s);
            }
        }
        else
        {
            if(s[i]=='0')
            {
                ans1 = 1+rec(i+1, '1', s);
            }
            else
            {
                ans1 = rec(i+1, s[i], s);
            }
        }
        return dp[i][c-'0'] = min(ans1, ans2);
    }
    int minFlipsMonoIncr(string s) {
        n = s.size();
        memset(dp, -1, sizeof(dp));
        return rec(0, '0', s);
    }
};