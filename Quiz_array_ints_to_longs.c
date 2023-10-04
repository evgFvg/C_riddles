#include <stdio.h> 
#include <string.h>  

long *SumIntPairsToLong(int ar[], size_t ar_size);
int main()
{
    size_t i = 0;

    int arr[] = {1, 2, 4, 5, 7, 8, 9, -12, 34, 0};
    long *l_arr = SumIntPairsToLong(arr, 10);
    for (i = 0; i < 5; i++)
    {
        printf("%ld\n", l_arr[i]);
    }
    return 0;
}

long *SumIntPairsToLong(int ar[], size_t ar_size)
{
    size_t i = 0;
    long item = 0;
    for (i = 0; i < ar_size; i += 2)
    {
        item = (long)ar[i] + (long)ar[i + 1];
        memcpy(ar+i, &item, (size_t)8);
    }
    return (long *)ar;
}
