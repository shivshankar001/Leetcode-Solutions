class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> pre(n+1, 0);
        for(int i=0; i<n; i++)
        {
            pre[i+1] = pre[i] + nums[i];
        }
        n++;
        for(int i=0; i<n; i++)
        {
            cout<<pre[i]<<" ";
        }
        cout<<endl;
        int temp = pre[n-1]-x;
        if(temp<0)
        {
            return -1;
        }
        // if(temp==0)
        // {
        //     return 0;
        // }
        // cout<<"temp : "<<temp<<endl;
        int ans = 1e9;
        for(int i=0; i<n; i++)
        {
            int pos = lower_bound(pre.begin(), pre.end(), pre[i]+temp)-pre.begin();
            if(pos<n && pre[pos]==pre[i]+temp)
            {
                int del = n-pos+i;
                // if(i==0)
                // {
                //     del--;
                // }
                ans = min(ans, del-1);
            }
        }
        if(ans>=1e9)
        {
            ans = -1;
        }
        return ans;
    }
};