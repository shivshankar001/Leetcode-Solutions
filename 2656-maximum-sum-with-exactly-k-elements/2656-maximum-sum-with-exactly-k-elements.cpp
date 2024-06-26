class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(), nums.end());
        
        int ans = maxi;
        k--;
        while(k--)
        {
            maxi++;
            ans += maxi;
        }
        
        return ans;
    }
};