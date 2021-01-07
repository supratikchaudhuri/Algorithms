#include<bits/stdc++.h>
using namespace std;

struct item {
    int val;
    int array;
    int idx;
};

class Solution {
public:
    vector<int> mergeKarrays(vector<vector<int>>& arrays) {

        auto comp = [](item a, item b){
            return a.val > b.val;
        };

        if(arrays.empty())
            return {};

        priority_queue<item , vector<item>, decltype(comp)> pq(comp); 

        for(int i = 0; i < arrays.size(); i++) {
            item it;
            it.val = arrays[i][0];
            it.array = i;
            it.idx = 0;

            pq.push(it);
        }

        // if(pq.empty())
        //     return {};

        vector<int> res;
        while(!pq.empty()) {
            item curr = pq.top(); pq.pop();
            int val = curr.val;
            int array = curr.array;
            int idx = curr.idx;

            res.push_back(val);

            if(arrays[array].size() > idx+1){
                item to_push;
                to_push.idx = idx+1;
                to_push.array = array;
                to_push.val = arrays[array][idx+1];
                pq.push(to_push);
            }
        }

        return res;
    }
};

int main () {

    vector<vector<int>> arrays = {{2,5,8,14}, {1,3,4,20}, {6}, {7, 22}};

    Solution ob;
    cout<<"Result: "<<endl;
    vector<int> res = ob.mergeKarrays(arrays);
    for(auto i : res)
        cout<< i << "  ";

    return 0;
}


// #include <bits/stdc++.h> 
// using namespace std; 
  
// // A pair of pairs, first element is going to 
// // store value, second element index of array 
// // and third element index in the array. 
// typedef pair<int, pair<int, int> > ppi; 
  
// // This function takes an array of arrays as an 
// // argument and all arrays are assumed to be 
// // sorted. It merges them together and prints 
// // the final sorted output. 
// vector<int> mergeKArrays(vector<vector<int> > arr) 
// { 
//     vector<int> output; 
  
//     // Create a min heap with k heap nodes. Every 
//     // heap node has first element of an array 
//     priority_queue<ppi, vector<ppi>, greater<ppi> > pq; 
  
//     for (int i = 0; i < arr.size(); i++) 
//         pq.push({ arr[i][0], { i, 0 } }); 
  
//     // Now one by one get the minimum element 
//     // from min heap and replace it with next 
//     // element of its array 
//     while (pq.empty() == false) { 
//         ppi curr = pq.top(); 
//         pq.pop(); 
  
//         // i ==> Array Number 
//         // j ==> Index in the array number 
//         int i = curr.second.first; 
//         int j = curr.second.second; 
  
//         output.push_back(curr.first); 
  
//         // The next element belongs to same array as 
//         // current. 
//         if (j + 1 < arr[i].size()) 
//             pq.push({ arr[i][j + 1], { i, j + 1 } }); 
//     } 
  
//     return output; 
// } 
  
// // Driver program to test above functions 
// int main() 
// { 
//     // Change n at the top to change number 
//     // of elements in an array 
//     vector<vector<int> > arr{ { 2, 6, 12 }, 
//                               { 1, 9 }, 
//                               { 23, 34, 90, 2000 } }; 
  
//     vector<int> output = mergeKArrays(arr); 
  
//     cout << "Merged array is " << endl; 
//     for (auto x : output) 
//         cout << x << " "; 
  
//     return 0; 
// } 