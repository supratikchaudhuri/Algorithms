#include<stdio.h>
int main()
{
    float i=10, *j;
    void *k;
    k=&i;
    j=k;
    printf("%f\n", *j);
    printf("%d   %d", sizeof(NULL), sizeof(""));
    return 0;
}