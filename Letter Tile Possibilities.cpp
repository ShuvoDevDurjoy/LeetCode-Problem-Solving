class Solution {
public:
    int count = 0;
    void backTrack(unordered_map<char,int> &maps){
            for(auto &entry : maps){
            if(entry.second>0){
                maps[entry.first]--;
                count++;
                backTrack(maps);
                maps[entry.first]++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        unordered_map<char,int> maps;
        for(auto &s : tiles){
            maps[s]++;
        }
        backTrack(maps);
        return count;
    }
};
