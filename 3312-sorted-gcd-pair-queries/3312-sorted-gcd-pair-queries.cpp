#define ll long long
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        map<int, int> mp;
        for(auto it : nums)
        {
            mp[it]++;
        }
        int maxi = *max_element(nums.begin(), nums.end());
        vector<long long> gcd(maxi+1);
        for(int i=maxi; i>0; i--)
        {
            int cnt = 0;
            for(int j=i; j<maxi+1; j+=i)
            {
                cnt += mp[j];
            }
            gcd[i] = 1ll*cnt*(cnt-1)/2;
            for(int j=2*i; j<maxi+1; j+=i)
            {
                gcd[i] -= gcd[j];
            }
        }
        vector<long long> pre(maxi+1, 0);
        for(int i=1; i<maxi+1; i++)
        {
            pre[i] = pre[i-1]+gcd[i];
        }
        vector<int> ans;
        for(auto &it : queries)
        {
            ans.push_back(lower_bound(pre.begin(), pre.end(), it+1)-pre.begin());
        }
        return ans;
    }
};