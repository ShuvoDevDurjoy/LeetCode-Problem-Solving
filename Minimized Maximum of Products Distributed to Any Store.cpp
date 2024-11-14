class Solution {
public:
    int size =  0; 
    int can_distribute(vector<int> &q, int n, int k){
        int count = 0 ; 
        int quotient = 0 ; 
        int remainders = 0 ; 
        for(int i = 0 ; i < size ; ++i){
            quotient = q[i]/k ; 
            remainders = q[i]%k ; 
            count +=(quotient+(remainders==0?0:1)); 
        }
        if(count<=n){
            return 0 ; 
        }
        else{
            return 1 ; 
        }
    }
    int minimizedMaximum(int n, vector<int>& q) {
        int start = 1 ; 
        int end = 0 ; 
        size = q.size() ;
        for(int i = 0 ; i < size ; ++i){
            if(q[i]>end){
                end = q[i] ; 
            }
        } 
        int mid ;  
        int prevmid = end ;
        int result = end; 
        while(start<=end){
            mid = start + (end-start)/2 ;
            int check = can_distribute(q,n,mid) ; 
            if(check==1){
                start = mid+1 ; 
            }
            else{
                end = mid-1 ; 
                result = min(prevmid,mid) ; 
                prevmid = mid ; 
            }
        }
        return result ; 
    }
};
