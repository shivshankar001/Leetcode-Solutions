class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        vector<int> ans;
        int curr_sum = 0;
        for(int i=0; i<n; i++)
        {
            ans.push_back(nums[i]);
            sum -= nums[i];
            curr_sum += nums[i];
            if(curr_sum > sum){
                break;
            }
        }
        
        return ans;
    }
};