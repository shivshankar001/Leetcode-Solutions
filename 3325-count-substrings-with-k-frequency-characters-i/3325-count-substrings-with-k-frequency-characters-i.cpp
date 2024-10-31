class Solution {
public:
    int n;
    bool check(map<char, int> mp, int k)
    {
        for(auto it : mp)
        {
            if(it.second>=k)
            {
                return true;
            }
        }
        return false;
    }
    int numberOfSubstrings(string s, int k) {
        n = s.size();
        map<char, int> mp;
        int i=0, j=0;
        int ans = 0;
        while(i<n)
        {
            mp[s[i]]++;
            while(j<=i && check(mp, k))
            {
                ans += (n-i);
                mp[s[j]]--;
                j++;
            }
            i++;
        }
        return ans;
    }
};