class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        unordered_map<char, int> end_map;
        int size = s.size();
        for(int i = 0; i < size; ++i){
            end_map[s[i]] = max(end_map[s[i]], i);
        }

        vector<pair<int,int>> valid_sequences;

        vector<bool> visited(26, false);
        for(int i = 0; i < size; ++i){
            if(visited[s[i] - 'a']) continue;
            int start_index = i;
            int end = end_map[s[i]];
            int x = i;
            bool valid = true;
            while(x < end && valid){
                if(visited[s[x] - 'a']) {valid = false; break;}
                end = max(end_map[s[x]], end); 
                x++;
            }
            if(valid){
                valid_sequences.push_back({start_index, end});
            }
            visited[s[i]-'a'] = true;
        }

        sort(valid_sequences.begin(), valid_sequences.end(), [](pair<int,int> &a, pair<int,int> &b){
            return a.second < b.second;
        });

        vector<string> result;
        int n = valid_sequences.size();
        pair<int,int> last = {-1, -1};
        for(int i = 0; i < n; ++i){
            if(valid_sequences[i].first > last.second){
                result.push_back(s.substr(valid_sequences[i].first, valid_sequences[i].second - valid_sequences[i].first + 1));
                last = valid_sequences[i];
            }
        }

        return result;
    }
};
