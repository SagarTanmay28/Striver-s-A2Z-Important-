class Solution {
public:
    double modular_exponentiation(double x,long long n){
        double res = 1.0;

        while(n != 0){
            if(n % 2 == 1){
                res = (res * x);
            }

            x = (x * x);
            n = n / 2;
        }

        return res;
    }
    double myPow(double x, int n) {
        long long N = n;

        if(N < 0){
            x = 1.0 / x;
            N = (-1) * N;
        }

        return modular_exponentiation(x,N);
    }
};
