#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> A) {
    for(int i : A)
        cout<<i<<" ";
}

vector<int> merge(vector<int> A, int l, int m, int r) {
    vector<int> temp = A;
    int i = l, j = m + 1, k = l;
    // cout<<endl<<"------------------------------------"<<endl;
    // for(int x = l; x <= r; x++)
    //     cout<<A[x]<<" ";
    // cout<<endl;

    while(i <= m && j <= r) {
        if(A[i] <= A[j])
            temp[k++] = A[i++];
        else    
            temp[k++] = A[j++];
    }

    while(i <= m)
        temp[k++] = A[i++];
    
    while(j <= r)
        temp[k++] = A[j++];
    
    // printArray(temp);
    // cout<<"------------------------------------";
    return temp;
}

void mergeSort(vector<int>& A) {
    int n = A.size(), k;
    
    // bottom up approach
    for(k = 2; k <= n; k *= 2) {    //size for merging 
        for(int i = 0; i+k-1 < n; i += k) {
            int l = i, r = i+k-1, m = (l+r) / 2;

            A = merge(A, l, m, r);
        }
    }
    if(k/2 < n)
        A = merge(A, 0, k/2, n-1);

}

int main() {
    vector<int> A = {5,14,-1,7,23,14,44,1312,42,-1,0,0,11,10,99,100};
  
    cout << "Array before sorting: \n";
    printArray(A);
  
    mergeSort(A);
  
    cout << "\n\nArray after sorting: \n";
    printArray(A);

    return 0;
}