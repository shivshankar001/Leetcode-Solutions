const int mod = 1e9+7;
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int n = s.size();
        vector<int> mp(27, 0);
        for(int i=0; i<n; i++)
        {
            mp[s[i]-'a'+1]++;
        }
        cout<<mp.size()<<endl;
        for(int i=0; i<t; i++)
        {
            vector<int> mp2(27, 0);
            for(int j=1; j<=26; j++)
            {
                if(mp[j]>0)
                {
                    if(j==26)
                    {
                        mp2[(j+1)%26] += (mp[j]%mod);
                        mp2[(j+2)%26] += (mp[j]%mod);
                        mp[j] = 0;
                    }
                    else
                    {
                        mp2[j+1] += (mp[j]%mod);
                        mp[j] = 0;
                    }
                }
            }
            // mp = mp2;
            for(int j=1; j<=26; j++)
            {
                mp[j] = 0;
                if(mp2[j]>0)
                {
                    mp[j] = mp2[j];
                }
            }
        }
        int ans = 0;
        for(int i=1; i<=26; i++)
        {
            ans = ((ans%mod) + (mp[i]%mod))%mod;
        }
        return ans;
    }
};