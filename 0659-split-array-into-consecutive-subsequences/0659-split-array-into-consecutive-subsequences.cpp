using ii = pair<int, int>;
class Solution {
public:
    class comparasion {
        public:
        bool operator()(pair<int, int>& a, pair<int, int>& b) {//always put the smallest and shortest sequence on the top of the heap
            if(a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        };
    };
    bool isPossible(vector<int>& a) {
        int n = a.size();
        priority_queue<ii, vector<ii>, comparasion> pq;
        for(int i=0; i<n; i++)
        {
            if(pq.empty())
            {
                pq.push({a[i], 1});
            }
            else
            {
                cout<<"i : "<<i<<endl;
                cout<<pq.top().first<<" "<<pq.top().second<<endl;
                if(pq.top().first == a[i])
                {
                    pq.push({a[i], 1});
                }
                else if(pq.top().first+1 == a[i])
                {
                    auto it = pq.top();
                    cout<<"here"<<endl;
                    // cout<<it.first<<" "<<it.second<<endl;
                    pq.pop();
                    cout<<"pushing : "<<a[i]<<" "<<it.second+1<<endl;
                    pq.push({a[i], it.second+1});
                }
                else
                {
                    if(pq.top().second < 3) 
                    {
                        return false;
                    }
                    pq.pop();
                    i--;
                }
            }
        }
        while(!pq.empty())
        {
            cout<<pq.top().second<<endl;
            if(pq.top().second<3)
            {
                return false;
            }
            pq.pop();
        }
        return true;
    }
};