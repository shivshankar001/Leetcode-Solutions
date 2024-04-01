class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++)
        {
            v.push_back({values[i], labels[i]});
        }
        
        sort(v.begin(), v.end());
        
        int sum = 0, ans = 0;
        unordered_map<int, int> mp, mp1;
        for(int i=n-1; i>=0; i--)
        {
            if(mp.find(v[i].second) == mp.end())
            {
                sum += v[i].first;
                ans = max(ans, sum);
                mp[v[i].second]++;
                mp1[v[i].second] = useLimit - 1;
                numWanted--;
            }
            else if(mp[v[i].second] > 0 && mp1[v[i].second] > 0)
            {
                sum += v[i].first;
                ans = max(ans, sum);
                mp1[v[i].second] -= 1;
                numWanted--;
            }

            if(numWanted<=0)
            {
                break;
            }
        }
        
        return ans;
    }
};