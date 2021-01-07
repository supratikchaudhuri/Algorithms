#include<bits/stdc++.h> 
using namespace std; 
  
// Function to calculate sum of absolute difference 
// of all pairs in array 
// arr[]  --> array of elements 
int sumPairs(int arr[],int n) 
{ 
    // final result 
    int sum = 0; 
    for (int i=n-1; i>=0; i--) 
        sum += i*arr[i] - (n-1-i)*arr[i]; 
    return sum; 
} 
  
// Driver program to run the case 
int main() 
{ 
    int arr[] = {1, 8, 9, 15, 16}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << sumPairs(arr, n); 
    return 0; 
} 