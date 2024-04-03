class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> result ; 
     for(int i = 0 ; i < arr.size() ; ++i){
        result[arr[i]]++ ; 
     }

     for(auto i = result.begin() ; i!=result.end() ; ++i){
        int count = 0 ; 
        for(auto it = i ; it!=result.end() ; ++it){
            if((int)it->second == (int)i->second)
            {
                count++ ; 
                if(count==2)return false ;
            }
        }
     }
     return true ; 
    }
};
