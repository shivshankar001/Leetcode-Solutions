class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    // Helper function to check if a position is within the grid
    bool val(int x, int y, int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    
    // Helper function to determine if a cell is on the border
    bool isBorder(int x, int y, vector<vector<int>>& grid, int n, int m, int color) {
        if (x == 0 || x == n-1 || y == 0 || y == m-1) {
            return true; // On the grid's edge
        }
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (val(nx, ny, n, m) && grid[nx][ny] != color) {
                return true; // Neighboring a different color
            }
        }
        return false;
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans = grid; // Initialize answer grid with original grid
        vector<vector<int>> visited(n, vector<int>(m, 0)); // Track visited cells
        int originalColor = grid[row][col];
        
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = 1;
        
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            // Check if the current cell is a border cell
            if (isBorder(x, y, grid, n, m, originalColor)) {
                ans[x][y] = color; // Color the border cell
            }
            
            // Explore the four directions
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                
                // If the neighboring cell is within bounds, not visited, and has the original color
                if (val(nx, ny, n, m) && !visited[nx][ny] && grid[nx][ny] == originalColor) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        
        return ans; // Return the modified grid
    }
};
