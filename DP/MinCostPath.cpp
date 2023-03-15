// \noindent Prof. Curly is planning a cross-country road-trip from Boston to Seattle on Interstate 90, and he needs to rent a car.  His first inclination was to call up the various car rental agencies to find the best price for renting a vehicle from Boston to Seattle, but he has learned,much to his dismay,  that this may not be an optimal strategy.  Due to the plethora of car rental agencies  and  the  various  price  wars  among  them,  it  might  actually  be cheaper to rent one car from Boston to Cleveland with Hertz,  followed by a second car from Cleveland to Chicago with Avis, and so on, than to rent any single car from Boston to Seattle.

// \noindent Prof. Curly is not opposed to stopping in a major city along Interstate 90 to change rental cars; however, he does not wish to backtrack, due to time contraints.  (In other words, a trip from Boston to Chicago, Chicago to Cleveland, and Cleveland to Seattle is out of the question.)  Prof.  Curly has selected $n$ major cities along Interstate 90 and ordered them from East to West, where City 1 is Boston and City $n$ is Seattle.  He has constructed a table $T[i, j]$ which for all $i < j$ contains the cost of the cheapest single rental car from City $i$ to City $j$.  Prof. Curly wants to travel as cheaply as possible. Devise an algorithm which solves this problem, argue that your algorithm is correct, and analyze its running time and space requirements.  Your algorithm or algorithms should output both the total cost of the trip and the various cities at which rental cars must be dropped off and/or picked up.

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:

    void minCostPath(vector<vector<int>> &T) {
        int n = T.size();

        vector<int> dp = T[0];
        vector<int> S(n, 0);

        for(int i = 1; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(T[i][j] + dp[i] < dp[j]) {
                    dp[j] = T[i][j] + dp[i];
                    S[j] = i;
                }
            }
        }

        cout<<"Cost: "<<dp[n-1]<<endl;

        cout<<"Trace: ";
        string path = "";
        int i = n-1;
        while(i != 0) {
            path = to_string(i) + " -> " + path;
            i = S[i];
        }
        path = "0 -> " + path;
        cout<<path<<endl;
    }

//     void minCostPath(vector<vector<int>> &T) {
//         int n = T.size();

//         vector<vector<int>> dp(n, vector<int>(n, 1e9));
//         vector<int> S(n);

//         for(int j = 0; j < n; j++)
//             dp[0][j] = T[0][j];

//         for(int i = 1; i < n; i++) {
//             for(int j = i+1; j < n; j++) {
//                 dp[i][j] = dp[i-1][j];

//                 if(T[i][j] + dp[i-1][j-1] < dp[i][j]) {//if we stop at this city
//                     dp[i][j] = T[i][j] + dp[i-1][j-1];
//                     S[j] = i;
//                 }
//             }
//         }
//         cout<<"Cost: "<<dp[n-2][n-1]<<endl;

//         for(int i = 0; i < n; i++) {
//             cout<<S[i]<<" ";
//         }
        
//     }
// };

int main() {
    vector<vector<int>> T = {{0,15,25,55,80,200},
                            {0,0,20,25,75,155},
                            {0,0,0,10,70,150},
                            {0,0,0,0,50,80},
                            {0,0,0,0,0,10},
                            {0,0,0,0,0,0}};

    Solution ob;
    ob.minCostPath(T);
    
    return 0;
}

// g++ -std=c++11 <filename>


