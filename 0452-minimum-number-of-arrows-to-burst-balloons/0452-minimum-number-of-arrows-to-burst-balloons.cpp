class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=1)
        {
            return 1;
        }
        int ans = 1;
        vector<pair<int, int>> v;
        for(int i=0; i<n; i++)
        {
            v.push_back({points[i][0], points[i][1]});
        }
        sort(v.begin(), v.end());
        
        int mini = v[0].first, maxi = v[1].second;
        for(int i=0; i<n; i++)
        {
            if(v[i].first>=mini && v[i].first<=maxi)
            {
                mini = max(v[i].first, mini);
                maxi = min(v[i].second, maxi);
            }
            else
            {
                ans++;
                mini = v[i].first;
                maxi = v[i].second;
            }
        }
        
        return ans;
    }
};