//This will check for the first occurance of the needle string in the haystack string and will return the index . If the string needle is not found in the 
//haystack string then it will return -1 .
public int strStr(String haystack, String needle) {
        int length1 = haystack.length();
        int length2  = needle.length() ; 
        if(length1 < length2){
            return -1 ; 
        }

        int index = 0 ; 
        int find = -1 ; 
        for (int i = 0 ; i < length1 ; ++ i){
            if(index == length2)
            {
                return find ; 
            }
            else if(haystack.charAt(i) == needle.charAt(index))
            {
                index++ ; 
                if(find == -1 ){
                    find = i ; 
                }
                continue ; 
            }
            else if(index > 0 ){
                index = 0 ; 
                i = find  ; 
                find = -1 ; 
                continue ; 
            }
            find = - 1; 
        }
        if(find != -1 && index == length2){
            return find ; 
        }
        return -1 ; 
    }
