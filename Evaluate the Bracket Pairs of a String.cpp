class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        stringstream stm;
        int size = s.size();
        unordered_map<string, string> maps;
        for(int i = 0;i < knowledge.size(); ++i){
            maps[knowledge[i][0]] = knowledge[i][1];
        }
        for(int i = 0; i < size; ++i){
            if(s[i]=='('){
                string str = "";
                i++;
                while(i < size && s[i] != ')'){
                    str += s[i++];
                }
                if(maps[str] != ""){
                    stm << maps[str];
                }
                else{
                    stm << "?";
                }
            }
            else{
                stm << s[i];
            }
        }

        return stm.str();
    }
};
