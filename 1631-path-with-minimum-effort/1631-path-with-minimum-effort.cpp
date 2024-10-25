using ii = pair<int, int>;
class Solution {
public:
    int n, m;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool val(int i, int j)
    {
        if(i>=0 && i<n && j>=0 && j<m)
        {
            return true;
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;
        pq.push({0, {0, 0}});
        int dis[n][m];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                dis[i][j] = 1e9;
            }
        }
        dis[0][0] = 0;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int x = it.second.first;
            int y = it.second.second;
            for(int k=0; k<4; k++)
            {
                int nx = x+dx[k];
                int ny = y+dy[k];
                if(val(nx, ny))
                {
                    int temp = abs(heights[nx][ny]-heights[x][y]);
                    int t = max(temp, wt);
                    if(dis[nx][ny]>t)
                    {
                        dis[nx][ny] = min(dis[nx][ny], t);
                        pq.push({dis[nx][ny], {nx, ny}});
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};