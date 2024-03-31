#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval) ; 
        sort(intervals.begin() , intervals.end()) ; 
        
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
    return  result ; 
    }
};
int main(){
    vector<vector<int>> intervals = {{1,3},{6,9}} ; 
    vector<int> newInterval = {2,5} ;
    Solution s ;
    vector<vector<int>> result = s.insert(intervals, newInterval) ;
    for(vector<int> i : result){
        cout<<i[0]<<" "<<i[1]<<endl;
    }

    
}
