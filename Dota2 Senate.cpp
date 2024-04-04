class Solution {
public:
    string predictPartyVictory(string senate) {
        int size = senate.length() ; 
        queue<int> rq ; 
        queue<int> dq ; 

        for(int i = 0 ; i < size ; ++i){
            if(senate[i] == 'D')
            dq.push(i) ; 
            else rq.push(i) ; 
        }
        while (!rq.empty() && !dq.empty()){
            if (rq.front() < dq.front()){
                rq.push(size++);
            }
            else {
                dq.push(size++);
            }
            rq.pop(), dq.pop();
        }
        if (dq.size()==0) return "Radiant" ; 
        else return "Dire" ; 
    }
};
