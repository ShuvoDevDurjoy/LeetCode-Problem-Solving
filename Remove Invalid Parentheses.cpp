class Solution {
private: 
    stack<string> min_st;
    int size = 0;
    unordered_map<string,bool> maps;
    void generate(string &s, int index, int st_count, string &result){
        if(index >= size){
            int s_size = min_st.empty()?0:min_st.top().size();
            if(st_count==0 && result.size() >= s_size){
                while(!min_st.empty() && result.size() > min_st.top().size()){
                    min_st.pop();
                }
                if(maps[result]) return;
                maps[result] = true;
                min_st.push(result);
            }
        }
        else if('a' <= s[index] && s[index] <= 'z'){
            result += s[index];
            generate(s, index+1, st_count, result);
            result.erase(result.begin() + result.size() - 1);
        }
        else if(s[index] == ')'){
            generate(s, index+1, st_count, result);
            if(st_count == 0) return;
            result += s[index];
            generate(s, index+1, st_count-1, result);
            result.erase(result.begin() + result.size() - 1);
        }
        else{
            generate(s, index+1, st_count, result);
            result += s[index];
            generate(s, index+1, st_count + 1, result);
            result.erase(result.begin() + result.size() - 1);
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        size = s.size();
        string r;
        generate(s, 0, 0, r);
        while(!min_st.empty()){
            result.push_back(min_st.top());
            min_st.pop();
        }
        return result;
    }
};
