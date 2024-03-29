#include<bits/stdc++.h>
using namespace std;
 
long long binpowmod(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while(b > 0) {
    if(b & 1)
      res = res * a%m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
 
int main(){
  long long n; cin >> n;
  long long mod = 1e9+7;
 
  long long a = 2;
 
  cout<<binpowmod(a, n, mod);
  return 0;
}