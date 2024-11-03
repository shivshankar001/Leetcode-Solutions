class Solution {
public:
    vector<int> g[2005];
    bool ans = true;
    int col[2005];
    void dfs(int i, int color = 1)
    {
        col[i] = color;
        for(auto it : g[i])
        {
            if(!col[it])
            {
                dfs(it, 3-color);
            }
            else
            {
                if(col[it]==color)
                {
                    ans = false;
                }
            }
        }
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for(int i=0; i<dislikes.size(); i++)
        {
            g[dislikes[i][0]-1].push_back(dislikes[i][1]-1);
            g[dislikes[i][1]-1].push_back(dislikes[i][0]-1);
        }
        memset(col, 0, sizeof(col));
        for(int i=0; i<n; i++)
        {
            if(!col[i])
            {
                dfs(i);
            }
        }
        return ans;
    }
};