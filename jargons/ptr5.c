#include<stdio.h>
power(int**);
int main()
{
    int a=5, *aa; /* Address of 'a' is 1000 */
    aa = &a;
    a = power(&aa);
    printf("%d\n", a);//25
    return 0;
}
power(int **ptr)
{
    int b;
    b = **ptr***ptr;
    return (b);
}