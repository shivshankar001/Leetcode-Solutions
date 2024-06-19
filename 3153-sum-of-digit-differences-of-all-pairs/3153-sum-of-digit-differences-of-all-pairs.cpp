class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        vector<string> v;
        for(int i=0; i<nums.size(); i++)
        {
            v.push_back(to_string(nums[i]));
        }
        
        int n = v[0].size();
        vector<vector<long long>> cnt(n);
        for(int i=0; i<n; i++)
        {
            unordered_map<char, long long> mp;
            for(int j=0; j<nums.size(); j++)
            {
                mp[v[j][i]]++;
            }
            for(auto it : mp)
            {
                cnt[i].push_back(it.second);
            }
        }
        
        vector<vector<long long>> pre(n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<cnt[i].size(); j++)
            {
                if(j==0)
                {
                    pre[i].push_back(cnt[i][j]);
                }
                else
                {
                    pre[i].push_back(pre[i][j-1] + cnt[i][j]);
                }
            }
        }
        
        long long ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<pre[i].size(); j++)
            {
                // cout<<pre[i][j]<<" ";
                long long x = pre[i].size();
                long long temp = pre[i][x-1]-pre[i][j];
                ans += (cnt[i][j]*temp);
            }
            // cout<<endl;
        }
        
        return ans;
    }
};