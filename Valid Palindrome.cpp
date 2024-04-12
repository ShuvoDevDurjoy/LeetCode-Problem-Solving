class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string str = "" ; 
        for(int i = 0 ; i < s.size() ; ++i){
            if(isalnum(s[i]))
            str+=s[i] ; 
        }
        int left = 0 ; 
        int right = str.length()-1 ; 
        // if(right==0) return false ; 
        while(left<right)
        {
            if(str[left]!=str[right])
            return false ; 

            left++ ; 
            right-- ; 
        }
        cout<<str<<endl;
        return true ; 
    }
};
