class Solution {
public:
    int n;
    vector<int> g[100100];
    int dis[100100];
    int ans = 1;
    string s;
    void dfs(int node)
    {
        dis[node] = 1;
        for(auto v : g[node])
        {
            dfs(v);
            if(s[node] != s[v])
            {
                ans = max(ans, dis[v]+dis[node]);
                dis[node] = max(dis[node], dis[v]+1);
            }
        }
    }
    int longestPath(vector<int>& parent, string str) {
        s = str;
        n = parent.size();
        for(int i=1; i<n; i++)
        {
            g[parent[i]].push_back(i);
        }
        dfs(0);
        return ans;
    }
};