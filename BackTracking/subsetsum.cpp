#include<bits/stdc++.h>
using namespace std;



class Solution {
    public:
    void subsetSums(int arr[], int l, int r, int sum, int& count) {
        if(l > r) {
            cout<<sum <<" ";
            count++;
            return;
        }

        subsetSums(arr, l+1, r, sum+arr[l], count);//including arr[l] in sum
        subsetSums(arr, l+1, r, sum, count);//excuding arr[l] in sum
    }

    void subsetSumsItertive(int arr[], int n) { 
        long long total = 1<<n; 
    
        for (long long i=0; i<total; i++) { 
            long long sum = 0; 
    
            for (int j=0; j<n; j++) 
                if (i & (1<<j)) 
                    sum += arr[j];
        } 
    } 
};


int main() {
    int arr[] = {5,7,3,5,8,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int count = 0;
    Solution ob;
    cout<<"====================================="<<endl;
    ob.subsetSums(arr, 0, n-1, 0, count);
    cout<<"\nTotal count : "<< count;
    cout<<"\n====================================="<<endl;

    // ob.subsetSumsItertive(arr, n);
    return 0;
}