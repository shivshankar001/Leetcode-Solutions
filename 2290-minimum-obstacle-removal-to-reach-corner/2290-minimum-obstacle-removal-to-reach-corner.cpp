class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool check(int i, int j, int n, int m)
    {
        if(i>=0 && i<n &&j>=0 && j<m)
        {
            return true;
        }
        return false;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        deque<pair<int, int>> q;
        q.push_front({0, 0});
        dis[0][0] = 0;
        while(!q.empty())
        {
            auto it = q.front();
            int x = it.first;
            int y = it.second;
            q.pop_front();
            for(int k=0; k<4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(check(nx, ny, n, m))
                {
                    int cost = 0;
                    if(grid[nx][ny]==1)
                    {
                        cost = 1;
                    }
                    if(dis[nx][ny]>dis[x][y]+cost)
                    {
                        dis[nx][ny] = dis[x][y]+cost;
                        if(cost==0)
                        {
                            q.push_front({nx, ny});
                        }
                        else
                        {
                            q.push_back({nx, ny});
                        }
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};