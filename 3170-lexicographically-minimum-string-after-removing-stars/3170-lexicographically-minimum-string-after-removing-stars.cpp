class Solution {
public:
    string clearStars(string s) {
        string ans = "";
        int n = s.size();
        vector<set<int>> v(26);
        set<int> st;
        for(int i=0; i<n; i++)
        {
            // cout<<"dncdskl"<<endl;
            if(s[i] != '*')
            {
                v[s[i]-97].insert(i);
                // cout<<"snlka"<<endl;
            }
            else
            {
                st.insert(i);
                for(int i=0; i<26; i++)
                {
                    if(!v[i].empty())
                    {
                        st.insert(*prev(v[i].end()));
                        v[i].erase(prev(v[i].end()));
                        break;
                    }
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            if(st.find(i) == st.end())
            {
                ans += s[i];
            }
        }
        
        return ans;
    }
};