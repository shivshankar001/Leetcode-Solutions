class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        
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
            }
            ans += maxi;
        }
        
        return ans;
    }
};