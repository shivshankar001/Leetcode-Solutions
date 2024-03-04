class Solution {
public:
    int n;
    int rec(vector<int> &arr, int k, int ind, vector<int> &dp)
    {
        //base case     
        if(ind >= n)
        {
            return 0;
        }
        //cache check
        if(dp[ind] != -1)
        {
            return dp[ind];
        }
        //compute
        int mx = 0, ans = 0;
        for(int i=ind; i<min(ind+k, n); i++){
            mx = max(mx, arr[i]);
            ans = max(ans, (i - ind + 1)*mx + rec(arr, k, i+1, dp));
        }
        //save and return
        return dp[ind] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        vector<int> dp(n, -1);
        return rec(arr, k, 0, dp);
    }
};