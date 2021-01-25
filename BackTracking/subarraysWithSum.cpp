//same as partition euqal subsets
#include<bits/stdc++.h>
using namespace std;

class Solution {

    void rec(vector<int> arr, int target, int start, vector<int> subarr, vector<vector<int>>& res) {
        if(start > arr.size()) return;

        if(target == 0) 
            res.push_back(subarr);

        for(int i = start; i <= arr.size(); i++) {
            if(i > start && arr[i] == arr[i-1]) continue; //to avoid duplicate subsets

            subarr.push_back(arr[i]);//including current element to the subarray
            rec(arr, target - arr[i], i+1, subarr, res);
            subarr.pop_back();//excluding current element from the subarray
        }
    }

public :
    vector<vector<int>> subsetSum(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        rec(arr, target, 0, {}, res);
        return res;
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
    vector<vector<int>> res = ob.subsetSum(arr, target);
    cout<<"\n---------------------------\n";

    for(int i = 0; i < res.size(); i++) {
        cout<< "Subarray " << i+1 << " :";
        for(int j = 0; j < res[i].size(); j++) {
            cout<<res[i][j] << " ";
        }
        cout<<endl;
    }
}