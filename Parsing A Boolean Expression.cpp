class Solution {
public:

    bool parseBoolExpr(string expression) {
    stack<char> char_stack;
    stack<bool> bool_stack;
    int length = expression.length();
    for (int i = 0; i < length; ++i)
    {
        if (expression[i] == '(' || expression[i] == ',')
            continue;
        else if (expression[i] == ')')
        {
            bool hasTrue= false , hasFalse = false ;
            while ((!char_stack.empty()) && (char_stack.top() != '&' && char_stack.top() != '|' && char_stack.top() != '!'))
            {
                if(char_stack.top()=='t'){
                    hasTrue = true;
                }
                else{
                    hasFalse = true;
                }
                char_stack.pop();
            }
            if (!char_stack.empty() && char_stack.top() == '&')
            {
                char_stack.pop();
                if(hasFalse){
                    char_stack.push('f');
                }else{
                char_stack.push('t');
                }
            }
            else if (!char_stack.empty() && char_stack.top() == '|')
            {
                char_stack.pop();
                if(hasTrue){
                    char_stack.push('t');
                }else{
                    char_stack.push('f');
                }
            }
            else
            {
                char_stack.pop();
                if(hasTrue){
                    char_stack.push('f');
                }else{
                char_stack.push('t');
                }
            }
        }
        else if (expression[i] == '|' || expression[i] == '&' || expression[i] == '!' || expression[i] == 't' || expression[i] == 'f')
        {
            char_stack.push(expression[i]);
        }
    }
    return char_stack.top() == 't' ? true : false;
    }
};
