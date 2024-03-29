#include <iostream>
using namespace std;

string sum(string str1 , string str2){
    int len1 = str1.length() ; 
    int len2 = str2.length() ; 
    if(len1==0 || len2==0){
        return str1+str2 ; 
    }
    int fin = len1 - 1; 
    int sin = len2 - 1; 
    int carry = 0 ; 
    string ans = "" ; 
    while(fin>=0 && sin >= 0){
        int s = (str1[fin--]-48)+(str2[sin--]-48)+carry ; 
        carry = s/10 ; 
        ans = to_string(s%10) + ans ; 
    }
    while(fin>=0){
        int s = (str1[fin--]-48)+carry ; 
        carry = s/10 ; 
        ans = to_string(s%10) + ans ;
    }
    while(sin>=0){
        int s = (str2[sin--]-48)+carry ; 
        carry = s/10 ; 
        ans = to_string(s%10) + ans ;
    }
    if(carry > 0){
        ans = to_string(carry) + ans ;
    }
    return ans ; 
}

string multiplyTwo(string s , int val ){
    int length = s.length(); 
    if(length==0){
        return "0" ; 
    }
    string ans = "" ; 
    int carry = 0 ; 
    for(int i = length-1 ; i >= 0 ; --i){
        int mul = (s[i]-48)*val+carry ; 
        carry = mul/10 ; 
        ans = to_string(mul%10) + ans ;
    }
    if(carry>0){
        ans = to_string(carry) + ans ;
    }
    return ans ; 
}

string multiply (string num1 , string num2){
    int length1 = num1.length() ; 
    int length2 = num2.length() ; 
    string ans = "" ; 
    string extra = "" ; 
    for(int i = length1-1 ; i>=0 ; --i){
        string mul = multiplyTwo(num2,num1[i]-48)+extra; 
        string s = sum(mul,ans) ; 
        ans  = s ; 
        extra +="0" ; 
    }
    return ans ; 
}

int main(){
    string s = multiply("999","999") ; 
    cout<<s<<endl;
}
