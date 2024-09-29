class Solution {
public:
    unordered_map<int, vector<int>> m;
    unordered_map<int, int> inboundCount;
    vector<vector<int>> ans;

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        for (auto& v : pairs) {
            int start = v[0], end = v[1];
            m[start].push_back(end);
            ++inboundCount[end];
        }

        int startNode = m.begin()->first;
        for (auto& [f, s] : m)
            if (s.size() > inboundCount[f]) startNode = f;

        dfs(startNode);
        reverse(ans.begin(), ans.end());

        return ans;
    }

    void dfs(int node) {
        auto& edges = m[node];
        while (!edges.empty()) {
            int next = edges.back();
            edges.pop_back();
            dfs(next);
            ans.push_back({node, next});
        }
    }
};