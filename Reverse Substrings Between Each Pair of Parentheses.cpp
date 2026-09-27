class Solution {
private: 
    int generate(string &s, int st){
        // cout<<st<<endl;
        int begin = st;
        st++;
        while(s[st]!=')'){
            if(s[st]=='('){
                st = generate(s, st); 
            }
            st++;
        }
        reverse(s.begin() + begin + 1, s.begin() + st);
        // cout<<s<<endl;
        return st;

    }
public:
    string reverseParentheses(string s) {
        int size = s.size();
        for(int i = 0; i < size; ++i){
            if(s[i]=='('){
                i = generate(s, i);
            }
        }
        stringstream str;
        for(int i = 0; i < size; ++i){
            if(s[i] != ')' && s[i] != '('){
                str << s[i];
            }
        }
        return str.str();
    }
};
