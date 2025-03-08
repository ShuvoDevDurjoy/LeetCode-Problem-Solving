class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int whiteCount = 0;
        for(int i = 0 ;i < k ; ++i){
            if(blocks[i]=='W'){
                whiteCount++;
            }
        }

        int minimum = whiteCount;

        int size = blocks.size();
        for(int i = k; i < size; ++i){
            if(blocks[i]=='W'){
                whiteCount++;
            }
            if(blocks[i-k]=='W'){
                whiteCount--;
            }
            minimum = min(minimum, whiteCount);
            if(!minimum){
                return minimum;
            }
        }

        return minimum;
    }
};
