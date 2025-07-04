class Solution {
public:
    pair<int, long long> lowerPower(long long n){
        if(n<=0){
            return {-1, 0};
        }
        int exponent = 0;
        long long power = 1;
        while((power<<1) < n){
            power <<= 1;
            exponent++;
        }

        return {exponent, power};
    }

    int solve(vector<int> &operation, long long index){
        if(index <= 1){ return 0;}
        pair<int, long long> lp = lowerPower(index);
        long long i = index - lp.second;
        return (operation[lp.first]) + solve(operation, i);
    }
    char kthCharacter(long long k, vector<int>& operations) {
        int count = solve(operations, k);
        // cout<<"Count is : "<<count<<endl;
        return ('a' + (count % 26));
    }
};
