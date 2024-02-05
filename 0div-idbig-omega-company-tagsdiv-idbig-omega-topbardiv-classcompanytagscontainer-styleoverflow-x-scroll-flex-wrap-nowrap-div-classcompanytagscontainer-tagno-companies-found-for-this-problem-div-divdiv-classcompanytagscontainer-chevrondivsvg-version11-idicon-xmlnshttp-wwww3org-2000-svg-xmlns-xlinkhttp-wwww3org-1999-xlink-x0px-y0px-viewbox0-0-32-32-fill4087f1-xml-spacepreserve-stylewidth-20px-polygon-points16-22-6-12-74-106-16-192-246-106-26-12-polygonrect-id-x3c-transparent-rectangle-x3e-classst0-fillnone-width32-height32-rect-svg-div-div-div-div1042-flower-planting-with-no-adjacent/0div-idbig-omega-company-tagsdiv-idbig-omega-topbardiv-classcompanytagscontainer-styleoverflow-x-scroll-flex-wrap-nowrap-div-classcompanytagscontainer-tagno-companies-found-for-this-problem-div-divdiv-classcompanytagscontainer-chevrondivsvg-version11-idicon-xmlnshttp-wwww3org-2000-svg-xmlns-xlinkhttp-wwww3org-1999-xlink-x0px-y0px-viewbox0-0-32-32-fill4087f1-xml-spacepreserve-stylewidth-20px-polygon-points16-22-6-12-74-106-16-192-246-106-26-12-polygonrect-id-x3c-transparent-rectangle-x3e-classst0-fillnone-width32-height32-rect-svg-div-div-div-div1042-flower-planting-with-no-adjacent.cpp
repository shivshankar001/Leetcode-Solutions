class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj_list[n+1];
        for(int i=0; i<paths.size(); i++)
        {
            int u = paths[i][0];
            int v = paths[i][1];

            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

        vector<int> vis(n+1, 0);
        vector<int> ans(n+1);

        for(int i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                ans[i] = 1;

                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    for(auto nbr : adj_list[node])
                    {
                        if(!vis[nbr])
                        {
                            vector<int> col(5, 0);

                            for(auto it : adj_list[nbr])
                            {
                                col[ans[it]] = 1;
                            }

                            for(int i=1; i<5; i++)
                            {
                                if(col[i] == 0)
                                {
                                    ans[nbr] = i;
                                    break;
                                }
                            }

                            vis[nbr] = 1;
                            q.push(nbr);
                        }
                    }
                }
            }
        }

        return vector<int>(ans.begin()+1, ans.end());
    }
};