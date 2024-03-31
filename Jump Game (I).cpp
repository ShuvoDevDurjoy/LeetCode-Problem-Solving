#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums){
    int current = 0 ; 
    int Intervalmax = 0 ; 
    int reached = 0 ; 
    int size = nums.size() ;
    int i = 0 ;  
    while(i < size){
        Intervalmax = max(Intervalmax , nums[i]+i) ; 
        Intervalmax = min(Intervalmax , size-1) ; 
        if(i == current ){
            current = Intervalmax ;
        }
        i++ ; 
    }
    if(current == size-1){
        return true ; 
    }
    return false ; 
}
};
int main(){
    vector<int> nums = {3,2,1,1,4} ; 
    Solution s  ; 
    bool result = s.canJump(nums) ; 
    cout<<boolalpha ; 
    cout<<result<<endl;
    
}
