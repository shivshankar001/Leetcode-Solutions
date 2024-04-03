class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n=arr.size(),idx=-1;
        
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>arr[i+1])
            {
                 idx=i;
                 break;
            }
        }
        
        if(idx == -1) 
        {
            return arr;
        }
        
        int temp = -1;
        for(int i=n-1; i>idx; i--)
        {
            if(arr[i]<arr[idx])
            {
                if(temp==-1)
                {
                    temp=i;
                }
                else if(arr[temp]<=arr[i]) temp=i;
              
            }
        }
        swap(arr[idx],arr[temp]);
        return arr;
    }
};