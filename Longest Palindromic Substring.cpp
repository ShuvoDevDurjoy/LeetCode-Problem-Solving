    string longestPalindrome(string s) {
    int maxsize = 0 ;
        int left = 0 ; 
        int right = 0 ;
        int length = s.length();
        for (int i = 0 ; i < length ; i++){
            int size1 , size2 ; 
            int a , b , c , d ; 
            a = i ; b = i ; 
            while(a>0&&b<length){
                if(s[--a]!=s[++b]){
                    a++ ; 
                    b-- ; 
                    break ; 
                }
            }
            if(i+1<length){
            c = i+1 ; 
            d = i ; 
            while(c>0 && d < length){
                if(s[--c]!=s[++d]){
                    c++ ; 
                    d-- ; 
                    break ; 
                }
            }
            }

            size1 = b - a +1 ; 
            size2 = d - c +1 ;
            if(size1 > maxsize || size2 > maxsize){
                if(size1>size2){
                    maxsize = size1;
                    left = a ; 
                    right = b ; 
                }
                else {
                    maxsize = size2 ; 
                    left = c ; 
                    right = d ;
                }
            }
        }
        string str ; 
        for(left ; left <=right ; left++){
            str += s[left];
        }
        return str ; 
    }
