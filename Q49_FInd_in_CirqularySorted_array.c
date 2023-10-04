
#include <assert.h>

int FindInCirqularySortedArray(int arr[], size_t size, int target);

int main()
{
    int arr[] = {7, 8, 0, 1, 2, 3, 4, 5};
    
    assert(2 == FindInCirqularySortedArray(arr, 8, 0));
    assert(-1 == FindInCirqularySortedArray(arr, 8, 6));

    return 0;
}


int FindInCirqularySortedArray(int arr[], size_t size, int target)
{
    size_t start = 0;
    size_t end = size - 1;
    size_t mid = 0;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] >= arr[start])
        {
            if (target >= arr[start] && target < arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            if (target > arr[mid] && target <= arr[end])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    return -1;
}
