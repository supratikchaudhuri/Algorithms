
#include<bits/stdc++.h>
using namespace std;

class Solution {

    void rec(vector<string>& res, string num, int start, int N) {
        if(num.size() == N) {
            res.push_back(num);
            return;
        }

        for(int i = start; i <= N; i++) {
            num += to_string(i);
            rec(res, num, i+1, N);
            num.pop_back();
        }
    }

    public :
    int kthpermutation(int N, int K) {
        vector<string> res;
        string num = "";
        rec(res, num, 1, N);
        cout<<"size: "<<res.size();
        int ret = stoi(res[K-1]);
        return ret;
    }
};

int main(){
    int N, K;
    cin >>N >> K;

    Solution ob;
    cout<<ob.kthpermutation(N, K);
    return 0;
}