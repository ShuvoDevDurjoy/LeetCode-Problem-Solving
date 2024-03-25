class Solution {
public:
bool checkRow(vector<vector<char>> &board){
    for(int i = 0 ; i < 9 ; ++i ){
    int check[9] = {0,0,0,0,0,0,0,0,0};
        for(int j = 0 ; j < 9 ; ++j ){
            if(board[i][j]=='.'){
                continue ; 
            }
            int num = board[i][j]-49 ; 
            if(check[num]!=0){
                return false ; ;
            }
            else {
                check[num] = 1 ; 
            }
        }
    }
    return true ; 
}

bool checkRow(vector<vector<char>> &board , int row , int column){
    int check[9] = {0,0,0,0,0,0,0,0,0};
    for(int i = row ; i <= row+2 ; ++i){
        for(int j = column ; j <= column+2 ; ++j){
            if(board[i][j] == '.') continue ; 
            int num = board[i][j]-49 ;
            if(check[num]!=0){
                return false ;
            }
            else {
                check[num] = 1 ; 
            }
        }
    }
    return true ; 
}


bool checkColumn (vector<vector<char>> &board){
    for(int i = 0 ; i < 9 ; i++){
    int check[9] = {0,0,0,0,0,0,0,0,0};
        for(int j = 0 ; j < 9 ; j++){
            if(board[j][i]=='.'){
                continue ; 
            }
            int num = board[j][i]-49 ; 
            if(check[num]!= 0){
                return false ; ;
            }
            else {
                check[num] = 1 ; 
            }
        }
    }
    return true ; 
}
bool isValidSudoku(vector<vector<char>> &board){
    if(!checkRow(board)) return false ;
    if(!checkColumn(board)) return false ;
    for(int i = 0 ; i < 9 ; i+=3){
        for(int j = 0 ; j < 9 ; j+=3){
            if(!checkRow(board,i,j)) return false ;
        }
    }
    return true ; 
}
};
