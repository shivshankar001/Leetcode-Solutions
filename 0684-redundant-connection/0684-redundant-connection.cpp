class Solution {
public:
    vector<int> g[1010];
    int par[1010];
    int up(int u)
    {
        if(par[u]==u)
        {
            return u;
        }
        return par[u] = up(par[u]);
    }
    void dsu(int u, int v)
    {
        int pu = up(u);
        int pv = up(v);
        if(pv!=pu)
        {
            par[pv] = pu;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i=0; i<edges.size(); i++)
        {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0; i<1010; i++)
        {
            par[i] = i;
        }
        vector<pair<int, int>> temp;
        for(int i=0; i<edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int pu = up(u);
            int pv = up(v);
            if(pv!=pu)
            {
                dsu(u, v);
            }
            else
            {
                temp.push_back({u, v});
            }
        }
        vector<int> ans;
        auto it = *prev(temp.end());
        int a = it.first;
        int b = it.second;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};