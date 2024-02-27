class Solution {
public:
    int rec(int i, int j, string word1, string word2, vector<vector<int>> &dp)
    {
        if(i>=word1.size() || j>=word2.size())
        {
            return 0;
        }
        
        if(dp[i][j] != -1)
        {
           return dp[i][j]; 
        }
        
        int ans = 0;
        ans = max(ans, rec(i+1, j, word1, word2, dp));
        ans = max(ans, rec(i, j+1, word1, word2, dp));
        if(word1[i] == word2[j])
        {
            ans = max(ans, 1+rec(i+1, j+1, word1, word2, dp));
        }
        
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
        int temp = rec(0, 0, word1, word2, dp);
        int ans = word1.size()+word2.size()-2*temp;
        // ans += word2.size()-temp;
        
        return ans;
    }
};