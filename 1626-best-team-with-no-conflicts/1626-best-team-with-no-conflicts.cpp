class Solution {
public:
//     int rec(int i, vector<pair<int, int>> &v)
//     {
// //         if(i>=v.size() || i<0)
// //         {
// //             return 0;
// //         }
        
// //         int ans = v[i].second;
// //         for(int j=0; j<i; j++)
// //         {
// //             if(v[i].second>=v[j].second)
// //             {
// //                 ans = max(ans, v[j].second+rec(j, v));   
// //             }
// //         }
        
// //         return ans;
        
        
//     }
    
    int a[1000], n, dp[1000];
    
    int r(int x)
    {
        if (x >= n) return 0;
        else if (dp[x] != -1) return dp[x];
        int ans = 0;
        for(int i = x + 1; i < n; i++)
        {
            if (a[i] >= a[x]) ans = max(ans, r(i));
        }
        return dp[x] = a[x] + ans;
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        memset(dp, -1, sizeof(dp));
        vector<pair<int, int>> v;
        for(int i=0; i<scores.size(); i++)
        {
            v.push_back({ages[i], scores[i]});
        }
        sort(v.begin(), v.end());
        int ans = 0;
        n = ages.size();
        for(int i = 0; i < n; i++) a[i] = v[i].second;
        for(int i=0; i<n; i++) ans = max(ans, r(i));
        return ans;
    }
    
    // int r(int x)
    // {
    //     if (x >= n) return 0;
    //     else if (dp[x] != -1) return dp[x];
    //     int ans = 0;
    //     for(int i = x + 1; i < n; i++)
    //     {
    //         if (a[i] >= a[x]) ans = max(ans, rec(i));
    //     }
    //     return dp[x] = a[x] + ans;
    // }
};