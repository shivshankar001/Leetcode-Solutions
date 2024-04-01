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
        // for(int i=0; i<n; i++)
        // {
        //     v.push_back({values[i], labels[i]});
        // }
        int limit = useLimit;
        // int temp = -1;
        int sum = 0, ans = 0;
        unordered_map<int, int> mp, mp1;
        for(int i=n-1; i>=0; i--)
        {
            int temp = v[i].second;
            if(mp.find(temp) == mp.end())
            {
                sum += v[i].first;
                ans = max(ans, sum);
                mp[temp]++;
                mp1[temp] = useLimit - 1;
                numWanted--;
            }
            else if(mp[temp] > 0 && mp1[temp] > 0)
            {
                // cout<<"bol"<<endl;
                sum += v[i].first;
                ans = max(ans, sum);
                // temp = v[i].second;
                mp1[temp] -= 1;
                numWanted--;
            }
            // cout<<temp<<endl;
            // cout<<sum<<" "<<ans<<endl;
            if(numWanted<=0)
            {
                break;
            }
        }
        
        return ans;
    }
};