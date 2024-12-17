class Solution {
public:
    string buildString(char c, int n ){
        string s = "" ; 
        for(int i = 0 ; i < n ; ++i){
            s += c ; 
        }
        return s; 
    }
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char,int>> pq;
        unordered_map<char,int> maps ; 
        int size = s.length() ; 
        for(int i = 0 ; i < size ; ++i){
            maps[s[i]]++;
        }

        unordered_map<char,int>::iterator it = maps.begin();
        while(it!=maps.end()){
            pq.push({it->first,it->second});
            it++;
        }

        pair<char,int> tempPair ; 
        int t ; 
        string result ;
        char recent = ' '; 
        bool checked = false;
        while(!pq.empty()){
            tempPair = pq.top() ;
            pq.pop();
            // cout<<tempPair.first<<" and "<<recent<<endl;
            if(tempPair.first==recent){
                t = 1 ; 
                if(pq.empty()){break;}
                
                pair<char,int> temp2 = pq.top() ;
                pq.pop();
                pq.push({tempPair.first,tempPair.second}); 
                if(temp2.second-1>0)
                pq.push({temp2.first,temp2.second-1});
                tempPair = temp2 ; 
            }
            else{
                if(tempPair.second>repeatLimit){
                    t = repeatLimit ; 
                    pq.push({tempPair.first,tempPair.second-t});
                }
                else{
                    t = tempPair.second;
                }
            }
            // cout<<tempPair.first<<" " <<t<<endl;
            result += buildString(tempPair.first,t);
            recent = tempPair.first;
        }
        return result ;  
    }
};
