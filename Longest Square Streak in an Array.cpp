class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int,bool> maps ; 
        int size = nums.size() ; 
        for(int i = 0 ; i < size ; ++i){
            maps[nums[i]] = true;
        }
        int maxsize = 0; 
        sort(nums.begin(),nums.end());

        for(int i = 0 ; i < size ; ++i){
            if(maps[nums[i]]){
                int executing = nums[i] ; 
                nums[i] = 0 ; 
                unordered_map<int,bool>::iterator it ; 
                while((maps.find(executing)!=maps.end())&&(maps[executing])){
                    maps[executing] = false ;
                    nums[i]++;
                    if(nums[i]>maxsize){
                        maxsize = nums[i] ; 
                    } 
                    if(executing>316) break;
                    executing = executing*executing; 
                }
            }
        }
        return maxsize>=2?maxsize:-1;
    }
};
