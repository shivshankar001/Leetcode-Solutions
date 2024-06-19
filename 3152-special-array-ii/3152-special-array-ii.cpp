class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> v;
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i]%2 == nums[i+1]%2)
            {
                v.push_back(i);
            }
        }

        vector<bool> ans;
        for(int i=0; i<queries.size(); i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            cout<<l<<" "<<r<<endl;
            auto it = lower_bound(v.begin(), v.end(), l);
            if(it == v.end() || (*it) >= r)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        
        return ans;
    }
};