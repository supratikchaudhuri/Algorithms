#include<bits/stdc++.h>
using namespace std;

typedef char x[10];

int main () {
    int arr[10] = {1,2,3,4};
    for(int i = 0; i <10; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    x myArray[5];
    int n = sizeof(myArray);
    cout<<n<<endl;

    static int a[ ] = { 7, 8, 9 } ;
    printf( "%d", 2[ a ] + a[ 2 ] ) ;   

    int val[2][4] = { 1, 2, 3, 4, 5, 6, 7, 8} ;
    printf("%d\n", val[1][0]); //????????????????????????????
    
}