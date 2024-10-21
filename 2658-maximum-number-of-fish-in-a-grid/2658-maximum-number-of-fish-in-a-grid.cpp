class Solution {
public:
    bool vis[20][20];
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int n, m;
    bool valid(int i, int j)
    {
        if(i>=0 && i<n && j>=0 && j<m)
        {
            return true;
        }
        return false;
    }
    int dfs(int i, int j, vector<vector<int>>& a)
    {
        vis[i][j] = true;
        int ans = a[i][j];
        for(int k=0; k<4; k++)
        {
            int nx = i+dx[k];
            int ny = j+dy[k];
            if(valid(nx, ny) && a[nx][ny] > 0 && !vis[nx][ny])
            {
                ans += dfs(nx, ny, a);
            }
        }
        return ans;
    }
    int findMaxFish(vector<vector<int>>& a) {
        int sum = 0;
        int maxi = 0;
        n = a.size();
        m = a[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                vis[i][j] = false;
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] && a[i][j]>0)
                {
                    maxi = max(maxi, dfs(i, j, a));
                }
            }
        }
        return maxi;
    }
};