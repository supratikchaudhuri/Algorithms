#include <bits/stdc++.h>
using namespace std;

union test {
    int a;
    char b;
};

int f1(int i) {
    cout<<i<<endl;
    return i;
}
int f2(int i) {
    cout<<i<<endl;
    return i;
}
int f3(int i) {
    cout<<i<<endl;   
    return i;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main () {
    test t;
    t.a = 325;
    printf("%c\n\n", t.b);  //t.b = E

    //whuich fn is called first
    int x = 2, y = 4, z = 6;
    int res = f1(x) + f2(y) * f3(z);
    
    int a = 5, b = 5;
    // printf("%d %d %d", a++, ++a, a++);

    while(a == b) {
        printf("Hello\n");
        a++;
    }

    int (*fp) (int, int) = max;
    cout<< fp(10, 5) <<endl;

    char *p = "GATE2020";
    printf("%s\n", p);
    printf("%s\n", p + p[3] - p[1]);

    char q[10];
    int i = strlen(p)-1, j = 0;

    for(; i>= 0; i--, j++)
        q[j] = p[i];
    q[j] = '\0';
    printf("%s\n", q);
}

