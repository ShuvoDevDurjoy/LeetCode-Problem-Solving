class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int low_count = 0;
        int dup_low = low;
        while(dup_low){
            ++low_count;
            dup_low = dup_low / 10;
        }

        int initial = 0;
        int add_factor = 0;
        for(int i = 1; i <= low_count; ++i){
            initial = initial * 10 + i;
            add_factor = add_factor * 10 + 1;
        }

        int mul_factor = low_count + 1;

        vector<int> result;

        while(initial <= high){
            if(initial >= low){
                result.push_back(initial);
            }
            if((initial % 10) == 9){
                initial = initial + (add_factor * mul_factor) + 1;
                add_factor = add_factor * 10 + 1;
                mul_factor += 1;
            }
            else{
                initial += add_factor;
            }
        }

        return result;

    }
};
