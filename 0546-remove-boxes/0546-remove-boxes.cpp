class Solution {
public:
    int n;
    int dp[105][105][105];
    int rec(int l, int r, int cnt, vector<int>& a)
    {
        if(l>r)
        {
            return 0;
        }
        if(l==r)
        {
            return ((cnt+1)*(cnt+1));
        }
        if(dp[l][r][cnt] != -1)
        {
            return dp[l][r][cnt];
        }
        int ans = 0;
        ans = max(ans, ((cnt+1)*(cnt+1)) + rec(l+1, r, 0, a));
        for(int i=l+1; i<=r; i++)
        {
            if(a[i]==a[l])
            {
                ans = max(ans, rec(l+1, i-1, 0, a)+rec(i, r, cnt+1, a));
            }
        }
        return dp[l][r][cnt] = ans;
    }
    int removeBoxes(vector<int>& a) {
        n = a.size();
        memset(dp, -1, sizeof(dp));
        return rec(0, n-1, 0, a);
    }
};