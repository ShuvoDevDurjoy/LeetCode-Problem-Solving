#include <iostream>
using namespace std ; 

string say(string s){
    string str = "" ; 
    for(int i = 0 ; i < s.length() ; ++i){
        int count = 0 ;
        if(s[i]=='*') continue ; 
        char c = s[i] ;  
        for(int j = i ; j  < s.length() ; ++j){
            if(s[j]==c){
                count++ ;
                s[j] = '*' ; 
                continue ; 
            }
            break ; 
        }
        str += to_string(count) + c ;
    }
    return str ; 
}

string countAndSay(int n ){
    string str = "1" ; 
    for(int i = 1 ; i < n ; ++i){
        str = say(str) ; 
    }
    return str ; 
}
