class Solution {
public:
    void rec(vector<int>& candidates, int target, vector<int> temp, set<vector<int>> &ans)
    {
        if(target == 0)
        {
            sort(temp.begin(), temp.end());
            ans.insert(temp);
            return;
        }
        if(target < 0)
        {
            return;   
        }
        
        for(int i=0; i<candidates.size(); i++)
        {
            temp.push_back(candidates[i]);
            rec(candidates, target-candidates[i], temp, ans);
            temp.pop_back();
        }
        
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        set<vector<int>> ans;
        rec(candidates, target, temp, ans);
        vector<vector<int>> ans1;
        for(auto it : ans)
        {
            vector<int> temp1;
            for(auto it1 : it)
            {
                temp1.push_back(it1);
            }
            ans1.push_back(temp1);
        }
        return ans1;
    }
};