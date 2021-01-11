#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
    bool isValid(vector<string>& board, int row, int col, int n) {
        //check if col already has a queen or not
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q')
                return false;
        }
        
        //check if 45 deg diagonal has queen pt not
        for(int i = row-1, j = col+1; i >= 0 and j < n; i--, j++)
            if(board[i][j] == 'Q')
                return false;
        
        //checkng if 135deg fiagnol has a Q or not
        for(int i = row-1, j = col-1; i >= 0 and j >= 0; i--, j--)
            if(board[i][j] == 'Q')
                return false;
        
        return true;
    }
    
    void rec(vector<vector<string>>& res, vector<string> board, int row, int n) {
        if(row == n) {
            res.push_back(board);
            return;
        }
        
        for(int col = 0; col < n; col++) {
            //checking to see if a queen at board[row][col] is valid or not ±
            if(isValid(board, row, col, n)) {
                board[row][col] = 'Q';
                rec(res, board, row+1, n);
                board[row][col] = '_';
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board (n, string(n, '_'));
        rec(res, board, 0, n);
        return res;
    }
};

int main() {
    Solution ob;
    int n;
    cout<<"Enter n for n*n queen chessboard"<<endl;
    cin >> n;

    vector<vector<string>> res= ob.solveNQueens(n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            cout<< res[i][j] << endl;
        }
        cout<<"--------------------------------------"<<endl;
    }
    return 0;
}