class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(g.size()==0 || s.size()==0) return 0 ; 
        sort(g.begin(),g.end()) ; 
        sort(s.begin(),s.end()) ; 
        int number = 0 ; 
        int gi = 0;
        int si = 0;
        for (auto child : g) {
            while (s[si] < child) {
                si++;
                if (si >= s.size())
                    return number;
            }
            si++;
            number++;
            if (si >= s.size())
                return number;
        }
        return number ; 
    }
};
