#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        
        if(n == 0 or n == 1)
            return n;
        
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
    

        for(int l = 2; l <= n; l++){
            for(int i = 0; i < n - l + 1; i++){
                int j = i + l - 1;
                if(l == 2 and s[i] == s[j])
                    dp[i][j] = 2;
                
                else if(s[i] == s[j])
                    dp[i][j] = 2 + dp[i+1][j-1];
                
                else
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
        
        return dp[0][n-1];
    }
};

int main() {
    Solution ob;

    vector<int> arr;
    vector<vector<int>> vec;
    string s = "bbbab";
    cout<<ob.longestPalindromeSubseq(s);
    return 0;
}