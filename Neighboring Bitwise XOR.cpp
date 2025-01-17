class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xor_derived = 0 ;
        for(auto &x : derived){
            xor_derived ^= x ; 
        }
        return xor_derived?false:true;
    }
};
