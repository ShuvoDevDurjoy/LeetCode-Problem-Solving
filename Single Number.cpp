class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int , int> maps ; 
        for(int i = 0 ; i < nums.size() ; ++i)
        {
            maps[nums[i]]++ ; 
        }

        unordered_map<int,int>::iterator iterator = maps.begin() ; 
        while(iterator!=maps.end())
        {
            if(iterator->second==1)
            return iterator->first ; 
            iterator++ ; 
        }
        return 0 ; 
    }
};
