class Solution {
public:
    string reverseWords(string str) {
        str+=" " ; 
    string s = "" ; 
    vector<string> v ; 
    for(int i = 0 ; i < str.length() ; ++i){
        if(s!="" && str[i]==' '){
            v.push_back(s) ;
            s = "" ; 
        }
        else if(str[i]!=' '){
            s+=str[i] ; 
        }
    }
    reverse(v.begin(),v.end()) ; 
    str="" ; 
    for(int i = 0 ; i < v.size()-1 ; ++i){
        str+=v[i] ;
        str+=" " ; 
    }
    str+=v[v.size()-1] ;
    return str ; 
    }
};
