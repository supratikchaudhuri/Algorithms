// O(n^3)........needs to have atleast 1 positive elemnt
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> kadane(vector<int>& nums, int n) {
        vector<int> res(3, 0);  //[sum, up, down]
        int cursum = nums[0], maxsum = nums[0], left = 0, right = 0;

        for(int i = 1; i < n; i++) {
            if(nums[i] > cursum + nums[i]){
                left = i;
                cursum = nums[i];
            }
            else {
                cursum += nums[i];
            }

            if(cursum > maxsum) {
                maxsum = cursum;
                right = i;
            }
        }
        return {maxsum, left, right};
    }

    public:
    void findMaxSum(vector<vector<int>>& arr) {
        int rows = arr.size(), cols = arr[0].size();

        int left = 0, right = 0, finalleft = 0, finalright = 0, finalup = 0, finaldown = 0, sum = INT_MIN;
        
        for(left = 0; left < cols; left++) {
            vector<int> temp(rows, 0);
            for(right = left; right < cols; right++) {
                for(int i = 0; i < rows; i++) {
                    temp[i]  += arr[i][right];
                    cout<<temp[i]<<" ";
                }
                cout<<endl;

                vector<int> v = kadane(temp, rows);

                if(v[0] > sum) {
                    sum = v[0];
                    finalleft = left;
                    finalright = right;
                    finalup = v[1];
                    finaldown = v[2];
                }
            }
        }
        cout<<"MAXSUM = "<< sum <<endl;
        // cout<< finalup<<" "<< finaldown<<" "<< finalleft<<" "<< finalright <<" "<< endl;
        for(int i = finalup; i <= finaldown; i++) {
            for(int j = finalleft; j <= finalright; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    Solution ob;

    vector<vector<int>> arr = { { 1, 2, -1, -4, -20 },
						        { -8, -3, 4, 2, 1 },
						        { 3, 8, 10, 1, 3 },
						        { -4, -1, 1, 7, -6 } };
    
    ob.findMaxSum(arr);
    return 0;
}