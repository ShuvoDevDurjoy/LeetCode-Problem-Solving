class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int size = gain.size() ; 
        int sum = 0 ; 
        for(int i = 0 ; i < size ; ++i){
            int temp = gain[i] ; 
            gain[i] = sum ; 
            sum+=temp ; 
        }
        gain.push_back(sum) ; 
        sort(gain.begin(),gain.end()) ; 
        return gain[size] ; 
    }
};
