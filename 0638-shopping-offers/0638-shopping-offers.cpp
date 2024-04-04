class Solution {
public:
    bool canApplyOffer(vector<int>& offer, vector<int> need)
    {
        for(int i=0; i<need.size(); i++)
        {
            if(need[i] >= offer[i])
            {
                continue;
            }
            return 0;
        }

        return 1;
    }

    int MinPrice(vector<int> needs, vector<int>& price, vector<vector<int>>& special, map<vector<int>, int>& dp)
    {
        if(dp.find(needs) != dp.end())
        {
            return dp[needs];
        }

        int ans = 0;
        
        //without-any-offer
        for(int i = 0; i < needs.size(); i++)
        {
            ans += needs[i] * price[i];
        }

        //checking offers
        for(auto x : special)
        {
            if(!canApplyOffer(x, needs))
            {
                continue;
            }
            
            int cost = x[x.size() - 1];

            for(int i = 0; i < needs.size(); i++)
            {
                needs[i] -= x[i];
            }

            ans = min(ans, cost + MinPrice(needs, price, special, dp));

            for(int i = 0; i < needs.size(); i++)
            {
                needs[i] += x[i];
            }
        }

        return dp[needs] = ans;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) 
    {
        map<vector<int>, int> dp;
        return MinPrice(needs, price, special, dp);
    }
};