class Solution {
public:
    int size;
    bool solve(vector<bool> &track, vector<int> &result, string &pattern, int n){
        if(n>=size) return true;
        unordered_map<int,bool> maps;
        for(int i = 1 ; i <= 9 ; ++i){
            if(!track[i] && !maps[i] &&(pattern[n]=='I'?i>result[n]:i<result[n])){
                result[n+1] = i ; 
                track[i] = true;
                if(!solve(track, result,pattern,n+1)){
                    result[n+1] = -1;
                    track[i] = false;
                    maps[i] = true;
                    i = 0;
                }
                else{
                    return true;
                }
            }
        }
        return false;
    }
    string smallestNumber(string pattern) {
        size = pattern.size()+1;
        vector<bool> track(10,false);
        vector<int> result(size+1,-1);
        if(pattern[0]=='I'){
            pattern = "I"+pattern;
            result[0] = 0;
        }
        else{
            pattern = "D"+pattern;
            result[0] = 10;
        }
        solve(track,result,pattern,0);
        string r = "" ; 
        for(int i = 1 ; i < size+1; ++i){
            r += to_string(result[i]);
        }
        return r;
    }
};
