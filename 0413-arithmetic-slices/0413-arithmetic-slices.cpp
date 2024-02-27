class Solution {
public:
    int rec(int i, vector<int>& nums)
    {
        if(i<2)
        {
            return 0;
        }
        
        int ans = 0;
        if(nums[i]+nums[i-2] == 2*nums[i-1])
        {
            ans = max(ans, 1+rec(i-1, nums));
        }
        else
        {
            
            //ans = max(ans, rec(i-1, nums));
        }
        
        return ans;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        for(int i=2; i<nums.size(); i++)
        {
            ans += rec(i, nums);
        }
        return ans;
    }
};