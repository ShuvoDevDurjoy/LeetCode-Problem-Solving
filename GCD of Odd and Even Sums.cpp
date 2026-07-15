class Solution {
private: 
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(min(a, b), (max(a, b) % min(a, b)));
    }   
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0, sumEven = 0;
        int even = 2, odd = 1;
        while(n){
            sumOdd += odd;
            sumEven += even;
            even += 2;
            odd += 2;
            n--;
        }

        return gcd(sumOdd, sumEven);
    }
};
