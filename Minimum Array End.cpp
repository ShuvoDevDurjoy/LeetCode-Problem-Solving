class Solution {
public:
    long long minEnd(int n, int x) {
        bitset<32> binaryn(n-1) ; 
        bitset<64> binaryx(x) ; 
        int nsize = 0 ; 
        for(int i = 0 ; i < 64 and nsize < 32 ; ++i){
            if(binaryx[i]==0){
                binaryx[i] = binaryn[nsize++] ; 
            }
        }
        return binaryx.to_ullong();
    }
};
