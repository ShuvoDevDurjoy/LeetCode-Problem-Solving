class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int size = nums.size() - 1;
        //Dynamic Part 1 
        vector<int> dynamic1(size+1,1) ; 
        int index = 1 ; 
        while(index<=size){
            int maximum = 0 ; 
            for(int i = index-1 ; i >= 0 ; --i){
                if(nums[i]<nums[index]){
                    maximum = max(maximum,dynamic1[i]) ; 
                }
                
            }
            dynamic1[index] += maximum;
            index++;
        }
        //Dynamic part 2
        vector<int> dynamic2(size+1,1) ; 
        index = size-1;
        while(index>=0){
            int maximum = 0 ;
            for(int i = index+1 ; i <= size ; ++i){
                if(nums[index]>nums[i]){
                    maximum = max(maximum,dynamic2[i]);
                }
            }
            dynamic2[index] += maximum ; 
            index--;
        }
        for(int i = 0 ; i <= size ; ++i){
            cout<<dynamic1[i]<<" ";
        }
        cout<<endl;

        for(int i = 0 ; i <= size ; ++i){
            cout<<dynamic2[i]<<" ";
        }
        cout<<endl;

        int max = 0 ;
        
        int min = size+1 ; 
        for(int i = 1 ; i <size ; ++i){
            if(dynamic1[i]>1 && dynamic2[i]>1){
                int x = dynamic1[i]+dynamic2[i] ; 
                
                x = size-x+1 ; 
                cout<<x<<endl;
                if(x<min){
                    min = x ; 
                }
            }
        } 
        return min==size+1?0:min+1 ;
    }
};
