class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        // for(int i=0; i<n; i++)
        // {
        //     cout<<nums[i]<<" ";
        // }
        // cout<<endl;
        int ans = 0;
        int s = nums[0];
        for(int i=0; i<n; i++)
        {
            if(nums[i]<s)
            {
                ans += (s-nums[i]);
                s++;
            }
            else
            {
                s = nums[i] + 1;
            }
        }
        
        return ans;
    }
};