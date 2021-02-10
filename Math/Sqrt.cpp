#include<bits/stdc++.h>
using namespace std;

int sqrt(int n) {
    if(n == 0 || n == 1) 
        return n;

    int l = 0, r = n, res = 0;
    while(l <= r) {
        int mid = (l+r) / 2;

        if(mid*mid == n)
            return mid;
        if(mid*mid < n) {
            res = mid;
            l = mid+1;
        }
        else   
            r = mid-1;
    }
    return res;
}

int main() {
    int n; cin >> n;
    cout << sqrt(n) << endl;
    return 0;
}