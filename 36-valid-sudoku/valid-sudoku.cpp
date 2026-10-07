class Solution {
private:
private:
bool isvalid(int row,int col,vector<vector<char>>&board,char c){
    for(int i=0;i<9;i++){
        if(i!=row&&board[i][col]==c)
        return false;
        if(i!=col&&board[row][i]==c)
        return false;
        int r = 3*(row/3)+i/3;
        int co = 3*(col/3)+i%3;
        if((r!=row||co!=col)&&board[r][co]==c)
        return false;
    }
    return true;
}
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int cnt = 0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.'){
                    char ch = board[i][j];
                    if(isvalid(i,j,board,ch)){
                        cnt++;
                    }
                    else
                    return false;
                }
            }
        }
        return true;
    }
};