
#include<assert.h>

#define OUT_OF_BOUNDES (-1)

void ShiftZeroes(int arr[], int size) ;
static void Swap(int *s1, int *s2);
static void TestArr(int arr[], int size) ;
static int GetFirst0Indx(int arr[], int size) ;

int main() {
    int arr[]  = {1,9,8,4,0,0,7,6,0,5};
    int size = sizeof(arr) / sizeof(int);
    ShiftZeroes(arr, size);
    TestArr(arr, size);
}

static void Swap(int *s1, int *s2)
{
    int temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void ShiftZeroes(int arr[], int n)
{
    int i =0;
    int zero_index = 0;

    for (i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            Swap(&arr[i],&arr[zero_index]);
            zero_index++;
        }
    }
}

static void TestArr(int arr[], int size) 
{
    int first_0_indx = GetFirst0Indx(arr, size);

    for(int i = first_0_indx + 1; i < size; ++i) 
    {
        assert(arr[i] == 0);
    }
}
static int GetFirst0Indx(int arr[], int size) 
{
    int i = 0;

    for(i = 0; i < size; ++i)
    {
        if(arr[i] == 0) 
        {
            break;
        }
    }

    return i == size ? OUT_OF_BOUNDES : i;
}

