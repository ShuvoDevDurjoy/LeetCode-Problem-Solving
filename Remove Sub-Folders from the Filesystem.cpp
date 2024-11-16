class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans ; 
        sort(folder.begin(),folder.end()) ; 
        int size = folder.size() ; 
        ans.push_back(folder[0]) ; 
        int ansSize = 0 ; 
        int position = 0 ; 
        for(int i = 1 ; i < size ; ++i){
            int position = folder[i].find(ans[ansSize]) ; 
            if(position == -1){
                ans.push_back(folder[i]) ; 
                ansSize++ ; 
            }
            else if(position==0 && folder[i][ans[ansSize].length()]!='/'){
                ans.push_back(folder[i]) ; 
                ansSize++;
            }
            else if(position != 0){
                ans.push_back(folder[i]) ; 
                ansSize++;
            }
        }
        return ans ; 

    }
};
