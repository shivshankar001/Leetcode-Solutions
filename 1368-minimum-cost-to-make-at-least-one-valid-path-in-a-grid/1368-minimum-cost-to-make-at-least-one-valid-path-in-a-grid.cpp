class Solution
{
public:
    bool check(int x, int y, int m, int n)
    {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
    int minCost(vector<vector<int>> &grid)
    {

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        deque<pair<int, int>> q;
        q.push_front({0, 0});
        dist[0][0] = 0;
        while (!q.empty())
        {
            auto node = q.front();
            q.pop_front();
            int x = node.first;
            int y = node.second;
            for (int k=0; k<4; k++)
            {
                int nx = dx[k] + x;
                int ny = dy[k] + y;
                if (check(nx, ny, m, n))
                {
                    int cost = 0;
                    if(k+1!=grid[x][y])
                    {
                        cost = 1;
                    }
                    if(dist[nx][ny]>dist[x][y]+cost)
                    {
                        dist[nx][ny] = dist[x][y]+cost;
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
        return dist[m - 1][n - 1];
    }
};