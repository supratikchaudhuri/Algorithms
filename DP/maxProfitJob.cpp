#include<bits/stdc++.h>
using namespace std;

// int bSearch(vector<vector<int>>& jobs, int i) {
//     int lo = 0, hi = jobs.size()-1;

//     while(lo < hi) {
//         int mid = (lo+hi)/2;

//         if(jobs[mid][1] <= jobs[i][0]) {
//             if(mid+1 < jobs.size() && jobs[mid+1][1] <= jobs[i][0])
//                 lo = mid+1;
//             else
//                 return mid;
//         }
//         else {
//             hi = mid;
//         }
//         return -1;
//     }
// }

int findMaxProfit(vector<vector<int>>& jobs) {
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), [](vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    });

    vector<int> dp(n, 0);
    dp[0] = jobs[0][2];

    for(int i = 1; i < n; i++) {
        int includeProfit = jobs[i][2];
        // int l = bSearch(jobs, i);
        //try  optimizing with bsearch
        for(int j = i-1; j >= 0; j--) {
            if(jobs[j][1] <= jobs[i][0]) {
                includeProfit += dp[j];
                break;
            }
        }
        dp[i] = max(dp[i-1], includeProfit);
    }
    return dp[n-1];
}

int main () {
    //[start, end, profit]
    vector<vector<int>> jobs = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}}; 
    // vector<vector<int>> jobs =  {{1, 1, 3}, {2, 2, 4}, {3, 3, 100}}; 
    // vector<vector<int>> jobs =  {{2,4, 4}, {3,6, 6}, {6, 8,2}, {5, 7,3}}; 
    int res = findMaxProfit(jobs);
    cout<<"Max Profit : " << res<<endl;

    return 0;
}