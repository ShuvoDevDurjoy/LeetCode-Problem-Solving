class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int zeros = 0 ; 
    int product = 1 ; 
    int size = nums.size() ; 
    for(int i = 0 ; i < size ; i++){
        if(nums[i]==0){
            zeros++ ; 
            if(zeros==2){
                return vector<int>(size , 0) ; 
            }
        }
        else {
            product*=nums[i] ; 
        }
    }

    vector<int> answer ; 
    for(int i = 0 ; i < size ; i++)
    {
        if(zeros){
            if(nums[i]==0) answer.push_back(product) ; 
            else answer.push_back(0) ; 
        }
        else {
            answer.push_back(product/nums[i]) ;
        }
    }
    return answer ;  
    }
};
