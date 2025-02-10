class Solution {
public:
    string clearDigits(string s) {
        stack<char> stacks;
        int size = s.size();
        for(int i = 0 ; i < size ; ++i){
            if(isdigit(s[i])){
                stacks.pop();
            }
            else{
                stacks.push(s[i]);
            }
        }

        string result = "";
        while(!stacks.empty()){
            result+=stacks.top();
            stacks.pop();
        }
        reverse(result.begin(),result.end());
        return result;;
    }
};
