#include<bits/stdc++.h>
class Solution {
public:
    vector<pair<int, int>> v;
    int rec(int i, vector<string>& strs, int m, int n, vector<vector<vector<int>>> &dp)
    {
        //base case
        if(i>=strs.size())
        {
            return 0;
        }
        //cache check
        if(dp[i][m][n] != -1)
        {
            return dp[i][m][n];
        }
        //compute
        int dt=0, t=0;
        dt = rec(i+1, strs, m, n, dp);
        if(m>=v[i].first && n>=v[i].second)
        {
            t = 1 + rec(i+1, strs, m-v[i].first, n-v[i].second, dp);
        }
        //save and return
        return dp[i][m][n]=max(dt, t);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        // vector<pair<int, int>> v;
        int num = strs.size();
        int maxi = 0;
        int tcnt0 = 0, tcnt1 = 0;
        for(int i=0; i<strs.size(); i++)
        {
            int cnt0 = 0, cnt1 = 0;
            for(int j=0; j<strs[i].size(); j++)
            {
                if(strs[i][j] == '0')
                {
                    cnt0++;
                    tcnt0++;
                }
                else
                {
                    cnt1++;
                    tcnt1++;
                }
            }
            if(strs[i].size()>maxi)
            {
                maxi = strs[i].size();
            }
            v.push_back({cnt0, cnt1});
        }
        cout<<tcnt0<<endl;
        // vector<vector<vector<int>>> dp(num+1, vector<vector<int>>(maxi, vector<int>(maxi, -1)));
        vector<vector<vector<int>>> dp(num, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        // cout<<1<<endl;
        return rec(0, strs, m, n, dp);
    }
};