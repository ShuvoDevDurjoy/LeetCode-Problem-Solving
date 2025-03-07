class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        // Edge case where the range doesn't contain any valid numbers
        if (right < 2) return {-1, -1};
        
        // Adjust the left bound since primes start from 2
        left = max(left, 2);
        
        // Step 1: Use the sieve of Eratosthenes to find all primes <= sqrt(right)
        int limit = sqrt(right);
        vector<bool> isPrime(limit + 1, true);
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

        // Mark non-primes up to sqrt(right)
        for (int i = 2; i <= limit; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Step 2: Use the primes found to mark non-primes in range [left, right]
        int size = right - left + 1;
        vector<bool> isPrimeRange(size, true);
        
        // Mark multiples of primes in the range [left, right]
        for (int i = 2; i <= limit; ++i) {
            if (isPrime[i]) {
                int start = max(i * i, (left + i - 1) / i * i);
                for (int j = start; j <= right; j += i) {
                    isPrimeRange[j - left] = false;
                }
            }
        }

        // Step 3: Traverse the range [left, right] to find the closest prime pair
        int prevPrime = -1, minLeft = -1, minRight = -1, minimum = INT_MAX;
        
        for (int i = 0; i < size; ++i) {
            if (isPrimeRange[i]) {
                int currPrime = left + i;
                if (prevPrime != -1) {
                    if (currPrime - prevPrime < minimum) {
                        minLeft = prevPrime;
                        minRight = currPrime;
                        minimum = currPrime - prevPrime;
                    }
                }
                prevPrime = currPrime;
            }
        }

        return {minLeft, minRight};
    }
};
