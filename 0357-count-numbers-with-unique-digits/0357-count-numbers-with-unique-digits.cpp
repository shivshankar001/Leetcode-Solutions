class Solution {
public:
    int fact(int n) {  //Calculates factorial
        if(n<=1) return 1;
        else return n*fact(n-1);
    }
    int rec(int n) {
        if(n==0) return 1;
        else return (rec(n-1) + (9* (fact(9)/fact(10-n))));
    }
    int countNumbersWithUniqueDigits(int n) {
        return rec(n);
    }
};