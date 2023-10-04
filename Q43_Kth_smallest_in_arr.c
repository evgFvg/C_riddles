
#include <assert.h>

int KthSmallest(int arr[], int left, int right, int k);
void Swap(int arr[], int left, int right);
int GetPivotIndex(int arr[], int left, int right);

int main()
{
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    int arr_expected[] = {3, 4, 5, 7, 12, 19, 26};
    int k = 1;
    int i = 0;

    for (i = 0; i < n; ++i)
    {
        assert(KthSmallest(arr, 0, n - 1, k - 1) == arr_expected[i]);
        ++k;
    }

    return 0;
}

int KthSmallest(int arr[], int left, int right, int k)
{
    int pivot_index = GetPivotIndex(arr, left, right);

    if (pivot_index == k)
    {
        return arr[k];
    }
    if (pivot_index < k)
    {
        return KthSmallest(arr, pivot_index + 1, right, k);
    }

    return KthSmallest(arr, left, pivot_index - 1, k);
}

void Swap(int arr[], int left, int right)
{
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

int GetPivotIndex(int arr[], int left, int right)
{
    int pivot = arr[right];
    int j = 0;
    int i = left;

    for (j = left; j <= right; ++j)
    {
        if (arr[j] < pivot)
        {
            Swap(arr, j, i);
            ++i;
        }
    }

    Swap(arr, right, i);

    return i;
}

