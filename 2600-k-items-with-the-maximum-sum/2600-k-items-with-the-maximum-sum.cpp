class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans = 0;
        int temp = numOnes + numZeros;
        if(temp >= k)
        {
            if(k <= numOnes)
            {
                ans = k;
                k = 0;
            }
            else
            {
                ans = numOnes;
                k = 0;
            }
        }
        else
        {
            ans = numOnes;
            int x = k - temp;
            if(x < numNegOnes)
            {
                ans -= x;
            }
            else
            {
                ans -= numNegOnes;
            }
        }
        
        return ans;
    }
};