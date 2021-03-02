#include<stdio.h>

int main()
{
    int x=30, *y, *z;
    y=&x; /* Assume address of x is 500 and integer is 4 byte size */
    z=y;
    printf("address: %d\n", y);
    // *y++=*z++;
    // x++; //this is resp for incrementing

    *++y;//increments addr
    ++*y;//only doing this will inc x
    printf("x = %d, y = %d, z = %d\n", x, y, z);
    return 0;
}
// *ptr++ increments the pointer and not the value, whereas the ++*ptr increments the value being pointed by ptr