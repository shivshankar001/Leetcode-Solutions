class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int cnt0 = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i] == 0)
            {
                cnt0++;
            }
            mp[arr[i]]++;
        }
        
        if(cnt0%2 != 0)
        {
            return false;
        }
        
        int cnt = 0;
        for(int i=0; i<arr.size(); i++)
        {
            int temp = arr[i]*2;
            if(mp[arr[i]]-1 >= 0 && mp[temp]-1 >= 0)
            {
                mp[arr[i]]--;
                mp[temp]--;
                cnt++;
            }
        }
        if(cnt >= arr.size()/2)
            return true;
        return false;
    }
};