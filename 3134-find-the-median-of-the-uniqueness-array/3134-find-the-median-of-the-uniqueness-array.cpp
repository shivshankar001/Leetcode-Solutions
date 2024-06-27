class Solution {
public:
    long long check(int mid, vector<int>& nums)
    {
        unordered_map<int, int> mp;
        long long i = 0, j = 0;
        long long cnt = 0;
        while(j<nums.size())
        {
            mp[nums[j]]++;
            while(mp.size()>mid)
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                {
                    mp.erase(nums[i]);
                }
                i++;
            }
            cnt += (j-i+1);
            j++;
        }
        
        return cnt;
    }
    int medianOfUniquenessArray(vector<int>& nums) {
        long long n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        
        int l = 1;
        int r = mp.size();
        int ans;
        long long total = (n*(n+1))/2;
        long long median = (total+1)/2;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(check(mid, nums)>=median)
            {
                ans = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        
        return ans;
    }
};