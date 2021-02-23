#include<bits/stdc++.h>
using namespace std;

// https://www.spoj.com/problems/AGGRCOW/
bool valid(vector<int>& pos, int mid, int c) {
    int cows_placed = 1, last_pos =pos[0];
    for(int i = 1; i < pos.size(); i++) {
        if((pos[i] - last_pos) >= mid) {
            last_pos = pos[i];
            cows_placed++;

            if(cows_placed == c)
                return true;
        }
    }
    return false;
}

void solve() {
    int n, c; cin >> n >> c;
    vector<int> pos(n);

    for(int i = 0; i < n; i++)
        cin >> pos[i];

    sort(pos.begin(), pos.end());

    int lo = 1, hi = 1e9, min_dist = -1;

    while(lo < hi) {
        int mid = lo + (hi-lo) / 2;

        if(valid(pos, mid, c)) {
            min_dist = mid;
            lo = mid+1;
        }
        else
            hi = mid;
    }
    cout << min_dist << endl;
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}