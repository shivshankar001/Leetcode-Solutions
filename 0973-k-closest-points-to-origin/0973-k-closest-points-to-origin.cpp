using ii = pair<int, int>;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& a, int k) {
        int n = a.size();
        vector<vector<int>> ans;
        priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;
        for(int i=0; i<n; i++)
        {
            int dist = abs(a[i][0])*abs(a[i][0]) + abs(a[i][1])*abs(a[i][1]);
            pq.push({dist, {a[i][0], a[i][1]}});
        }
        while(!pq.empty() && k--)
        {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};