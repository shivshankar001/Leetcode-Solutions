class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int temp = i;
            int cnt1 = 0;
            while(temp+1 < n && arr[temp] < arr[temp+1])
            {
                cnt1++;
                temp++;
            }
            int cnt2 = 0;
            while(temp+1 < n && arr[temp] > arr[temp+1])
            {
                cnt2++;
                temp++;
            }
            
            if(cnt1>=1 && cnt2>=1)
            {
                ans = max(ans, cnt1+cnt2+1);
            }
            if(cnt2>=1 && cnt1>=1)
            {
                ans = max(ans, cnt1+cnt2+1);
            }
        }
        // cout<<ans<<endl;
        return ans;
    }
};