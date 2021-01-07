#include<bits/stdtr1c++.h>
using namespace std;

vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,-1}, {0,1}};

//TRY SEATCHING IN ONLY A SIGLE DIRECTION
void countWord(vector<vector<char>>& arr, int i, int j, string& str, int& count, int start, string cur) {
    if(arr[i][j] != str[start])
        return;
    
    cur += arr[i][j];
    cout<<cur<<endl;
    if(cur == str)
        count++;    

    for(auto dir : dirs) {
        int new_i = i + dir[0];
        int new_j = j + dir[1];

        if(new_i >= 0 and new_i < arr.size() and new_j >= 0 and new_j < arr[0].size()){
            countWord(arr, new_i, new_j, str, count, start+1, cur);
        }
    }
    
}

int main() {

    // vector<vector<char>> a ={{'D','D','D','G','D','D'},
    //                         {'B','B','D','E','B','S'},
    //                         {'B','S','K','E','B','K'},
    //                         {'D','D','D','D','D','E'},
    //                         {'D','D','D','D','D','E'},
    //                         {'D','D','D','D','D','G'}};
    vector<vector<char>> a ={{'B','B','M','B','B','B'},
                                {'C','B','A','B','B','B'},
                                {'I','B','G','B','B','B'},
                                {'G','B','I','B','B','B'},
                                {'A','B','C','B','B','B'},
                                {'M','C','I','G','A','M'}};

    string str = "MAGIC";
    int count = 0;
    string cur = "";
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[0].size(); j++) {
            countWord(a, i, j, str, count, 0, cur);
        }
    }   

    cout<<count<<endl;

    return 0;
}