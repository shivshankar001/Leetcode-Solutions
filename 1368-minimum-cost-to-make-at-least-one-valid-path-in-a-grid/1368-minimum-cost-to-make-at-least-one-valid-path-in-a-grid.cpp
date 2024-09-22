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
            int x1 = node.first;
            int y1 = node.second;
            int dir = grid[x1][y1];
            for (auto k : {0, 1, 2, 3})
            {
                int x2 = dx[k] + x1;
                int y2 = dy[k] + y1;

                if (check(x2, y2, m, n) && dist[x1][y1] + (grid[x1][y1] != (k + 1)) < dist[x2][y2])
                {
                    dist[x2][y2] = dist[x1][y1] + (grid[x1][y1] != (k + 1));
                    if ((grid[x1][y1] == (k + 1)))
                    {
                        q.push_front({x2, y2});
                    }
                    else
                    {
                        q.push_back({x2, y2});
                    }
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};