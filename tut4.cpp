//same as partition euqal subsets
#include<bits/stdc++.h>
using namespace std;


class Solution {
public :

    void printSubArray(vector<int> subarr) {
        for(int i : subarr) {
            cout<< i<<" ";
        }
        cout<<endl;
    }

    void rec(vector<int>& arr, int target, int i, int n, vector<int> subarr,vector<vector<int>>& res) {
        if(i > n) return;

        if(target == 0) {
            res.push_back(subarr);
        }
        
        //include current element in sum
        subarr.push_back(arr[i]);
        rec(arr, target - arr[i], i+1, n, subarr, res);

        //exclude current element from sum
        subarr.pop_back();
        rec(arr, target, i+1, n, subarr, res);
    }

    void subsetSum(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        rec(arr, target, 0, arr.size(), {}, res);
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout<<"Enter elements of array: \n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout<<"Enter subset Sum you want to find: ";
    cin >> target;

    Solution ob;
    ob.subsetSum(arr, target, 0, n, {});
}