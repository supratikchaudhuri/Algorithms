#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n; cin >> n;vector<int> arr(n);    for(int i = 0; i < n; i++)
    cin >> arr[i];
    sort(arr.begin(), arr.end());
    ll a = 0, b = 0;for(int i = n-1; i >= 0; i--) {
        if(a < b)
            a += arr[i];
        else  
            b += arr[i];    }if(a == b)
 cout<<"YES"<<endl;else    cout<<"NO"<<endl;
    
}

int main()
 {
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
