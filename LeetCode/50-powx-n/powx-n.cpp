class Solution {
public:
    double multiply(double x, int n){
        if(n == 0)
            return 1;
        else if(n%2 == 0){
            double res = multiply(x, n/2);
            return res*res;// if n is even
        }
        else {
            double res = multiply(x,n/2);
            return x*res*res; // if n is odd
        }
    }

    double myPow(double x, int n) {
        if(x == 0)
            return 0;
        double ans = multiply(x,n);
        if(n < 0)
            return 1/ans; // if n is negative
        
        return ans;
        
    }
};