#include<bits/stdc++.h>
using namespace std;

vector<vector<double>>  countIntervals(vector<double>& A) {
    vector<vector<double>> res;
    double start = A[0];
    double intervalEnd = A[0];
    int intervals = 1;

    for(int i = 1 ; i < A.size(); i++) {
        if(A[i] <= start + 1) {
            intervalEnd = A[i];
        }
        else {
            res.push_back({start, intervalEnd});
            start = A[i];
        }
    }
    res.push_back({start, intervalEnd});
    return res;
}

int main() {
    vector<double> A = {-4,-3.8,-3.5,-3,0,0.5,2,3};

    auto intervals = countIntervals(A);

    for(auto i: intervals)
        cout<<i[0]<<" "<<i[1]<<endl;

    return 1;

}