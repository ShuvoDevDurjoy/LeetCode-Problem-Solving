class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> stacks ; 
        string ans ; 
        string cur ; 
        for(int i = 0 ; i < s.length() ; ++i){
            if(s[i]=='(')
            stacks.push('(') ; 
            else if(s[i]==')')
            {
                if(stacks.empty())
                {
                    continue ;
                }
                else {
                    stacks.pop() ; 
                }
            }
            
                ans+=s[i] ; 
            

        }
        cout<<"Here ans is : "<<ans<<endl;
        s = ans ; 
        ans = ""  ; 
        while(!stacks.empty())
        stacks.pop() ;
        // reverse(s.begin() , s.end()) ; 
        for(int i = s.length()-1 ; i>=0 ; --i){
            if(s[i]==')')
            stacks.push(')') ; 
            else if(s[i]=='(')
            {
                if(stacks.empty())
                {
                    continue ;
                }
                else {
                    stacks.pop() ; 
                }
            }
            
                ans+=s[i] ; 
            

        } 
        reverse(ans.begin(),ans.end()) ; 

        return ans; 
    }
};
