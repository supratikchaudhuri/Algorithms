#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l-1;

    for(int j = l; j < r; j++) {
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);     //putting pivot at right place
    return i+1;
}

void quickSort(int arr[], int l, int r) {
    int pivot;
    if(l < r) {
        pivot = partition(arr, l, r); 
        quickSort(arr, l, pivot-1);
        quickSort(arr, pivot+1, r);
    }
}

int main () {

    int arr[] = {5,8,3,10,4,-9,2,45,37,1,3,5,89,35,76};
    quickSort(arr, 0, 14);

    for(int i = 0; i < 15; i++)
        cout<<arr[i]<<"\t";
    return 0;
}