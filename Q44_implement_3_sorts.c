#include <stdio.h>


#define TRUE (0)
#define FALSE (1)

void Swap(int *a, int *b);
void BubbleSort(int arr[], int size);
int GetMInIndex(int arr[], int left, int right);
void SelectionSort(int arr[], int size);
void InsertionSort(int arr[], int size);

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    InsertionSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void BubbleSort(int arr[], int size)
{
    int i = 0, j = 0, is_swapped = FALSE;

    for (i = 0; i < size - 1; ++i)
    {
        is_swapped = FALSE;
        for (j = 0; j < size - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                Swap(&arr[j], &arr[j + 1]);
                is_swapped = TRUE;
            }
        }

        if (is_swapped == FALSE)
        {
            break;
        }
    }
}

void Swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void SelectionSort(int arr[], int size)
{
    int i = 0, min_index = 0;
    for (i = 0; i < size; ++i)
    {
        min_index = GetMInIndex(arr, i, size);
        Swap(&arr[i], &arr[min_index]);
    }
}

int GetMInIndex(int arr[], int left, int right)
{
    int min = 0;
    int i = 0;

    for (i = left + 1, min = left; i < right; ++i)
    {
        if (arr[i] < arr[min])
        {
            min = i;
        }
    }

    return min;
}

void InsertionSort(int arr[], int size)
{
    int i = 0;
    int j = 0;
    int key = 0;

    for(i = 1; i < size; ++i)
    {
        key = arr[i];
        j = i - 1;

        while( j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}
