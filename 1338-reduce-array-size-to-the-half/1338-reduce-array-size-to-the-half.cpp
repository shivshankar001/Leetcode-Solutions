class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int, int> mp;
        for(int i=0; i<arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        
        vector<int> v;
        for(auto it : mp)
        {
            v.push_back(it.second);
        }
        
        sort(v.begin(), v.end());
        
        n = (n/2);
        
        int ans = 0;
        for(int i=v.size()-1; i>=0; i--)
        {
            n -= v[i];
            ans++;
            if(n <= 0)
            {
                break;
            }
        }
        
        
        return ans;
    }
};