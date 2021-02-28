#include<bits/stdc++.h>
using namespace std;

//LC 1775...try to get the array,,,, inclomplete
//arrays should only have idgits from 1-6
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(6*m < n || 7*n < m) return -1;
        
        
        int sum1 = accumulate(begin(nums1), end(nums1), 0);
        int sum2 = accumulate(begin(nums2), end(nums2), 0);
        
        if(sum1 > sum2) 
            return minOperations(nums2, nums1);
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0, j = n-1;
        int diff = abs(sum2 - sum1), ops = 0;
        
        while(diff > 0) {
            if(j < 0 || 6 - nums1[i] > nums2[j] - 1) {
                if(diff >= 6 - nums1[i]) {
                    sum1 += 6 - nums1[i];
                    nums1[i] = 6;
                    
                }
                else {
                    sum1 += diff;
                    nums1[i] += diff;
                }
                i++;
            }
            else {
                if(6 - nums1[i] < nums2[j] - 1) {
                    sum2 -= nums2[j] - 1;
                    nums2[j] = 1;
                }
                else {
                    sum2 -= diff;
                    nums2[j] += diff;
                }
                j--;
            }
            diff = abs(sum2-sum1);
            ops++;
        }
        
        cout<<"sum1: "<<sum1<<endl;
        cout<<"sum2: "<<sum2<<endl;
        if(sum1 != sum2) {
            nums2[j] -= abs(sum1 - sum2);
        }
        return ops;
    }
};

void printarr(vector<int> nums) {
    for(int i : nums)
        cout<< i <<"  "; 
    cout<<endl;
}

int main() {
    vector<int> nums1 = {1,2,3,4,5,6}, nums2 = {1,1,2,2,2,2};
    Solution ob;
    cout<<ob.minOperations(nums1, nums2)<<endl;
    printarr(nums1);
    printarr(nums2);
    
    return 0;
}