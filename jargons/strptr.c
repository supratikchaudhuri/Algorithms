#include<stdio.h>

int main()
{
    int arr[3] = {2, 3, 4};
    char *p;
    p = arr;
    p = (char*)((int*)(p));
    printf("%d, ", *p);

    p = (int*)(p+1);
    printf("%d\n\n\n", *p);



    ///////////////////

    char *str;
    str = "%d\n";
    str++;
    str++;
    printf(str-2, 300);


    /////////////

    printf("\n\n\n\n%c\n", 7["IndiaBIX"]); //"X"

    //////////////////


    char *s;
    s="hello";
    printf("%s\n\n\n\n", *&*&s);//"hello"
    return 0;
}