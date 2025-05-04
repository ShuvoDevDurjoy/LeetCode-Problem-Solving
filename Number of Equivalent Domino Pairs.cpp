class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<string, int> maps;
        stringstream ss;
        ss.str("");
        for( vector<int> &temp: dominoes){
            ss<<min(temp[0], temp[1])<<max(temp[0], temp[1]);
            maps[ss.str()]++;
            ss.str("");
        }

        int count = 0;

        unordered_map<string, int>::iterator it;
        it = maps.begin();
        while(it!=maps.end()){
            count += (((it->second)*(it->second - 1))/2);
            it++;
        }
        return count;
    }
};
