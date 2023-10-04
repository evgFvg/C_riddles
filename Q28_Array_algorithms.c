
#include <assert.h>
#include <string.h> /*memcmp*/
#include <stdio.h> /*printf*/
int IsHasChar(const char arr[], size_t size, char c);
void ReverseArrayFromTo(int arr[], size_t from, size_t to);
void ShiftArray(int arr[], size_t size, size_t n_shift);

int main()
{
    char arr[5] = {3, 5, 6, 0, 2};
    int ar[5] = {1, 2, 3, 4, 5};
    int expected[5] = {3,4,5,1,2};
    char c = 6;

    assert(1 == IsHasChar(arr, 5, c));
    assert(0 == IsHasChar(arr, 5, 88));

    ShiftArray(ar, 5, 2);

    assert(0 == memcmp(ar, expected, 5));

    return 0;
}

int IsHasChar(const char arr[], size_t size, char c)
{
    int res = 0;
    size_t i = 0;

    for (i = 0; i < size; ++i)
    {
        res += (arr[i] == c);
    }

    return !!res;
}

void ShiftArray(int arr[], size_t size, size_t n_shift)
{
    if (0 == n_shift % size)
    {
        return;
    }

    ReverseArrayFromTo(arr, 0, size-1);
    ReverseArrayFromTo(arr, 0, n_shift);
    ReverseArrayFromTo(arr, n_shift + 1, size - 1);
}

void ReverseArrayFromTo(int arr[], size_t from, size_t to)
{
    int temp = 0;
    size_t i = 0;

    for (i = from; i < to; i++, --to)
    {
        temp = arr[i];
        arr[i] = arr[to];
        arr[to] = temp;
    }
}

