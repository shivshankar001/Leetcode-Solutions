class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int odd = 0, even = 0, ans = 0;
        int mod = 1e9+7;
        for(int i=0; i<n; i++)
        {
            if(arr[i]%2==1)
            {
                swap(odd, even);
                odd++;
            }
            else
            {
                even++;    
            }
            ans = ((ans%mod)+(odd%mod))%mod;
        }
        return ans;
    }
};