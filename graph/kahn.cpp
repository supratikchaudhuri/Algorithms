#include <bits/stdc++.h>
using namespace std;

//KAHN ALGO O(V+E) Must be DAG
class Solution
{

    bool kahn(vector<vector<int>> adj, vector<int> &indegree, vector<int> &res, int numCourses)
    {
        queue<int> q;
        for (int i = 0; i < indegree.size(); i++)
            if (indegree[i] == 0)
                q.push(i);

        int count = 0; //to takecare of cycle condition

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (auto ele : adj[curr])
            {
                indegree[ele]--;
                if (indegree[ele] == 0)
                    q.push(ele);
            }

            res.push_back(curr);
            count += 1;
        }

        if (count != numCourses)
            return false;
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prereq)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);

        for (int i = 0; i < prereq.size(); i++)
        {
            adj[prereq[i][1]].push_back(prereq[i][0]);
            indegree[prereq[i][0]]++;
        }

        vector<int> res;
        if (kahn(adj, indegree, res, numCourses))
            return res;
        else
            return {};
    }
};