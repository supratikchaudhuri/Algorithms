#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int r, int n){
    int i = l, j = m+1, k = l;
    
    // cout<<"doing :   ";     for(int s = l; s<= r; s++){
    //                             cout<<arr[s]<<"\t";
    //                         }
    // //cout<<i<<"  "<<j;
    // cout<<endl;
    int temp[n];

    while(i <=m and j <= r){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
        }
        else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i <= m){
        temp[k] = arr[i];
        k++;
        i++;
    }
    while(j <= r){
        temp[k] = arr[j];
        k++;
        j++;
    }

    for(int s = l; s <= r; s++){
        arr[s] = temp[s];
    }
}

void mergeSort(int arr[], int l, int r, int n){
    int m = (l+r) / 2;

    if(l < r){
        mergeSort(arr, l, m, n);
        mergeSort(arr, m+1, r, n);
        merge(arr, l, m, r, n);
    }
}

int main() {
    int arr[] = {5,8,2,5,8,0,-2,3,67,-23,45,78, 99,-99,-12,45,76};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    mergeSort(arr, 0, n-1, n);
    
    for(int i = 0; i < n; i++){
        cout<< arr[i] <<"\t";
    }
}