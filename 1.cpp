#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
    int res = -1;

    void dfs(int i, vector<vector<int>> adj, unordered_map<char, int> map, string colors) {
        map[colors[i]]++;
        res = max(res, map[colors[i]]);

        for(auto nei: adj[i]) {
            dfs(nei, adj, map, colors);
        }
    }

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(auto e: edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                unordered_map<char, int> map;
                dfs(i, adj, map, colors);
            }
        }

        return res;
    }
};

int main() {
    string colors = "hwuyyyyuyhwwhuhwwwwhuyhuuhwwyuwyuhwhuwuyhuhhuyuuwuhw";
    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{3,4},{4,5},{5,6},{3,6},{6,7},{7,8},{4,8},{8,9},{7,9},{7,10},{10,11},{8,12},{8,13},{11,13},{12,14},{13,14},{10,14},{8,15},{15,16},{12,16},{11,16},{16,17},{9,17},{13,17},{15,18},{17,18},{9,19},{13,19},{18,20},{19,20},{16,20},{15,21},{20,21},{17,21},{18,21},{18,22},{21,22},{21,23},{22,23},{21,24},{24,25},{20,25},{12,25},{14,26},{25,27},{25,28},{26,28},{28,29},{27,29},{23,29},{27,30},{29,30},{10,30},{28,31},{29,31},{27,31},{30,31},{23,32},{31,32},{20,33},{27,33},{33,34},{30,34},{32,34},{28,34},{31,35},{4,35},{25,35},{34,35},{31,36},{30,36},{34,36},{35,36},{26,36},{33,37},{37,38},{36,38},{34,38},{33,39},{36,39},{38,39},{38,40},{39,40},{37,40},{33,40},{36,40},{40,41},{39,41},{35,41},{25,41},{23,42},{27,42},{39,42},{18,43},{35,43},{42,44},{33,45},{34,46},{43,46},{45,46},{44,47},{46,47},{37,48},{40,48},{36,49},{47,49},{37,49},{46,49},{48,49},{48,50},{49,50},{48,51}};

    Solution ob;
    cout<<ob.largestPathValue(colors, edges);
}


