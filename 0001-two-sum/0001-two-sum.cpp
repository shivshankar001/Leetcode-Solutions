class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        vector<int> x;
        for(i=0;i<nums.size()-1;i++){
            for(j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                   x.push_back(i);
                   x.push_back(j);
                }
            }
        }
        return x;
    }
};