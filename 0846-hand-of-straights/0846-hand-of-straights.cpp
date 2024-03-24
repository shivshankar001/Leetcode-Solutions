class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int g) {
        int n = hand.size();
        if(n%g != 0)
        {
            return false;
        }
        
        unordered_map<int, int> mp;
        set<int> s;
        for(int i=0; i<n; i++)
        {
            mp[hand[i]]++;
            s.insert(hand[i]);
        }
        
        for(auto it : s)
        {
            int temp = mp[it];
            if(temp>0)
            {
                for(int i=it; i<it+g; i++)
                {
                    if(mp[i]-temp >= 0)
                    {
                        mp[i] -= temp;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};