#include<bits/stdc++.h>
using namespace std;

//O(2^n)
int knapsack(int weights[], int profits[], int w, int i) {
    if(w == 0 || i < 0)
        return 0;

    if(weights[i] > w)
        return knapsack(weights, profits, w, i-1);//we skip this item

    else {
        //either include current profit or exclude it hoping to get more profit in future
        return max(profits[i] + knapsack(weights, profits, w-weights[i], i-1), 
                    knapsack(weights, profits, w, i-1));
    } 
}

//O(n*w)
int knapsackMEMO(int weights[], int profits[], int w, int i, vector<vector<int>> &memo) {
    if(w == 0 || i == 0)
        return 0;

    if(memo[i][w] != -1) return memo[i][w];

    int res;

    if(weights[i-1] > w)
        res = knapsackMEMO(weights, profits, w, i-1, memo);//we skip this item

    else {
        //either include current profit or wxcule it hoping to get more profit in future
        res = max(profits[i-1] + knapsackMEMO(weights, profits, w-weights[i-1], i-1, memo), 
                    knapsackMEMO(weights, profits, w, i-1, memo));
    }
    return memo[i][w] = res;
}

//O(n*w)
int knapsackDP(vector<int> weights, vector<int> profits, int w, int n, vector<vector<int>> &dp) {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= w; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = 0;

            else if(weights[i-1] > j)
                dp[i][j] = dp[i-1][j];//skip this element

            else 
                dp[i][j] = max(dp[i-1][j], profits[i-1] + dp[i-1][j-weights[i-1]]);
        }
    }
    return dp[n][w];
}
 

int main () {

    int n = 4, w = 21;
    vector<int> weights = {6,3,5,9};
    vector<int> profits = {18,20,14,18};

    cout<< "Max Profit: " << knapsack(weights, profits, w, n-1) << "\n";

    vector<vector<int>> memo(n+1, vector<int> (w+1, -1));
    knapsackMEMO(weights, profits, w, n, memo);
    cout<< "Max Profit: " << memo[n][w] << "\n";

    vector<vector<int>> dp(n+1, vector<int> (w+1));
    knapsackDP(weights, profits, w, n, dp);
    cout<< "Max Profit: " << dp[n][w];
}