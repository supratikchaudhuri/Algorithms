#include<stdio.h>

int main()
{
    void fun(char*);
    char a[100];
    a[0] = 'A'; a[1] = 'B';
    a[2] = 'C'; a[3] = 'D';
    fun(&a[0]);     //BC
    return 0;
}
void fun(char *a)
{
    a++;
    printf("%c", *a);
    a++;
    printf("%c", *a);
}