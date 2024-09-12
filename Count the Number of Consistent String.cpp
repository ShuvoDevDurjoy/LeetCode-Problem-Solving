class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,bool> maps ; 
        for(int i = 0 ; i < 26 ; ++i){
            maps['a'+i] = false ; 
        }

        int size = allowed.length() ; 
        for(int i = 0 ; i < size ; ++i){
            maps[allowed[i]] = true ; 
        }

        int row = words.size() ;
        int count = 0 ;  
        for(int i = 0 ; i < row ; ++i){
            int column = words[i].length() ;
            bool allow = true ;  
            for(int j = 0 ; j < column ; ++j){
                if(maps[words[i][j]]==false){
                    allow = false ; 
                    break ; 
                }
            }
            allow?count++:count; 
        }
        return count ; 
    }
};
