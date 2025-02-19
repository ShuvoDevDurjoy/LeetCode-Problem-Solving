class Solution {
public:
    int target ;
    int size ; 
    int count = 0;
    void solve(string &result, int index){
        if(index > size){
            ++count;
            return ;
        }
        for(auto &c : {'a','b','c'}){
            if(c!=result[index-1]){
                result[index] = c ;
                solve(result,index+1);
                if(count==target){
                    return ;
                } 
            }
        }
    }
    string getHappyString(int n, int k) {
        target = k ; 
        size = n ;
        string result = "xxxxxxxxxxx";
        solve(result,1);
        if(count<k) return "";
        return result.substr(1,size);
    }
};
