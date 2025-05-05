class Solution {
public:
    int numTilings(int n) {
        if(n<=2) return n;
        if(n==3) return 5;
        vector<int> arr(n, 0);
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 5;
        int MOD = 1e9 + 7;
        for(int i = 3; i < n; ++i){
            arr[i] = ((((arr[i-1]*2)%MOD)+arr[i-3])%MOD);
        }

        return arr[n-1];
    }
};
