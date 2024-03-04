class Solution {
public:
    int rec(int ind, vector<vector<int>>& books, int shelfWidth, vector<int> &dp)
    {
        //base case
        if (ind == books.size())
        {
            return 0;
        }
        // cache check 
        if(dp[ind] != -1)
        {
            return dp[ind];
        }
        //compute
        int width = shelfWidth;
        int maxi_h = 0;
        int ans = 1e9;
        for (int i = ind; i < books.size(); i++)
        {
            int book_w = books[i][0];
            int book_h = books[i][1];
            if (book_w > width)
            {
                break;
            }
            maxi_h = max(maxi_h, book_h);
            width -= book_w;
            ans = min(ans, maxi_h + rec(i + 1, books, shelfWidth, dp));
        }
        
        //save and return
        return dp[ind] = ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int> dp(books.size(), -1);
        return rec(0, books, shelfWidth, dp);
    }
};