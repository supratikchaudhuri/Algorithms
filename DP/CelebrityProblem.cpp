#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool knows(int a, int b, vector<vector<int>>& arr) {
        return arr[a][b];
    }

    int findCelebrity(vector<vector<int>>& arr) {
        int n = arr.size();

        int candidate = 0;
        for(int i = 0; i < n; i++) {
            if(knows(candidate, i, arr))
                candidate = i;
        }

        for(int i = 0; i < n; i++) 
            if(i != candidate && (knows(candidate, i, arr) || !knows(i, candidate, arr)))
                return -1;
        
        return candidate;
    }
};

int main() {
    vector<vector<int>> arr = { {0, 0, 1, 0}, 
                                {0, 0, 1, 0}, 
                                {0, 0, 0, 0}, 
                                {0, 0, 1, 0} };

    Solution ob;
    int id = ob.findCelebrity(arr);
    id == -1 ? cout<< "No celebrity" : cout<< "Celebrify ID: " << id;
    return 0;
}