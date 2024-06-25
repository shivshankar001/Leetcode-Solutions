class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        for(int i=0; i<s.size(); i++)
        {
            mp[s[i]]++;
        }
        int cnt = 0;
        bool odd = false;
        for(auto it : mp)
        {
            cnt += (it.second/2);
            if(it.second%2!=0)
            {
                odd = true;
            }
        }
        int ans = cnt*2;
        if(odd)ans++;
        
        return ans;
    }
};