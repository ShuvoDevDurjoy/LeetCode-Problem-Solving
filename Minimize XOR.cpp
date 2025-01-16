class Solution {
public:
    int minimizeXor(int num1, int num2) {
        bitset<32> bits(num2) ; 
        int set_bit_count = __builtin_popcount(num2) ; 
        bitset<32> num1_bits(num1) ; 
        int set_bit_count2 = __builtin_popcount(num1);
        set_bit_count -= set_bit_count2 ; 
        int count = 0 ;
        bool negative = false;
        if(set_bit_count<0){
            set_bit_count *= -1;
            negative = true;
        }
        //111011100110101100101000000000
        long int result = num1 ;
        while(set_bit_count>0){
            if(!negative && num1_bits[count]==0){
                result |= ((1L)<<count);
                --set_bit_count ;
            }
            else if(negative && num1_bits[count]==1){
                result ^= (1<<count) ; 
                --set_bit_count ;
            }
            count++; 
        }

        return result; ;  
    }
};
