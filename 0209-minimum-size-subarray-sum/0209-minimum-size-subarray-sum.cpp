class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i =0;
        int j = 0;
        int sum = 0;
        int ans = 1e9;
        while(i<n)
        {
            sum += nums[i];
            cout<<sum<<endl;
            while(sum>=target && j<n)
            {
                ans = min(ans, i-j+1);
                sum -= nums[j];
                j++;
            }
            i++;
        }
        if(ans>=1e9)
        {
            return 0;
        }
        return ans;
    }
};