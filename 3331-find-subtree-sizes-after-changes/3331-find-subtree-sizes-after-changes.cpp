class Solution {
public:
    int n;
    vector<int> g[100100];
    vector<int> ng[100100];
    int fpar[100100];
    int fr[26];
    void dfs(int i, int par, string &s)
    {
        if(fr[s[i]-'a'] == -1)
        {
            fpar[i] = par;
        }
        else
        {
            fpar[i] = fr[s[i]-'a'];
        }
        int temp = fr[s[i]-'a'];
        fr[s[i]-'a'] = i;
        for(auto it : g[i])
        {
            if(par != it)
            {
                dfs(it, i, s);
            }
        }
        fr[s[i]-'a'] = temp;
    }
    void dfs2(int i, vector<int> &ans)
    {
        ans[i] = 1;
        for(auto it : ng[i])
        {
            dfs2(it, ans);
            ans[i] += ans[it];
        }
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        n = s.size();
        for(int i=1; i<n; i++)
        {
            g[parent[i]].push_back(i);
        }
        memset(fr, -1, sizeof(fr));
        dfs(0, -1, s);
        for(int i=1; i<n; i++)
        {
            ng[fpar[i]].push_back(i);
        }
        vector<int> ans(n);
        dfs2(0, ans);
        return ans;
    }
};