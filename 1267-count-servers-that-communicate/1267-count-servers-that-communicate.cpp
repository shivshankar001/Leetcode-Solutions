class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int &cnt)
    {
        vis[i][j] = 1;
        cnt++;
        for(int temp=0; temp<grid[0].size(); temp++)
        {
            if(!vis[i][temp] && grid[i][temp] == 1)
            {
                dfs(i, temp, grid, vis, cnt);
                // vis[i][temp] = 1;
                // cnt++;
            }
        }
        for(int temp=0; temp<grid.size(); temp++)
        {
            if(!vis[temp][j] && grid[temp][j] == 1)
            {
                dfs(temp, j, grid, vis, cnt);
                // vis[temp][j] = 1;
                // cnt++;
            }
        }
        
        return cnt;
    }
    int countServers(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int ans = 0;
        vector<vector<int>> vis(row+1, vector<int>(col+1, 0));
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    int temp = 0;
                    int cnt = dfs(i, j, grid, vis, temp);
                    if(cnt >= 2)
                    {
                        ans += cnt;
                    }
                }
            }
        }
        
        return ans;
    }
};