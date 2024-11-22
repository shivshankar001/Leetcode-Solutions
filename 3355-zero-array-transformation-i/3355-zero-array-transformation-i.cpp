class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        map<int, int> mp;
        for(auto it : queries)
        {
            mp[it[0]]++;
            mp[it[1]+1]--;
        }
        int op = 0;
        int maxi = *max_element(nums.begin(), nums.begin());
        for(int i=0; i<n; i++)
        {
            op += mp[i];
            if(op<nums[i])
            {
                return false;
            }
        }
        return true;
    }
};