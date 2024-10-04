class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        int n1 = a.size();
        int n2 = b.size();
        vector<int> ans(n1);
        unordered_map<int, int> mp;
        for(int i=0; i<n1; i++)
        {
            for(int j=0; j<n2; j++)
            {
                if(a[i]==b[j])
                {
                    mp[a[i]] = j;
                    break;
                }
            }
        }
        for(int i=0; i<n1; i++)
        {
            int pos = mp[a[i]];
            int fd = -1;
            cout<<pos<<endl;
            for(int j=pos; j<n2; j++)
            {
                if(b[j]>a[i])
                {
                    fd = b[j];
                    break;
                }
            }
            ans[i] = fd;
        }
        return ans;
    }
};