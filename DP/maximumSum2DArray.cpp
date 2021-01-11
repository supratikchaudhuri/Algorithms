#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void findMaxSum(vector<vector<int>>& arr) {
        int rows = arr.size(), cols = arr[0].size();

        int left = 0, right = 0, up = 0, down = 0;
        vector<int> temp;

        for(int left = 0; left < cols; left++) {
            temp.resize(rows, 0);
            for(int right = left; right < cols; right++) {
                for(int i = 0; i < rows; i++) {
                    temp[i]  += arr[i][right];
                }

                int sum = kadane(temp, up, down, rows);


            }
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