#include<bits/stdc++.h> 
  
using namespace std; 
  
long long moduloMultiplication(long long a, long long b, long long mod){ 
    long long res = 0; 
    a %= mod; 
    //a * b = a + a + … + a (b times)
    while (b) 
    { 
        if (b & 1) 
            res = (res + a) % mod; 
  
        a = (2 * a) % mod; 
        b >>= 1; 
    } 
  return res; 
}  
int main() 
{ 
    long long a = 10123465234878998; 
    long long b = 65746311545646431; 
    long long m = 1e16+7; 
    cout << moduloMultiplication(a, b, m); 
    return 0; 
} 