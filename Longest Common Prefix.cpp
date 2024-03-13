string longestCommonPrefix(vector<string>& strs) {
        bool moreToSearch = true ;
    string prefix = ""; 
    int i = 0 ; 
    while(moreToSearch && i < strs.at(0).length()){
        char c = strs.at(0)[i];
        bool match = true ; 
        for (int j = 1 ; j < strs.size() ; j++){
            if(i>=strs.at(j).length()){
                match = false ; 
                moreToSearch = false ; 
                break ; 
            }
            else if(strs.at(j)[i] == c){
                match = true ;  
            }
            else {
                match = false ; 
                moreToSearch = false ; 
                break ;
            }
        }
        if(match){
            prefix += c ;
        }
        i++ ; 
    }
    return prefix ; 
    }
