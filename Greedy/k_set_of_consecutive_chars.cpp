// LC1296 Divide Array in Sets of K Consecutive Numbers
#include<bits/stdc++.h>
using namespace std;
//
class Solution {
    public:
    vector<vector<int>> isPossibleDivide(vector<int>& nums, int k) {
        
        if(nums.size()%k != 0) return {{}};
        vector<vector<int>> res;
        map<int, int> map;
        for(int i : nums)   //logn
            map[i]++;
        
        for(auto it : map){//n
            if(it.second > 0) { 
                int freq = it.second;
                int val = it.first;
                vector<int> vec;

                for(int i = val; i < val+k; i++) {//k but ignore as its only loop on char left in the nums
                    if(map[i] < freq)   //if 2 appears 2 times then 3 also has to appear atleast 3 times
                        return {{}};
                    else{
                        vec.push_back(i);
                        map[i] -= freq;
                    }
                }
                for(int i = 0; i < freq; i++)
                    res.push_back(vec);
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {2,3,4,5,3,4,5,6,4,5,6,7,1,2,3,4,1,2,3,4,7,8,9,10,7,8,9,10};
    int k = 4;
    Solution ob;
    auto res = ob.isPossibleDivide(nums, k);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < k; j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}