class RecentCounter {
public:
    vector<int> counter ; 
    RecentCounter() {
        counter.push_back(0) ; 
    }
    
    int ping(int t) {
        counter.push_back(t) ; 
        int time = t - 3000 ; 
        int size = counter.size()-1; 
        int count = 0 ; 
        for(int i = size ; i >=0 && counter[i] >= time && counter[i]!=0 ; --i)
            count++ ; 
        return count ; 
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
