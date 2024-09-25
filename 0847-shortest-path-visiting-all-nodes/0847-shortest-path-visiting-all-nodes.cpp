class Solution {
public:
    int shortestPathLength(vector<vector<int>>& g) {
        int n = g.size();
        int all = (1<<n)-1;
        
        queue<pair<int, pair<int, int>>> q;
        set<pair<int, int>> vis;
        for(int i=0; i<n; i++)
        {
            int mask = (1<<i);
            q.push({i, {0, mask}});
            vis.insert({i, mask});
        }
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int node = it.first;
            int dis = it.second.first;
            int mask = it.second.second;
            for(auto ch : g[node])
            {
                int newmask = mask|(1<<ch);
                if(newmask==all)
                {
                    return dis+1;
                }
                else if(vis.count({ch, newmask}))
                {
                    continue;
                }
                else
                {
                    q.push({ch, {dis+1, newmask}});
                    vis.insert({ch, newmask});
                }
            }
        }
        return 0;
    }
};