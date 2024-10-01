class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool val(int i, int j, int n, int m)
    {
        if(i>=0 && i<n && j>=0 && j<m)
        {
            return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> v(n, vector<int>(m, -1));
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i, j}, 0});
                    v[i][j] = 0;
                }
            }
        }
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int x = it.first.first;
            int y = it.first.second;
            int t = it.second;
            for(int k=0; k<4; k++)
            {
                int nx = x+dx[k];
                int ny = y+dy[k];
                if(val(nx, ny, n, m))
                {
                    if(v[nx][ny]==-1 && grid[nx][ny]==1)
                    {
                        v[nx][ny] = t+1;
                        q.push({{nx, ny}, t+1});
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(v[i][j]==-1 && grid[i][j]==1)
                {
                    return -1;
                }
                else if(v[i][j]!=-1)
                {
                    ans = max(ans, v[i][j]);
                }
            }
        }
        return ans;
    }
};