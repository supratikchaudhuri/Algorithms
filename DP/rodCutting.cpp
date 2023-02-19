//same as discrete knapsack
#include<bits/stdc++.h>
// #include<vector>
using namespace std;

int rodCut(vector<int>& price, int n) {
    vector<int> dp(n+1, 0);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], price[j] + dp[i-j]);
        }
    }
    
    return dp[n];
}

// int rodCut(vector<int>& price, int n) {
//     vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <= n; j++) {
//             dp[i][j] = dp[i-1][j];

//             if(i <= j)
//                 dp[i][j] = max(dp[i-1][j], price[i] + dp[i][j - i]);
//         }
//     }

//     return dp[n][n];
// }

int main() {
    // price of the lenght = index  len1 = 2, len4 = 1, etc
    vector<int> price = {0,2,7,10,11,12};
    cout<<rodCut(price, 5);
    return 0;
}