class Solution {
public:
    long long minEnd(int n, int x) {
        vector<long long> a;
        for(long long i=0; i<63; i++)
        {
            if((x&(1LL<<i))==0)
            {
                a.push_back(i);
            }
        }
        for(long long i=0; i<a.size(); i++)
        {
            cout<<a[i]<<"  ";
        }
        cout<<endl;
        long long num = x;
        long long req = n-1;
        for(long long i=0; i<63; i++)
        {
            if((req&(1LL<<i))!=0)
            {
                num += (1LL<<a[i]);
            }
        }
        
        return num;
    }
};