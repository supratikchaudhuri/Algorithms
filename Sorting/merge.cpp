#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int r){
    int i = l, j = m+1, k = l;
    
    cout<<"doing :   ";     for(int s = l; s<= r; s++){
                                cout<<arr[s]<<"\t";
                            }
    //cout<<i<<"  "<<j;
    cout<<endl;
    int temp[7];

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

void mergeSort(int arr[], int l, int r){
    int m = (l+r) / 2;

    if(l < r){
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[7] = {6,3,5,4,1,7,2};

    mergeSort(arr, 0, 6);
    
    for(int i = 0; i < 7; i++){
        cout<< arr[i] <<"\t";
    }
    
    return 0;
}