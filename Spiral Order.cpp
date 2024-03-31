#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int downToUp = 1 ; 
    int upToDown = matrix.size()-1 ; 
    int leftToRight = matrix[0].size()-1 ; 
    int rightToLeft = 0 ;
    int size = (upToDown+1) * (leftToRight+1) ; 
    bool l = true , r = false , b = false , u = false ;
    int row = 0 ; 
    int column = 0 ; 
    vector<int> ans;

    for(int i = 0 ; i < size ; ++i)
    {
        if(l){
            if(column == leftToRight){
                ans.push_back(matrix[row][column]) ; 
                leftToRight-- ; 
                row++ ; 
                l = false ; 
                b = true ; 
            }
            else{
                ans.push_back(matrix[row][column++]) ; 
            }
        }
        else if(r){
            if(column == rightToLeft){
                ans.push_back(matrix[row][column]);
                rightToLeft++ ; 
                row-- ; 
                r = false ; 
                u = true ;
            }
            else{
                ans.push_back(matrix[row][column--]) ; 
            }

        }
        else if(b){
            if(row == upToDown){
                ans.push_back(matrix[row][column]);
                column-- ; 
                upToDown-- ; 
                b = false ; 
                r = true ;
            }
            else {
                ans.push_back(matrix[row++][column]) ;
            }
        }
        else if(u){
            if(row == downToUp){
                ans.push_back(matrix[row][column]); 
                column++ ; 
                downToUp++ ;
                u = false ; 
                l = true ;
            }
            else {
                ans.push_back(matrix[row--][column]) ; 
            }

        }
    } 
    return ans ; 
    }
};
int main(){
    vector<vector<int>> matrix = {{1,2,3,4,5},
                                 {6,7,8,9,10},
                                 {11,12,13,14,15},
                                 {16,17,18,19,20},
                                 {21,22,23,24,25}};
    Solution s ; 
    vector<int> result = s.spiralOrder(matrix) ; 
    for(int i : result){
        cout<<i<<endl;
    }
    
}
