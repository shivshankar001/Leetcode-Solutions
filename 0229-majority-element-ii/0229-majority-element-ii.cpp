class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int temp = n/3;
        vector<int> ans;
        map<int, int> mp;
        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++;
        }
        for(auto it : mp)
        {
            if(it.second>temp)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};