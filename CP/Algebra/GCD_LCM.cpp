#include<bits/stdc++.h> 
using namespace std; 

void gcd_lcm(int a, int b) {
    int gcd;
    long long aa = a, bb = b, lcm;

    while(b) {
        a %= b;
        swap(a, b);
    }
    gcd = a;

    lcm = aa*bb / gcd;
    
    cout<<gcd<<" "<<lcm<<endl;
}

int main() 
{ 
    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        gcd_lcm(a, b); 
    }
    return 0; 
} 