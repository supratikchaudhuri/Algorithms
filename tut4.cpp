class Solution {
    unordered_set<int> set;

    void getPrimes(int n) {
        vector<bool> dp(n+1, 0);

        for(int i = 2; i <= n; i++) {
            if(dp[i] == false)
                continue;
                
            dp[i] = 1;
        }
    }
public:
    bool primeSubOperation(vector<int>& A) {
        
        int maxi = max_element(A.begin(), A.end());

        getPrimes(maxi)l
    }
};