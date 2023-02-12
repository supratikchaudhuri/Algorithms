#include<bits/stdc++.h>
using namespace std;

int countIntervals(vector<double>& A) {
    double start = A[0];
    int intervals = 1;

    for(int i = 1 ; i < A.size(); i++) {
        if(A[i] <= start + 1)
            continue;
        else {
            start = A[i];
            intervals++;
        }
    }
    return intervals;
}

int main() {
    vector<double> A = {-4,3.8,3,5,0,0.5,2,3};

    int intervals = countIntervals(A);
    cout<<intervals;

    return 1;

}