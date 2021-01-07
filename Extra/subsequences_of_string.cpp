#include<bits/stdc++.h>
using namespace std;

void rec(vector<string>& res, string curr, string s, int start) {
    res.push_back(curr);
    for(int i = start; i < s.length(); i++) {
        if(i > start and s[i] == s[i-1]) continue;

        curr += s[i];
        // res.push_back(curr);
        rec(res, curr, s, i+1);
        curr.pop_back();
    }
}

vector<string> subsequences(string &s) {
    if(s.length() == 0)
    return {};

    vector<string> res;
    string curr = "";
    rec(res, curr, s, 0);

    return res;
}

int main () {
    string s = "aaa";
    vector<string> res = subsequences(s);

    for(auto str : res)
    cout<<str<<endl;
    return 0;
}