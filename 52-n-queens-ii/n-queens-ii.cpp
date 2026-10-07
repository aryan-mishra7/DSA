class Solution {
private:
bool issafe(int row,int col, vector<string> &board,int n){
    int temprow = row;
    int tempcol = col;
    //upper diagonal check karo
    while(temprow>=0&&tempcol>=0){
        if(board[temprow][tempcol]=='Q')
        return false;
        temprow--;
        tempcol--;
    }
    //check left col
    tempcol = col;
    temprow  = row;
    while(tempcol>=0){
        if(board[temprow][tempcol]=='Q')
        return false;
        tempcol--;
    }
    tempcol = col;
    temprow = row;
    while(temprow<n&&tempcol>=0){
        if(board[temprow][tempcol]=='Q')
        return false;
        temprow++;
        tempcol--;
    }
    return true;
}
void solve(int col,vector<string> &board,int &cnt,int n){
    if(col==n){
        cnt++;
        return;
    }
    for(int row = 0;row<n;row++){
        if(issafe(row,col,board,n)){
            board[row][col]='Q';
            solve(col+1,board,cnt,n);
            board[row][col]='.';
        }
    }
}
public:
    int totalNQueens(int n) {
        int cnt = 0;
        string s(n,'.'); 
        vector<string> board(n);
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        solve(0,board,cnt,n);
        return cnt;
    }
};