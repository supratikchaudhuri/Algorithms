#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int minStops (vector<int> A, int m) {
    int start = 0;
    int stops = 0;
    int last_stop = 0;
    int max_dist = last_stop + m;
    

   for(int i = 0; i < A.size(); i++) {
        while(i < A.size() && A[i] <= max_dist) {
            i++;
        }

        last_stop = A[i-1];
        start = last_stop;
        max_dist = last_stop + m;
        stops++;
    }
    return stops;
}

int main() {
    vector<int> A = {1, 2, 5, 6, 7, 10};
    cout<<minStops(A, 4);

}


