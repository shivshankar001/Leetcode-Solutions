class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n);
        stack<int> s;
        for(int i=n-1; i>=0; i--)
        {
            s.push(a[i]);
        }
        for(int i=n-1; i>=0; i--)
        {
            while(!s.empty() && s.top()<=a[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = s.top();
            }
            s.push(a[i]);
        }
        return ans;
    }
};