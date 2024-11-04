class Solution {
public:
    int max ;
    void check(unordered_map<string,bool> &par){
        stack<char> stk ; 
        for(const auto& paren : par){
            string str = paren.first ; 
            stk.push(str[0]);
            int index = 1 ; 
            bool valid = true ; 
            for(int i = 1 ; i < max*2 ; ++i){
                if(str[i]=='(') stk.push('(');
                else if(str[i]==')' && (!stk.empty() && stk.top()=='(')) stk.pop();
                else{
                    par[str] = false ; 
                    while(!stk.empty()) stk.pop();
                    break;
                }
            }
        }
    }
    void forward_parenthesis(int front,int back, string str, unordered_map<string,bool> &paranthesis){
        if(front>max || back>max) return ; 
        if(front==back && front==max){
            if(paranthesis.find(str) == paranthesis.end())
            paranthesis[str] = true;
            return ;
        }
        backward_parenthesis(front+1,back,str+'(',paranthesis);
        forward_parenthesis(front+1,back,str+'(',paranthesis);
    }
    void backward_parenthesis(int front,int back, string str, unordered_map<string,bool> &paranthesis){
        if(front>max || back>max) return ; 
        if(front==back && front==max){
            if(paranthesis.find(str) == paranthesis.end())
            paranthesis[str] = true;
            return ;
        }
        forward_parenthesis(front,back+1,str+')',paranthesis);
        backward_parenthesis(front,back+1,str+')',paranthesis);
    }
    vector<string> generateParenthesis(int n) {
        max = n; 
        unordered_map<string,bool> paren;
        forward_parenthesis(0,0,"",paren);
        check(paren);
        vector<string> parenthesis ; 
        for(const auto& pair : paren){
            if(pair.second){
                parenthesis.push_back(pair.first);
            }
        }
        return parenthesis;
    }
};
