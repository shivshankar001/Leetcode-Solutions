class Solution {
public:
    long long cntp(int n)
    {
        return (n*(n-1))/2;
    }
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int j = 0;
        long long ans = 0;
        unordered_map<int, int> mp;
        long long cnt = 0;
        long long pairs = 0;
        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++;
            if(mp.find(nums[i])==mp.end())
            {
                pairs += cntp(mp[nums[i]]);
            }
            else
            {
                pairs += (cntp(mp[nums[i]])-cntp(mp[nums[i]]-1));
            }
            while(pairs>=k)
            {
                ans += (n-i);
                pairs -= cntp(mp[nums[j]]);
                mp[nums[j]]--;
                pairs += cntp(mp[nums[j]]);
                j++;
            }
        }
        return ans;
    }
};