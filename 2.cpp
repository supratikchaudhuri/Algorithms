#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> denominations = {25, 10, 5, 1};

int coinChange(int n) {
   int coins = 0;
   int i = 0;
   while(n != 0) {
      while(n >= denominations[i]) {
         n -= denominations[i];
         coins++;
      }
      
      i++;
   }
   return coins;
}

int main() {
   cout<<coinChange(36)<<endl;
   cout<<coinChange(37)<<endl;
   cout<<coinChange(38)<<endl;
   cout<<coinChange(39)<<endl;
   cout<<coinChange(40)<<endl;
}