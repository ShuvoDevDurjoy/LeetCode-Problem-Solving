class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int size = 0 ; 
        while(tickets[k]!=0)
        {for(int i = 0 ; i < tickets.size() ; ++i){
            if(tickets[k]==0)
            break ; 
            else if(tickets[i]==0)
            continue ; 
            else if(tickets[i]>0){
                size++ ; 
                tickets[i] = tickets[i]-1 ; 
            }
        }
        }
        return size ; 
    }
};
