#include <bits/stdc++.h>
using namespace std;

int main()
{
    //code
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i];

        int zero = 0;
        int two = n - 1;
        int index = 0;

        while (zero < two and index <= two)
        {
            if (vec[index] == 0)
            {
                swap(vec[index], vec[zero]);
                zero++;
                index++;
            }
            else if (vec[index] == 2)
            {
                swap(vec[index], vec[two]);
                two--;
            }
            else
            {
                index++;
            }
        }
        for (int i : vec)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}