#include <bits/stdc++.h> 
using namespace std;

struct Item { 
    int value, weight; 
  // Constructor 
    Item(int value, int weight) 
        : value(value) 
        , weight(weight) 
    {} 
}; 

bool cmp(struct Item a, struct Item b) {//value per item 
    double r1 = (double)a.value / (double)a.weight; 
    double r2 = (double)b.value / (double)b.weight; 
    return r1 > r2; 
} 


double fractionalKnapsack(int W, struct Item arr[], int n) { 
    sort(arr, arr + n, cmp); 
  
    int curWeight = 0; // Current weight in knapsack 
    double finalvalue = 0.0; // Result (value in Knapsack) 
  
    for (int i = 0; i < n; i++) { 
        if (curWeight + arr[i].weight <= W)  { 
            curWeight += arr[i].weight; 
            finalvalue += arr[i].value; 
        } 
 
        else { 
            int remain = W - curWeight; 
            finalvalue += (arr[i].value/ (double)arr[i].weight) * ((double)remain); 
            break; 
        } 
    } 

    return finalvalue; 
} 
  
// Driver code 
int main() { 
    int W = 45; //    Weight of knapsack 
    Item arr[] = { {22,24}, {37,15}, {14, 10}, {19, 8}, {15,11} };  
    // Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 }, { 40, 40 } };  
    // Item arr[] = { { 25,18 }, { 24,15 }, { 15,10 }};  
  
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // Function call 
    cout << "Maximum value we can obtain = "
         << fractionalKnapsack(W, arr, n); 
    return 0; 
}