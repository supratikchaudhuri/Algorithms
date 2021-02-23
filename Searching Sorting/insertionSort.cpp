#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n) {
	for(int i = 1; i < n; i++)
	{
		int j=i;
		while( j > 0 && arr[j] < arr[j-1])
		{
			swap(arr[j], arr[j-1]);
			j--;
		}
	}
}

int main () {
    int arr[] = {5,8,2,5,8,0,2,3,67,23,45,78,12,45,76};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    for(int i = 0; i < n; i++)
        cout<<arr[i]<<"  ";
}