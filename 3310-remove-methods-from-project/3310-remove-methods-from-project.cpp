class Solution {
public:
    vector<int> g[100100];
    int in[100100];
    int out[100100];
    set<int> st;
    bool vis[100100];
    void dfs(int i)
    {
        vis[i] = true;
        st.insert(i);
        for(auto it : g[i])
        {
            if(!vis[it])
            {
                dfs(it);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        for(int i=0; i<invocations.size(); i++)
        {
            g[invocations[i][0]].push_back(invocations[i][1]);
            in[invocations[i][1]]++;
            out[invocations[i][0]]++;
        }
        memset(vis, false, 100100);
        dfs(k);
        bool cant = false;
        for(int i=0; i<n; i++)
        {
            if(st.find(i)==st.end())
            {
                vector<int> temp = g[i];
                for(int j=0; j<temp.size(); j++)
                {
                    if(!st.empty() && st.find(temp[j])!=st.end())
                    {
                        cant = true;
                        break;
                        // st.erase(st.find(temp[j]));
                    }
                }
                if(cant)
                {
                    break;
                }
            }
        }
        vector<int> ans;
        if(cant)
        {
            cout<<"here"<<endl;
            for(int i=0; i<n; i++)
            {
                ans.push_back(i);
            }
            return ans;
        }
        for(int i=0; i<n; i++)
        {
            if(st.find(i)==st.end())
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};