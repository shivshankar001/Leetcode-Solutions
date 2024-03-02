class Solution {
public:
    int n;
    int rec(int i, vector<int> &s, vector<int>& stoneValue, vector<int> &dp)
    {
        //base case
        if(i>=n)
        {
            return 0;
        }
        //cache check
        if(dp[i] != -1)
        {
            return dp[i];
        }
        //compute
        int sum = 0, ans = INT_MIN;
        for(int j=i; j<n && j<i+3; j++)
        {
            sum += stoneValue[j];
            int temp;
            if(j+1>=n)
                temp = 0;
            else
                temp = s[j+1];
            ans = max(ans, sum + (temp-rec(j+1, s, stoneValue, dp)));
        }
        //save and return
        return dp[i]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        vector<int> s(n);
        s[n-1] = stoneValue[n-1];
        for(int i=n-2; i>=0; i--)
        {
            s[i] = s[i+1] + stoneValue[i];
        }
        
        vector<int> dp(n, -1);
        int ans = rec(0, s, stoneValue, dp);
        
        if(ans > s[0] - ans)
        {
            return "Alice";   
        }
        else if(ans < s[0] - ans)
        {
            return "Bob";
        }
        else
        {
            return "Tie";
        }
    }
};