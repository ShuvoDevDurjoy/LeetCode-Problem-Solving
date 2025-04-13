class Solution {
public:
    long long mod_pow(long long int base, long long int exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) { 
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp = exp >> 1;
        }

        return result;
    }

    long long int countGoodNumbers(long long n) {
        long long int even = 1 + ((n-1) / 2);
        long long int odd = n / 2;
        long long mod = 1e9 + 7;
        even = mod_pow(5LL, even, mod);
        odd = mod_pow(4LL, odd, mod);

        return (even * odd) % mod;
    }
};
