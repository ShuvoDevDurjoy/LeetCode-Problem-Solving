class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       int size = flowerbed.size();
       if(size==1 && n==1){
        if(flowerbed[0]==0) return true ; 
        return false ; 
       }
    for(int i = 0 ; i < size ; ++i){
        if(n==0) return true ; 
        if(flowerbed[i]==1) continue ; 
        else {
            if(i==0){
                if(flowerbed[i+1]==0){
                    flowerbed[0] = 1 ; 
                    n-- ; 
                }
            }
            else if(i==size-1 ){
                if(flowerbed[i-1]==0)
                {flowerbed[i] = 1 ; 
                n-- ; 
                }

            }
            else {
                if(flowerbed[i+1]==0 && flowerbed[i-1]==0){
                    flowerbed[i]=1 ; 
                    n-- ; 
                }
            }
        }
    }
    if(n==0) return true ; 
    return false ;  
    }
};
