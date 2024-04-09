class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> sw ; 
        queue<int> s ; 
        for(int i = sandwiches.size()-1  ; i>=0 ; --i ){
            sw.push(sandwiches[i]) ; 
        }
        for(int i = 0 ; i < students.size() ; ++i)
        {
            s.push(students[i]) ; 
        }

        int size = 0 ; 
        while(size!=s.size())
        {
            if(s.front()==sw.top())
            {
                s.pop() ; 
                sw.pop() ; 
                size = 0 ; 
            }
            else
            {
                int x = s.front(); 
                s.pop() ; 
                s.push(x) ; 
                size++ ; 
            }
        }
        return s.size() ; 
    }
};
