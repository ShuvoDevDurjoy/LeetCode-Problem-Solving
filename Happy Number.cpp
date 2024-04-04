class Solution {
public:
    bool isHappy(int n) {
        if(n==1||n==7) return true ; 
        else if(n>1 && n<7) return false ; 
        else {
            int sum = n  ; 
            while(true){
                if(sum==1||sum==7)return true ; 
                if(sum>1 && sum < 7) return false ; 
                int tempsum = 0 ; 
                while(sum!=0){
                    tempsum+= pow(sum%10 , 2);
                    sum/=10 ; 
                }
                sum = tempsum ; 
            }
        }
    }
};
