class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int rmin=n, rmax=0, cmin=m, cmax=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1)
                {
                    rmin = min(rmin, i);
                    rmax = max(rmax, i);
                    cmin = min(cmin, j);
                    cmax = max(cmax, j);
                }
            }
        }
        cout<<rmin<<"  "<<rmax<<endl;
        cout<<cmin<<"  "<<cmax<<endl;
        int ans = (rmax-rmin+1)*(cmax-cmin+1);
        
        return ans;
    }
};