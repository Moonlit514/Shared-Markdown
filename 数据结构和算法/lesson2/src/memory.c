#include <stdio.h>

int main()
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("head address of array: %d\n", a);
    printf("size of int: %d\n", sizeof(int));
    printf("size of array: %d\n", sizeof(a));
    printf("address of array first element: %d\n", &a[0]);
    printf("address of array second element: %d\n", &a[1]);
    printf("end address of array: %d\n", &a[10]);
    return 0;
}