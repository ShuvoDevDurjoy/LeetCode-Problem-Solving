class Solution {
public:
    string reverseVowels(string str) {
    bool leftfound = false ; 
    bool rightfound = false ; 
    int left = 0 ; 
    int right = str.length() - 1 ;
    while(left<right){
        char c = tolower(str[left]) ; 
        cout<<c<<'*'<<endl;
        if(!leftfound && c=='a'||c=='e'||c=='o'||c=='i'||c=='u') leftfound = true ; 
        c = tolower(str[right]) ;
        cout<<c<<endl; 
        if(!rightfound && c=='a'||c=='e'||c=='o'||c=='i'||c=='u') rightfound = true ;
        if(leftfound&&rightfound){
            c = str[left] ; 
            str[left] = str[right] ; 
            str[right] = c ;
            leftfound =false ; 
            rightfound = false ; 
            left++ ; 
            right-- ; 
            continue ;  
        }
        if((!leftfound&&!rightfound))
        {
            left++ ; 
            right-- ; 
            continue ; 
        }
        if(leftfound){
            right-- ; 
        }
        if(rightfound){
            left++ ; 
        }

    }
    return str ; 
    }
};
