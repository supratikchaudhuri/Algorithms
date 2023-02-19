#include<bits/stdc++.h>
using namespace std;

void print(vector<int> & res) {
    for(int i : res)
        cout<<i<<" ";
    cout<<endl;
}

class Solution {
    
    int lower_bound(vector<int> arr, int l, int r, int x) {
        while(l < r) {
            int m = (l+r) / 2;
            
            if(arr[m] >= x)
                r = m;
            else
                l = m+1;
        }
        return l;
    }
    
public:
    vector<int> LIS(vector<int>& A) {
        int n = A.size();
        
        vector<int> temp, res;
        temp.push_back(A[0]);
        res = temp;
        
        for(int i = 1; i < n; i++) {
            if(A[i] > temp.back()) {
                temp.push_back(A[i]); 
                res = temp;
            }
            else {
                int idx = lower_bound(temp, 0, temp.size()-1, A[i]);
                temp[idx] = A[i];
            }
        }
        return res;
    }
};

int main() {

    vector<int> A, res;
    Solution ob;

    A = {0,1,0,3,2,3};
    res = ob.LIS(A);
    print(res);

    A = {2,5,7,1,2,3,4,8,6,10,2,13};
    res = ob.LIS(A);
    print(res);

    A = {2,5,7,1};
    res = ob.LIS(A);
    print(res);

    A = {7,7,7,7,7,7,7};
    res = ob.LIS(A);
    print(res);

    A = {4,6,8,1,13};
    res = ob.LIS(A);
    print(res);

    return 0;
}