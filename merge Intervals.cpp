#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public : 
    vector<vector<int>> merge(vector<vector<int>> &intervals){
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    int size = intervals.size() ; 
    vector<vector<int>> result ; 
    result.push_back(intervals[0]) ; 
    int index = 0 ; 
    for(int i = 1; i < size; i++){
        if(intervals[i][0] >= result[index][0] && intervals[i][0] <= result[index][1]){
            if(intervals[i][1] >= result[index][1]){
                result[index][1] = intervals[i][1] ;
            } 
        }
        else{
            index++ ; 
            result.push_back(intervals[i]) ; 
        }
    }
    return result ;
}
};
int main(){
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}} ; 
    Solution s  ; 
    vector<vector<int>> result = s.merge(intervals) ; 
    for(int i = 0 ; i < result.size() ; ++i){
        cout<<result[i][0]<<" "<<result[i][1]<<endl;
    }
}
