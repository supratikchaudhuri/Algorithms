//to only ans yes/no use boyer moore voting technique
//to print the string use this technique

#include<bits/stdc++.h>
using namespace std;

void rearrange(string s) {
    int count[26] = {0};

    for(char ch : s){
        count[ch-'a']++;
    }

    priority_queue<pair<int, char>> pq;
    for(int i = 0; i < 26; i++){
        if(count[i] > 0){
            pq.push({count[i], i+'a'});
        }
    }

    string res = "";
    pair<int, char> prev = {-1, '~'};
    while(!pq.empty()) {
        auto p = pq.top(); pq.pop();

        res += p.second;

        if(prev.first > 0)
            pq.push(prev);

        p.first--;

        prev = p;
    }
    if(res.length() != s.length())
        cout<<"Not Possible";
    else 
        cout<<res<<endl;
}

int main() {

    cout<<"Enter string : ";
    string s; cin >>s;
    cout<<endl;

    rearrange(s);

    return 0;
}