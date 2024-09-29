class Solution {
public:
    int par[1010];
    
    // Find function with path compression
    int find(int u) {
        if (u == par[u]) {
            return u;
        }
        return par[u] = find(par[u]);
    }
    
    // Union function
    void unionSets(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) {
            par[pv] = pu;
        }
    }
    
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        // Initialize parent array for union-find
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
        
        vector<bool> ans(requests.size());
        
        for (int i = 0; i < requests.size(); i++) {
            int u = requests[i][0];
            int v = requests[i][1];
            
            int pu = find(u);
            int pv = find(v);
            
            // Temporarily unite u and v
            bool isValid = true;
            
            // Check all restrictions to see if this union violates any restriction
            for (auto& r : restrictions) {
                int u1 = r[0];
                int v1 = r[1];
                int pu1 = find(u1);
                int pv1 = find(v1);
                
                // If the restricted nodes end up in the same set, it's invalid
                if ((pu == pu1 && pv == pv1) || (pu == pv1 && pv == pu1)) {
                    isValid = false;
                    break;
                }
            }
            
            // If the request is valid, apply the union, otherwise skip it
            if (isValid) {
                unionSets(u, v);
            }
            
            ans[i] = isValid;
        }
        
        return ans;
    }
};
