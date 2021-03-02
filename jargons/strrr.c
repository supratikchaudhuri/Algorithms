#include<stdio.h>

int main()
{
    void *vp;
    char ch=74, *cp="JACK";
    int j=65;
    vp=&ch;
    printf("%c\n", *(char*)vp);
    printf("%c\n\n", *cp);//only cp wont give anything as addr is int

    vp=&j;
    printf("%c\n", *(int*)vp);

    vp=cp;
    printf("%s\n", (char*)vp+2);
    return 0;
}