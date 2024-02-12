class Solution {
public:
    void dfs(int i, int src, int finish, vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int> temp)
    {
        if(i == finish)
        {
            ans.push_back(temp);
            // return;
        }
        
        for(auto it : graph[i])
        {
            temp.push_back(it);
            dfs(it, src, finish, graph, ans, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(0);
        dfs(0, 0, n-1, graph, ans, temp);
        return ans;
    }
};