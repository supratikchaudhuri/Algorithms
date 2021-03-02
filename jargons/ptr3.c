#include<stdio.h>

int main()
{
    int arr[3][3] = {1, 2, 3, 4};
    printf("%d\n", *(arr));//addr
    printf("%d\n", *(*(arr)+1));//2
    printf("%d\n", *(*(arr+1)));//4
    // printf("%d\n", *(*(*(arr))));//err
    return 0;
}