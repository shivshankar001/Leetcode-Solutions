class Solution {
private:
    unordered_map<long long int, long long int> mp;
    long long int ans;

    void panda(int i, vector<bool>& vis, unordered_map<int, vector<pair<int, char>>>& ajl, long long int mask) {
        vis[i] = true;
        ans += mp[mask];
        for (int j = 0; j < 26; ++j) {
            long long int newmask = mask ^ (1LL << j);
            ans += mp[newmask];
        }
        mp[mask]++;

        for (const auto& [j, c] : ajl[i]) {
            if (!vis[j]) {
                panda(j, vis, ajl, mask ^ (1LL << (c - 'a')));
            }
        }
    }

public:
    long long int countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();
        unordered_map<int, vector<pair<int, char>>> ajl;
        for (int i = 1; i < n; ++i) {
            int u = i, v = parent[i];
            ajl[u].push_back({v, s[i]});
            ajl[v].push_back({u, s[i]});
        }

        vector<bool> vis(n + 1, false);
        ans = 0;

        panda(0, vis, ajl, 0);

        return ans;
    }
};