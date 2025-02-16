class Solution {
    public:
        int s ;
        int count = 0 ;
        int value ;
        int size;

        bool check(int index, int value, vector<int> &result){
            return index+value>=size?false:result[index+value]!=-1?false:true;
        }

        bool solve(vector<int> &result, vector<bool> &track, int index){
            if(index>=size){
                return count == s ; 
            }
            if(index<size && result[index]!=-1){
                return solve(result,track,index+1);
            }
            vector<bool> maps(s,false);
            for(int i = value ; i>=1 ; --i){
                if(result[index]==-1 && !track[i] && !maps[i] && (i!=1?index+i<size:true) && (i!=1?result[index+i]==-1:true)){
                    result[index] = i;
                    if(i!=1)result[index+i] = i;
                    track[i] = true ; 
                    count++; 
                    if(solve(result,track,index+1)){
                        return true;
                    }
                    else{
                        result[index] = -1;
                        if(i!=1)result[index+i] = -1;
                        track[i] = false;
                        maps[i] = true;
                        count--;
                        i = value+1;
                    }
                }
            }
            return count==s;   
        }
        
        vector<int> constructDistancedSequence(int n) {
            if(n==1) return {1};
            s = n;
            value = n;
            size = 1+(n-1)*2;
            vector<int> result(size,-1);
            vector<bool> track(size,false);
            solve(result,track,0);
            return result;
        }
};
