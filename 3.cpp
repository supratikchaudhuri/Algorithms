#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    priority_queue<int> odds, evens;
    for(int i : arr) {
        if(i & 1)
            odds.push(i);
        else
            evens.push(i);
    }

    ll alice = 0, bob = 0;
    int f = 1;
    while(!odds.empty() && !evens.empty()) {
        if(f) {
            if(evens.top() >=odds.top()) {
                alice += evens.top(); evens.pop();
            }
            else{
                odds.pop();
            }
        }
        else {
            if(evens.top() <= odds.top()) {
                bob += odds.top(); odds.pop();
            }
            else{
                evens.pop();
            }
        }
        f = !f;
    }

    while(!odds.empty()) {
        if(!f) 
            bob += odds.top();

        odds.pop();
        f = !f;
    }
    while(!evens.empty()) {
        if(f) 
            alice += evens.top();

        evens.pop();
        f = !f;
    }

    if(alice > bob)
        cout<< "Alice"<<endl;
    else if (alice == bob)
        cout<<"Tie"<<endl;
    else
        cout<<"Bob"<<endl;    
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}