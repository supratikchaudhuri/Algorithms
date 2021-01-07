//Recursively print all sentences that can be formed from list of word lists
#include<bits/stdc++.h>
using namespace std;

void rec(vector<string>& res, string cur, int i, vector<vector<string>> &ip) {
    if(i == ip.size()) {
        res.push_back(cur);
        return;
    }

    for(int j = 0; j < ip[i].size(); j++) {
        cur += ip[i][j];
        rec(res, cur + " ", i+1, ip);
        int s = ip[i][j].size();
        cur = cur.substr(0, cur.size()-s);
    }
} 

vector<string> strs(vector<vector<string>> &ip) {
    vector<string> res;
    rec(res, "", 0, ip);

    return res;
}

int main(){
    vector<vector<string>> ip = {{"you", "we"},
                                {"have", "are"},
                                {"sleep", "eat", "drink"}};

    vector<string> res = strs(ip);

    for(auto s : res)
        cout<<s<<endl;
    
    return 0;
}




// #include <iostream>
// #include <string>
 
// #define R 3
// #define C 3
// using namespace std;
 
// // A recursive function to print all possible sentences that can be formed
// // from a list of word list
// void printUtil(string arr[R][C], int m, int n, string output[R])
// {
//     // Add current word to output array
//     output[m] = arr[m][n];
 
//     // If this is last word of current output sentence, then print
//     // the output sentence
//     if (m==R-1)
//     {
//         for (int i=0; i<R; i++)
//            cout << output[i] << " ";
//         cout << endl;
//         return;
//     }
 
//     // Recur for next row
//     for (int i=0; i<C; i++)
//        if (arr[m+1][i] != "")
//           printUtil(arr, m+1, i, output);
// }
 
// // A wrapper over printUtil()
// void print(string arr[R][C])
// {
//    // Create an array to store sentence
//    string output[R];
 
//    // Consider all words for first row as starting points and
//    // print all sentences
//    for (int i=0; i<C; i++)
//      if (arr[0][i] != "")
//         printUtil(arr, 0, i, output);
// }
 
// // Driver program to test above functions
// int main()
// {
//    string arr[R][C]  = {{"you", "we"},
//                         {"have", "are"},
//                         {"sleep", "eat", "drink"}};
 
//    print(arr);
 
//    return 0;
// }