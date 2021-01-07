// Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d > b.


#include<bits/stdc++.h>
using namespace std;

#define N 5

int specificPair(int arr[N][N]) {
    int maxArr[N][N];
    maxArr[N-1][N-1] = arr[N-1][N-1];
    //preprocess last row
    int maxval = maxArr[N-1][N-1];
    for(int j = N-2; j >= 0; j--) {
        maxval = max(maxval, arr[N-1][j]);
        maxArr[N-1][j] = maxval;
    }
    //preprocess last col
    maxval = maxArr[N-1][N-1];
    for(int i = N-2; i >= 0; i--) {
        maxval = max(maxval, arr[i][N-1]);
        maxArr[i][N-1] = maxval;
    }
    
    int res = INT_MIN;
    for(int i = N-2; i >= 0; i--){
        for(int j = N-2; j >= 0; j--){
            res = max(res, maxArr[i+1][j+1] - arr[i][j]);
            maxArr[i][j] = max(arr[i][j], max(maxArr[i+1][j], maxArr[i][j+1]));
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++){
            cout<<maxArr[i][j]<<"  ";
        }
        cout<<endl;
    }
    return res;
}

int main() {
    
    int arr[N][N] = {{ 1, 2, -1, -4, -20 },
                    { -8, -3, 4, 2, 1 }, 
                    { 3, 8, 6, 1, 3 },
                    { -4, -1, 1, 7, -6 },
                    { 0, -4, 10, -5, 1 }};

    int res = specificPair(arr);

    cout<<res;
    
    return 0;
}