class MinStack {
public:
    vector<vector<int>> nums ; 
    int index = 0 ; 
    int minSoFar = INT_MAX ; 
    MinStack() {
        
    }
    
    void push(int val) {
        int minimum = min(minSoFar , val) ; 
        minSoFar = minimum; 
        nums.push_back({val,minimum}) ; 
        index++ ; 
    }
    
    void pop() {
        if(index==1) minSoFar = INT_MAX ; 
        else minSoFar = nums[index-2][1] ; 
        nums.pop_back() ;
        index-- ;  
    }
    
    int top() {
        return nums[index-1][0] ; 
    }
    
    int getMin() {
        return nums[index-1][1] ; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
