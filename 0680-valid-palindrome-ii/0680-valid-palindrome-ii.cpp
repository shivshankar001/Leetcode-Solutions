class Solution {
public:
    bool validPalindrome(string s) {
        unordered_map<char, int> mp;
        for(int i=0; i<s.size(); i++)
        {
            mp[s[i]]++;
        }
        
        int cnt = 0;
        for(auto it : mp)
        {
            if(it.second==1)cnt++;
        }
        
        if(cnt>2)return false;
        
        int cnt1 = 0, cnt2 = 0;
        int i = 0, j = s.size()-1;
        while(i<j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                cnt1++;
                j--;
            }
            if(cnt1>=2)break;
        }
        
        reverse(s.begin(), s.end());
        
        i = 0, j = s.size()-1;
        while(i<j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                cnt2++;
                j--;
            }
            if(cnt2>=2)break;
        }
        
        if(cnt1<2|| cnt2<2)return true;
        
        return false;
    }
};