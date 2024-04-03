class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k)
        {
            return false;
        }
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        for(int i = 0; i < n; i++)
        {   
            if(mp[nums[i]] == 0)   
            {
                continue;
            }   
            mp[nums[i]]--;
            for(int j = 1; j < k; j++)
            {
                if(mp[nums[i] + j] == 0)
                {
                    return false;
                }
                mp[nums[i] + j]--;
            }
        }
        
        return true;
    }
};