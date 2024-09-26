struct Event{
    int start ; 
    int end ; 
} ; 
class MyCalendar {
public:
    vector<int> events ; 
    int size = 0 ; 
    MyCalendar() {
        
    }

    bool checkWithin(int start , int end , int start1 , int end1){
        if((start1>=start && start1<end)){ 
            return true ; 
        }
        else if((end1>start && end1<=end)){
            return true ; 
        }
        else if(start1<start && end1>end){
            return true ; 
        }
        else if(start1>start && end1<end){
            return true ; 
        }
        return false ; 
    }
    
    bool book(int start, int end) {
        if(start==70 && end==71){
            for(int i = 0 ; i < events.size(); ++i){
                cout<<events[i]<<" " ; 
            }
            cout<<endl;
        }
        int size = events.size() ; 
        if(size==0){
            events.push_back(start) ; 
            events.push_back(end) ; 
            return true ; 
        }
        bool interval = false ; 
        if(end<=events[0]){
            events.insert(events.begin(),start) ; 
            events.insert(events.begin()+1,end) ;
            return true ;  
        }
        for(int i = 1 ; i < size ; ++i){
            if(i%2==1){
                if(checkWithin(events[i-1],events[i],start,end)){
                    return false ; 
                }
                else{
                    continue ; 
                }
            }else{
                if(start>=events[i-1] && end<=events[i]){
                    
                    events.insert(events.begin()+i,start) ; 
                    events.insert(events.begin()+(i+1),end) ; 
                    return true ; 
                }
                else{
                    continue ; 
                }
            }
        }
        events.push_back(start) ; 
        events.push_back(end) ; 
        return true ; 
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
