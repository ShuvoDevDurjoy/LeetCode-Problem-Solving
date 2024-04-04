class Solution {
public:
bool exist(vector<vector<char>> &board , string word , int wordsize ,  int level ,  int rowsize , int colsize , int row  , int col )
{
    if(level == wordsize ){
        return true ; 
    }
    if(row<0 || row > rowsize){
        return false ; 
    }
    else if(col<0 || col > colsize){
        return false ; 
    }


    bool l = false , r = false , u = false , d = false ; 
    if(board[row][col] == word[level])
    {
        char c = board[row][col] ; 
        board[row][col] = '#' ; 
    l = exist(board,word,wordsize,level+1,rowsize,colsize,row,col+1) ; 
    r = exist(board,word,wordsize,level+1,rowsize,colsize,row,col-1) ;
    u = exist(board,word,wordsize,level+1,rowsize,colsize,row-1,col) ;
    d = exist(board,word,wordsize,level+1,rowsize,colsize,row+1,col) ;
    board[row][col] = c ; 
    if(l||r||u||d){
        return true ; 
    }
    }
    return false ; 

}
    bool exist(vector<vector<char>>& board, string word) {
    for(int i = 0 ; i < board.size() ; ++i)
    {
        for(int j = 0 ; j < board[0].size() ; ++j){
            if(board[i][j] == word[0])
            {
                if(exist(board , word , word.length(), 0, board.size()-1 , board[0].size()-1,i,j))
                {
                    return true ; 
                }
            }
        }
    }
    return false ; 
    }
};
