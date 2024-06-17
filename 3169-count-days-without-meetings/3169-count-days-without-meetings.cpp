class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());
        set<vector<int>> s;
        s.insert(meetings[0]);
        for(int i=1; i<n; i++)
        {
            auto it = *prev(s.end());
            int first = it[0];
            int second = it[1];
            
            if(second < meetings[i][0])
            {
                s.insert(meetings[i]);
            }
            else
            {
                s.erase(prev(s.end()));
                vector<int> v(2);
                v[0] = min(first, meetings[i][0]);
                v[1] = max(second, meetings[i][1]);
                s.insert(v);
            }
        }
        
        int ans = 0;
        for(auto it : s)
        {
            int first = it[0];
            int second = it[1];
            cout<<first<<" "<<second<<endl;
            int temp = second-first+1;
            days -= temp;
        }
        
        return days;
    }
};