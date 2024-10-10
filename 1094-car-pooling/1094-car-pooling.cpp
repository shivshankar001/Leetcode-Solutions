class Solution {
public:
    bool carPooling(vector<vector<int>>& a, int c) {
        int n = a.size();
        vector<int> pre(1010, 0);
        for(int i=0; i<n; i++)
        {
            int w = a[i][0];
            int u = a[i][1];
            int v = a[i][2];
            pre[u] += w;
            pre[v] -= w;
        }
        for(int i=1; i<1010; i++)
        {
            pre[i] += pre[i-1];
        }
        for(int i=0; i<1010; i++)
        {
            if(pre[i]>c)
            {
                return false;
            }
        }
        return true;
    }
};