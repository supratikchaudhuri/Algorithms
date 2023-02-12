#include<bits/stdc++.h>
using namespace std;

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
        
        vector<int> temp;
        temp.push_back(A[0]);
        
        for(int i = 1; i < n; i++) {
            if(A[i] > temp.back())
                temp.push_back(A[i]);
            else {
                int idx = lower_bound(temp, 0, temp.size()-1, A[i]);
                temp[idx] = A[i];
            }
        }

        vector<int> res(temp.size(), 0);
        res[res.size()-1] = A[n-1];

        for(int i = n - 2, k = temp.size() - 1; i >= 0; i--) {
            if(A[i] >= res[k] and A[i] < res[k+1]) {
                res[k] = A[i];
                continue;
            }
            
            else    
                res[--k] = A[i];
        }

        return res;
    }
};

int main() {
    // vector<int> A = {2,5,7,1,2,3,4,8,6,10,2,13};
    // vector<int> A = {2,5,7,1,2,3,4,8,6,10,2,13};
    // vector<int> A = {2,5,7,1,2,3,4,8,6,10,2,13};
    vector<int> A = {2,5,7,1};
    Solution ob;
    vector<int> res = ob.LIS(A);

    for(int i : res)
        cout<<i<<" ";

    return 0;
}