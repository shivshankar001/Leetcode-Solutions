class Solution {
public:
    int maximumSwap(int num) {
        int ans = num;
        string temp = to_string(num);
        for(int i=0; i<temp.size()-1; i++)
        {
            for(int j=i+1; j<temp.size(); j++)
            {
                swap(temp[i], temp[j]);
                int t = stoi(temp);
                ans = max(ans, t);
                swap(temp[i], temp[j]);
            }
        }
        
        return ans;
    }
};