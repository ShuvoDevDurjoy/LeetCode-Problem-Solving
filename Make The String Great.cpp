class Solution {
public:
    string makeGood(string s) {
        if(s.length()<=1) return s ; 
        string str = "" ; 
        for(int i = 0 ; i < s.length() ; ++i){
            if(i+1<s.length() && abs(s[i]-s[i+1])==32) 
            {
                s = str + (i+2<s.length()?s.substr(i+2 , s.length()) : "" ); 
                str = "" ; 
                i = -1 ; 
            }
            else 
            {
                str+=s[i] ; 
            }
            cout<<str<<endl;

        }
        return str; 
    }
};
