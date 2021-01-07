#include <bits/stdc++.h>
using namespace std;

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> vec(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }

        int dp[n] = {10000};
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (j + vec[j] >= i)
                {
                    dp[i] = min(dp[i], j = vec[j]);
                }
            }
        }
        if (dp[n - 1] == 10000)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << dp[n - 1];
        }
    }
    return 0;
}