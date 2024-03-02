class Solution {
public:
    int fact(int n) {  //Calculates factorial
        if(n<=1) return 1;
        else return n*fact(n-1);
    }
    int rec(int n, vector<int> &dp) {
        if(n==0)
        {
            return 1;
        }
        else 
        {
            if(dp[n] != -1)
            {
                return dp[n];
            }
            return dp[n] = (rec(n-1, dp) + (9* (fact(9)/fact(10-n))));
        }
    }
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n+1, -1);
        return rec(n, dp);
    }
};