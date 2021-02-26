#include<bits/stdc++.h>
using namespace std;

//MACRO FUNCTIONS

typedef float float_arr [100];

enum colors{red=5, black};
enum suit{heart, diamond=8, spade=3, club=1, clove};//can have same values 

int main () {
    float_arr a;
    printf("size of float_arr: %d\nsize of a: %d\n", sizeof(float_arr), sizeof(a)/sizeof(a[0]));
    //400, 100

    // extern int i;
    // i = 20;
    // printf("%d\n\n",sizeof(i));//gives error

    extern int under_main;
    printf("\n%d\n\n",under_main);//20

    cout <<"The value of enum color : "<<red<<","<<black;
    cout <<"\nThe default value of enum suit : "<<heart<<","<<diamond<<","<<spade<<","<<club<<","<<clove<<endl;


    printf ( "\nTIM--- %d\n\n" , printf ( "tim" ));//3
    return 0;

    // int xx:4;
    // printf("%d", sizeof(xx));    xxis 4bit integer....bitted number usually inside struct
}
int under_main = 20;