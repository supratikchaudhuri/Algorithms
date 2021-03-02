#include<stdio.h>

int main()
{
    char* ptr1 = "yellow";
    printf("%s\n", ptr1);

    static char *s[] = {"black", "white", "pink", "violet"};
    char **ptr[] = {s+3, s+2, s+1, s}, ***p;
    p = ptr;
    ++p;
    printf("%s", **p+1);
    return 0;
}