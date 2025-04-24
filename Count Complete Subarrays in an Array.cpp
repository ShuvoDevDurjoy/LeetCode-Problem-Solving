class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int,int> maps;
        int distinctCount = 0;
        for(int i = 0; i < size; ++i){
            if(!maps[nums[i]]){
                ++distinctCount;
                maps[nums[i]] = 1;
            }
        }

        maps.clear();

        int left = 0;

        int result = 0;
        int count = 0;

        for(int i = 0;i < size; ++i){
            if(!maps[nums[i]]){
                ++count;
                maps[nums[i]] = 1;
            }
            else{
                maps[nums[i]]++;
            }
            
            if(count==distinctCount){
                while(left<i && maps[nums[left]]>1){
                    maps[nums[left]]--;
                    left++;
                }

                result += (left+1);
            }
        }

        return result;

    }
};
