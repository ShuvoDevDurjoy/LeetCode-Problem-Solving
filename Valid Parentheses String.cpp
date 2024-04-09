class Solution {
public:
    bool checkValidString(string s) {
        stack<int> op ;  
        stack<int> st; 
       for(int i=0;i<s.length();i++){
      if(s[i] == '(') op.push(i);
      else if(s[i] == '*') st.push(i);
      else if(s[i] == ')'){
        if(op.size() > 0) op.pop();
        else if(st.size() > 0) st.pop();
        else return false;
      }
    }

    while(op.size() > 0 && st.size() > 0){
      if(op.top() > st.top()) return false;
      op.pop();
      st.pop();
    }
    return op.size() == 0; 
    }
};
