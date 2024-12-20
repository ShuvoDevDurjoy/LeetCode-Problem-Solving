class Solution {
public:
    bool check(vector<bool> &track, int x){
        for(int i = 0 ; i <= x ; ++i){
            if(track[i]==false) return false;
        }
        return true;
    }
    int maxChunksToSorted(vector<int>& arr) {
        int size = arr.size(); 
        vector<bool> track(size,false) ;
        int count = 0; 
        for(int i = 0 ; i < size ; ++i){
            track[arr[i]] = true;
            if(check(track,i)){
                ++count ; 
            }
        } 
        return count==0?1:count;
    }
};
