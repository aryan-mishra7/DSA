class Solution {
private:
bool issafe(int row,int col,vector<string>&board,int n){
    int temprow = row;
    int tempcol = col;
    //check upperdiagonal;
    while(temprow>=0&&tempcol>=0){
        if(board[temprow][tempcol]=='Q')
        return false;
        temprow--;
        tempcol--;
        //for upper diagonal both row and col decrease
    }
    //check left row
    temprow = row;
    tempcol = col;
    while(tempcol>=0){
        if(board[temprow][tempcol]=='Q')
        return false;
        tempcol--;
        //for left col only col decreases
    }
    //check lower left diagonal
    temprow = row;
    tempcol = col;
    while(temprow<n&&tempcol>=0){
        if(board[temprow][tempcol]=='Q')
        return false;
        temprow++;
        tempcol--;
    }
    return true;

}
void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row = 0;row<n;row++){
        if(issafe(row,col,board,n)){
            board[row][col] = 'Q';
            solve(col+1,board,ans,n);
            board[row][col]='.';
        }
    }
}
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        solve(0,board,ans,n);
        return ans;
    }
};
/*we only need to check the upper left diagonal , left col and lower left diagonal in issafe function because we have not yet filled the right side of board with a queen 
henche we have to only check whether there is a queen on anywhere left side of board*/