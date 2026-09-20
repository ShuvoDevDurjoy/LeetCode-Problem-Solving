class Solution {
public:
    int reverseDegree(string s) {
        int reverse_degree = 0;
        int n = s.size();
        for(int i = 0; i < n; ++i){
            reverse_degree += (123 - s[i]) * (i + 1);
        }

        return reverse_degree;
    }
};
