class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int, int> mp;
        set<int> s;
        for(int i=0; i<n; i++)
        {
            mp[answers[i]]++;
            s.insert(answers[i]);
        }
        // cout<<s.size();
        int ans = 0;
        for(auto it : s)
        {
            if(it == 0)
            {
                ans += mp[0];
            }
            else
            {
                if(mp[it]%(it+1) == 0)
                {
                    ans += (mp[it]/(it+1))*(it+1);
                }
                else
                {
                    int temp = (mp[it]/(it+1))+1;
                    ans += (temp*(it+1));
                }
            }
        }
        
        return ans;
    }
};