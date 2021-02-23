#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    } 
}

int main () {
    int arr[] = {5,8,2,5,8,0,2,3,67,23,45,78,12,45,76};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    for(int i = 0; i < n; i++)
        cout<<arr[i]<<"  ";
}