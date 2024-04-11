class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int aS = 0 ; 
        int bS = 0 ; 
        vector<int> result(2,0) ; 
        for(int i = 0 ; i < aliceSizes.size() ; ++i){
            aS+=aliceSizes[i] ; 
        }
        for(int i = 0 ; i < bobSizes.size() ; ++i){
            bS +=bobSizes[i] ; 
        }
        cout<<"alice sum : "<<aS<<endl;
        cout<<"bob sum : "<<bS<<endl<<endl;
        unordered_map<int,int> maps ; 
        for(int i = 0 ; i < aliceSizes.size() ; ++i){
            maps[aliceSizes[i]] = 0 ; 
        }
        for(int i = 0 ; i < bobSizes.size() ; ++i){
            int temp = (aS-bS)/2+bobSizes[i] ; 
            cout<<"bob : "<<bobSizes[i]<<endl;
            cout<<"alice : "<<temp<<endl<<endl;
            if(maps.find(temp)!=maps.end())
            {
                result[0] = temp ; 
                result[1] = bobSizes[i] ; 
                return result ; 
            } 
        }
        return result; 
    }
};
