// i solved this problem using both recursion and iteration . here both of the code has been given 

//using recursion 
class Solution {
public:
int countJump(vector<int> &nums , int index , int size, vector<int> &track){
    if(index == size){
        return 0 ; 
    }
    int top = index + nums[index] ; 
    if(top>size){
        top = size ; 
    }
    if(track[index]!=-1){
        return track[index] ; 
    }

    int minValue = size ; 
    for(int i = index+1 ; i <= top ; ++i){
        int x =1+countJump(nums , i , size  , track) ;  
        if(x < minValue){
            minValue = x ; 
        }
    }

    track[index] = minValue ; 
    return minValue ; 
}
    int jump(vector<int>& nums) {
        int size = nums.size() ; 
    vector<int> track(size,-1) ; 
     int x = countJump(nums , 0 , size-1 , track) ;
     return x ; 
    }
};


//using iteration : 
class Solution{
public : 
  int jump(vector<int> &nums){

    int size = nums.size()-1 ; 
    int current = 0 ; 
    int farMost = 0 ;
    int jump = 0 ; 
    if(size==0){
      return 0 ; 
    }

    for(int i = 0 ; i < size ; ++i){
      far = max(far , nums[i]+i) ; 
      if(i==current){
        current = far ; 
        ++jump ; 
      }
    }

    return jump ; 
  }
}
