class Solution {
public:
    int maxDepth(string s) {
        int maxdepth = 0;
        int counter = 0;
        int size = s.size();
        for(int i = 0; i < size; ++i){
            if(s[i]=='(') counter++;
            else if(s[i]==')') counter--;
            maxdepth = max(maxdepth, counter);
        }

        return maxdepth;
    }
};
