class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> graph[n+1];
        for(int i=0; i<times.size(); i++)
        {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            graph[u].push_back({v, w});
        }
        
        if(graph[k].size() == 0)
        {
            return -1;
        }
        
        vector<int> vis(n+1, 0);
        vector<int> dis(n+1, INT_MAX);
        queue<pair<int, int>> q;
        q.push({k, 0});
        vis[k] = true;
        dis[k] = 0;
        
        while(!q.empty())
        {
            int top_node = q.front().first;
            int time = q.front().second;
            q.pop();
            
            for(auto it : graph[top_node])
            {
                int nbr = it.first;
                int dist = time + it.second;
                if(dis[nbr]>dist)
                {
                    q.push({nbr, dist});
                    dis[nbr] = dist;
                }
            }
        }
        
        int ans = INT_MIN;
        for(int i=1; i<dis.size(); i++)
        {
            if(dis[i] != INT_MAX)
            {
                ans = max(ans, dis[i]);
            }
            else
            {
                return -1;
            }
        }
        return ans;
    }
};