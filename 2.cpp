#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
   int n; cin >> n;
   vector<int> arr(n);
   for(int i = 0; i < n; i++)
      cin >> arr[i];

   vector<ll> dp(n);
   dp[0] = arr[0];

   for(int i = 0; i < n; i++) {
      if(i + arr[i] < n)
         dp[i+arr[i]] = max(dp[i+arr[i]], max(dp[i], (ll)arr[i]) + arr[i+arr[i]]);
      if(i > 0)
         dp[i] = max(dp[i], max((ll)arr[i], dp[i-1]));
   }
   cout<<dp[n-1]<<endl;
}

int main() {
   int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}