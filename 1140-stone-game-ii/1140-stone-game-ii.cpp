class Solution {
public:
    
    int dp[100][101], n, s[100];
    vector<int> v;
    
    int rec(int y, int z)
    {
        if (y >= n) return 0;
        if (dp[y][z] != -1) return dp[y][z];
        int ans = 0, sum = 0;
        for(int i = y; i < n && i - y + 1 <= 2 * z; i++)
        {
            sum += v[i];
            ans = max(ans, sum + (i + 1 < n ? s[i + 1] : 0) - rec( i + 1, min(n, max(z, i - y + 1))));
        }
        return dp[y][z] = ans;
    }
    
    int stoneGameII(vector<int>& a) 
    {
        n = a.size();
        v = a;
        memset(dp, -1, sizeof(dp));
        int x = 0;
        for(int i = n - 1; i >= 0; i--) x += a[i], s[i] = x;
        // for(int i=0;i<n;i++)
        //     cout<<s[i]<<" ";
        return rec(0, 1); // add
    }
};