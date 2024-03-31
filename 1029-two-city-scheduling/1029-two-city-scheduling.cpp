class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b)
  {
      return abs(a[0]-a[1])<abs(b[0]-b[1]);
  }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),comp);
        int n=costs.size();
        int a=n/2,b=n/2;
        int sum=0;
        for(int i=n-1;i>=0;i--)
        {
            if(costs[i][0]<=costs[i][1])
            {
                if(a>0)
                {
                    sum+=costs[i][0];
                    a--;
                }
                else
                   {
                       sum+=costs[i][1];
                       b--;
                   }
            }
            else
            {
                if(b>0)
                {
                      sum+=costs[i][1];
                       b--;
                }
                else
                {
                     sum+=costs[i][0];
                    a--;
                }
            }

        }
        return sum;
    }
};