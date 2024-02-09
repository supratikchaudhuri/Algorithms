#include <bits/stdc++.h>
#include<vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countLuck' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING_ARRAY matrix
 *  2. INTEGER k
 */

vector<vector<int> > dirs = {{1,0},{-1,0},{0,-1},{0,1}};

string countLuck(vector<string> A, int k) {
    int m = A.size(), n = A[0].size();
    queue<vector<int> > q;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(A[i][j] == 'M')
                q.push({i, j, 0, 0, 0});
        }
    }
    
    while(!q.empty()) {
        vector<int> v = q.front();
        int i = v[0], j = v[1], ci = v[2], cj = v[3], changes = v[4];
        if(A[i][j] == '*') 
            return changes == k ? "Impressed" : "Oops!";
        
        for(vector<int> dir: dirs) {
            int ni = i + dir[0], nj = j + dir[0];
            
            if(ni < 0 or ni == m or nj < 0 or nj == n or nj == 'X')
                continue;
                
            q.push({ni, nj, dir[0], dir[1], dir[0] == ci and dir[1] == cj ? changes : changes + 1});
        }
    }
    return "default";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<string> matrix(n);

        for (int i = 0; i < n; i++) {
            string matrix_item;
            getline(cin, matrix_item);

            matrix[i] = matrix_item;
        }

        string k_temp;
        getline(cin, k_temp);

        int k = stoi(ltrim(rtrim(k_temp)));

        string result = countLuck(matrix, k);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
