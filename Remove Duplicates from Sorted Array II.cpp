class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int current = nums[0] ; 
   int count = 1 ; 
   int curindex = 1 ; 
   for(int i = 1; i < nums.size() ; ++i)
   {
      if(nums[i]==current && count<2)
      {
         nums[curindex] = current ; 
         count++ ; 
         curindex++ ; 
      }
      else if(nums[i]!=current)
      {
         nums[curindex] = nums[i] ; 
         current = nums[i] ; 
         count = 1 ; 
         curindex++ ; 
      }
   }
   return curindex ;
    }
};
