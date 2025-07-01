class Solution {
public:
    int possibleStringCount(string word) {
        int result = 0;
        int prev = word[0];
        int size = word.size();
        int groupsize = 1;
        for(int i = 0; i < size; ++i){
            if(word[i]==prev){
                groupsize++;
            }
            else{
                result += groupsize - 1;
                groupsize = 1;
            }
            prev = word[i];
        }

        result += groupsize - 1;
        return result;

        return 5;
    }
};
