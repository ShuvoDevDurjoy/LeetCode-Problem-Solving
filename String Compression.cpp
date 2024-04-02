class Solution {
public:
    int compress(vector<char>& chars) {
             int size = chars.size() ; 
        if(size==1)return size ; 
    char c = chars[0] ;
    int count = 1 ;  
    int index = 0 ; 
    for(int i = 1 ; i < size ; ++i)
    {
        if(i+1==size){
            if(chars[i] == c){
                count++ ; 
                chars[index++] = c ;
            if(count!=1){
                string s = to_string(count) ;
                int ssize = s.size() ;  
                for(int x = 0 ; x < ssize ; ++x){
                    chars[index++] = s[x] ;
                }
            }
            }
            else {
                chars[index++] = c ;
            if(count!=1){
                string s = to_string(count) ;
                int ssize = s.size() ;  
                for(int x = 0 ; x < ssize ; ++x){
                    chars[index++] = s[x] ;
                }
            }
            chars[index++] = chars[i] ; 
            }
        }
        else if(chars[i]==c){
            count++ ; 
        }
        else {
            chars[index++] = c ;
            if(count!=1){
                string s = to_string(count) ;
                int ssize = s.size() ;  
                for(int x = 0 ; x < ssize ; ++x){
                    chars[index++] = s[x] ;
                } 
            }
            count = 1 ;
            c = chars[i] ;
        }

    }

    return index ;
    }
};
