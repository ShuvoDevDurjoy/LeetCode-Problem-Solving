class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int> maps ; 
        int size = nums.size();
        int s = 0; 
        for(int i = 0 ; i < size ; ++i){
            maps[nums[i]]+=nums[i];
        }

        unordered_map<int,int>::iterator it = maps.begin();

        vector<int> track ; 

        while(it!=maps.end()){
            track.push_back(it->first);
            it++;
        }

        size = track.size();

        sort(track.begin(),track.end());

        track.push_back(0);
        track.push_back(0);

        int maximum = 0 ;

        for(int i = size-1; i >= 0 ; --i){
            if(maps[track[i]+1]){
                maps[track[i]] += maps[track[i+2]];
            }
            else{
                maps[track[i]] += maps[track[i+1]];
            }
            maps[track[i]] = max(maximum,maps[track[i]]);
            maximum = max(maximum, maps[track[i]]);
        }


        return max(maps[track[0]],maps[track[1]]);
    }
};
