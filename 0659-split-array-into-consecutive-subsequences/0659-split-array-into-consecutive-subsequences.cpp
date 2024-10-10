using ii = pair<int, int>;
class Solution {
public:
    class comp{
        public:
        bool operator()(ii &a, ii &b)
        {
            if(a.first==b.first)
            {
                return a.second>b.second;
            }
            return a.first>b.first;
        }
    };
    bool isPossible(vector<int>& a) {
        int n = a.size();
        priority_queue<ii, vector<ii>, comp> pq;
        for(int i=0; i<n; i++)
        {
            if(pq.empty())
            {
                pq.push({a[i], 1});
            }
            else
            {
                if(pq.top().first == a[i])
                {
                    pq.push({a[i], 1});
                }
                else if(pq.top().first+1 == a[i])
                {
                    auto it = pq.top();
                    pq.pop();
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
            if(pq.top().second<3)
            {
                return false;
            }
            pq.pop();
        }
        return true;
    }
};