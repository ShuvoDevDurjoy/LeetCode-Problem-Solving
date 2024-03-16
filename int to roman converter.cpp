#include <iostream>
using namespace std; 
//this code can convert any integer nuber within range 1 < 4000 to its corresponding roman number . 
string checking(int value , int size){
    string s , g , gg; 
    switch (size){
        case 1 : s = "I" , g = "V"  , gg = "X" ; 
        break ; 
        case 10 : s = "X" , g = "L" , gg = "C" ; 
        break ; 
        case 100 : s = "C" , g = "D" , gg = "M" ; 
        break ; 
        default : s = "M" , g = "M" , gg = "M" ; 
    }

    switch (value) {
        case 1 : return s+"" ; 
        case 2 : return s+s+"" ; 
        case 3 : return s+s+s+"" ; 
        case 4 : return s+g+"" ; 
        case 5 : return g+"" ; 
        case 6 : return g+s+"" ; 
        case 7 : return g+s+s+"" ; 
        case 8 : return g+s+s+s+"" ; 
        case 9 : return s+gg+"" ; 
        case 10 : return gg+"" ; 
    }
    return "" ; 
}


string intToRoman(int num){
    if(num >= 4000){
        return "" ; 
    }
    string roman = "" ; 
    int m = 1 ; 
    while(num!=0){
        roman = checking(num%10 , m ) +roman; 
        num = num/10 ; 
        m = m*10 ; 
    }
    return roman ; 
}


int main(){
    for (int i = 1 ; i < 4000 ; ++  i ){
        cout<<i<<" -> "<<intToRoman(i)<<endl ; 
    }
    cout<<endl;
}
