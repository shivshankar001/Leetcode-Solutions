class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        
        // vector<pair<int, int>> v; 
        // for(int i=0; i<n; i++)
        // {
        //     v.push_back({difficulty[i], profit[i]});
        // }
        // sort(v.begin(), v.end());
        // sort(difficulty.begin(), difficulty.end());
        
        int ans = 0;
        for(int i=0; i<m; i++)
        {
            int maxi = 0;
            for(int j=0; j<n; j++)
            {
                if(worker[i]>=difficulty[j])
                {
                    maxi = max(maxi, profit[j]);
                }
                // else
                // {
                //     break;
                // }
            }
            ans += maxi;
        }
        
        return ans;
    }
};