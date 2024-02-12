/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int n = employees.size();
        // vector<int> temp;
        // temp = employees.subordinates;
        map<int, int> mp;
        // int k = 0;
        vector<int> adj_list[n];
        for(int i=0; i<n; i++)
        {
            int u = employees[i]->id;
            mp[u] = i;
        }
        for(int i=0; i<n; i++)
        {
            int u = employees[i]->id;
            // mp[u] = k;
            // ump[k] = u;
            // k++;
            for(int j=0; j<employees[i]->subordinates.size(); j++)
            {
                int v = employees[i]->subordinates[j];
                adj_list[mp[u]].push_back(mp[v]);
            }
            // k++;
        }
        
        for(int i = 1; i <= 3; i++)
        {
            for(int x: adj_list[mp[i]]) cout << x << ' ';
            cout << '\n';
        }
        
        int ans = 0;
        // vector<bool> vis(n+1, false);
        // vis[id] = true;
        ans += employees[mp[id]]->importance;
        queue<int> q;
        q.push(mp[id]);
        
        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            // cout<<"Top : "<<top<<endl;
            for(int it : adj_list[top])
            {
                // if(!vis[it])
                // {
                    // cout<<"it : "<<it<<endl;
                    ans += employees[it]->importance;
                    q.push(it);
                    // cout<<"empl(it)->imp : "<<employees[it - 1]->importance<<endl;
                    // vis[it] = true;
                // }
            }
        }
        return ans;
    }
};