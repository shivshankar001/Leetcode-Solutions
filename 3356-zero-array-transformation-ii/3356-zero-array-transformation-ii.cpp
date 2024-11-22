class Solution {
public:
    int n, m;
    bool check(int mid, vector<int>& nums, vector<vector<int>>& queries)
    {
        unordered_map<int, int> mp;
        for(int i=0; i<mid; i++)
        {
            mp[queries[i][0]] += queries[i][2];
            mp[queries[i][1]+1] -= queries[i][2];
        }
        int op = 0;
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
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        m = queries.size();
        int ans = 1e9;
        int l = 0, r = m;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(check(mid, nums, queries))
            {
                ans = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        if(ans>=1e9)
        {
            return -1;
        }
        return ans;
    }
};