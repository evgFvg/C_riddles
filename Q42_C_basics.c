#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<string.h>

#define ROWS (5)
#define COLS (5)

int CheckBoth2_6_bits(unsigned char c)
{
    return ((c & (1 << 1)) && (c & (1 << 5)));
}

int Check2_Or_6_bits(unsigned char c)
{
    return ((c & (1 << 1)) || (c & (1 << 5)));
}

void Swap2_And_6_bits(unsigned char *c)
{
    return *c ^= ((1 << 1) | (1 << 5));
}

void SwapVoidPtrs(void **p1, void **p2)
{
    void *tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void CmpStrings()
{
    char *p = "lalala"; //String literal in Data read only segment, Inmutable. p could be assigned to other string
    char arr[10] = "lalala"; //String in stack segment, Mutable. Arr can not be assigned to other value.
    ++p; // Allowed
    //++arr; Non modifyable value 
    //*p = 's' - error. String literals are inmutable
    //p[0] = 's' - same
    arr[1] = 's'; // allowed
    *(arr  + 1) = 's';// same as prev - allowed
    1[arr] = 's';// same. allowed
}

int * CreateOneD_Array(int size)
{
    return (int *)malloc(size * sizeof(int));
}

int **Create2DArray(int row, int col)
{
    int **res = (int **)malloc(row * sizeof(int *));
    size_t i = 0;
    size_t j = 0;
    if(NULL == res)
    {
        return NULL;
    }
    for(i = 0; i < row; ++i)
    {
        res[i] = (int *)malloc(row * sizeof(int));

        if(NULL == res[i])
        {
            for(j = 0; j < i; ++j)
            {
                free(res[j]);
            }

            free(res);

            return NULL;
        }
    }

    return res;
}

void ResetArray(int arr[], size_t size)
{
    memset(arr, 0, size * sizeof(int));
}

void Reset2DArray(int **arr, int row, int col)
{
    size_t i = 0;

    for(i = 0; i < ROWS; ++i)
    {
        ResetArray(arr[i], col);
    }
}

void Reset2DArray2(int **matrix, int row, int col)
{
    memset(*matrix, 0, row * col * sizeof(int));
}
