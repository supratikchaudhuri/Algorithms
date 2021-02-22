#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1-i; j++) {
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

int main () {
    int arr[] = {5,8,2,5,8,0,2,3,67,23,45,78,12,45,76};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    for(int i = 0; i < n; i++)
        cout<<arr[i]<<"  ";
}