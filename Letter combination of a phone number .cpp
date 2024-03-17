vector<string> letterCombinations(string digits) {
        int length = digits.length() ; 
    vector<string> ans;
    if(length == 0){
        return ans;
    }

    char arr[length*2] ; 
    int index = 0 ; 
    for (int i = 0 ; i < length ; ++ i){
        if(digits[i]=='7'){
            arr[index] =97+ 5*3 ; 
            arr[index+1] = arr[index]+4 ;
            index+=2 ;  
        }
        else if(digits[i]=='8'){
            arr[index] = 97 + 6*3 +1 ; 
            arr[index+1] = arr[index]+3 ;
            index+=2 ; 
        }
        else if(digits[i]=='9'){
            arr[index] = 97 + 7*3 +1 ;
            arr[index+1] = arr[index] + 4 ; 
            index+=2 ;  
        }
        else 
        {
            arr[index] = 97+ (digits[i]-'2')*3;
            arr[index+1] = arr[index] + 3 ;
            index+=2 ; 
        }
    } 
    if(length==1){
        for(char f = arr[0] ; f < arr[1] ; ++ f){
            ans.push_back(string(1,f));
        }
    }
    else if(length ==2 ){
        for(char f = arr[0] ; f < arr[1] ; ++f){
            for(char l = arr[2] ; l < arr[3] ; ++ l ){
                ans.push_back(string(1, f) + l) ; 
            }
        }
    }
    else if(length==3){
        for(char f = arr[0] ; f < arr[1] ; ++f){
            for(char m = arr[2] ; m < arr[3] ; ++ m ){
                for(char l = arr[4] ; l < arr[5] ; ++l){
                ans.push_back(string(1, f)+m+l) ; 
                }
            }
        }
    }
    else {
        for(char f = arr[0] ; f < arr[1] ; ++f){
            for(char m = arr[2] ; m < arr[3] ; ++ m ){
                for(char n = arr[4] ; n < arr[5] ; ++n){
                    for(char l = arr[6] ; l < arr[7] ; ++l){
                    ans.push_back(string(1, f)+m+n+l) ;
                    }
            }
        }
    }
}
    return ans ; 
    }
