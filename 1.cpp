#include<bits/stdc++.h>
#include<unordered_set>
#include<string>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> set(deadends.begin(), deadends.end());
        unordered_set<string> vis;
        int res = 0;
        if(target == "0000") return res;
        queue<string> q;
        q.push("0000");

        while(!q.empty()) {
            string s = q.front(); q.pop();
            vis.insert(s);

            for(int i = 0; i < 4; i++) {
                string s1 = s, s2 = s;
                s1[i] = (((s1[i] - '0') - 1) % 10) + '0';
                s2[i] = (((s1[i] - '0') + 1) % 10) + '0';

                if(s1 == target || s2 == target)
                    return res + 1;

                if(set.find(s1) == set.end() and vis.find(s1) == vis.end())
                    q.push(s1);
                if(set.find(s2) == set.end() and vis.find(s2) == vis.end())
                    q.push(s2);
            }
            res++;
        }

        return -1;
    }
};

int main() {
    string target = "0202";
    vector<string> A = {"0201","0101","0102","1212","2002"};
    Solution ob;
    cout<<ob.openLock(A, target);
}


