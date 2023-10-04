
#include <stdio.h>     /*printf*/
#include <stdlib.h>    /*malloc*/
#include <assert.h>
#include <time.h>

static void Swap(int *a, int *b);
static void MyQsort(int arr[], size_t size);
static void RecQSort(int arr[], int left, int right);
static size_t Partition(int arr[], int left, int right);

int main()
{
    int arr[] = {6,3,-2,0,11,10,2};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    MyQsort(arr, size);

    for(int i = 0; i < size; ++i)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}

static void MyQsort(int arr[], size_t size)
{
    srand(time(NULL));
    RecQSort(arr, 0, size - 1);
}

static void RecQSort(int arr[], int left, int right)
{
    size_t pivot = 0;

    if(left < right)
    {
        pivot = Partition(arr, left, right);

        RecQSort(arr, left, pivot - 1);
        RecQSort(arr, pivot + 1, right);
    }
}

static size_t Partition(int arr[], int left, int right)
{
    int i = left;
    int j =  left;
    int pivot_i = left + (rand() % (right - left));

    Swap(&arr[right], &arr[pivot_i]);

    for(j = left; j < right; ++j)
    {
        if(arr[j] <= arr[right])
        {
            Swap(&arr[j], &arr[i]);
            ++i;
        }
    }

    Swap(&arr[i], &arr[right]);

    return i;
}

static void Swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
