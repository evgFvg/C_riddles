
#include <assert.h>
#include <stddef.h> /*size_t*/
#include <string.h> /*memcmp*/

void SortArray(int ar[], size_t size);
size_t GetIndexOf0(int ar[], size_t size, size_t j);
size_t GetIndexOf1(int ar[], size_t size, size_t i);
void Swap(int ar[], size_t i, size_t j);

int main()
{
    int ar[] = {1,0,0,1,0,0,1,0,1,1,0,0,1};
    int ar_expected[] = {0,0,0,0,0,0,0,1,1,1,1,1,1};
    size_t size = sizeof(ar) / sizeof(int);

    SortArray(ar, size);

    assert( 0 == memcmp(ar, ar_expected, size * sizeof(int)));

    return 0;
}

void SortArray(int ar[], size_t size)
{
    size_t i = 0;
    size_t j = size - 1;
    size_t index_of_1 = 0;
    size_t index_of_0 = 0;
    while(i < j)
    {
        index_of_1 = GetIndexOf1(ar, size, i);
        index_of_0 = GetIndexOf0(ar, size, j);
        Swap(ar, index_of_1, index_of_0);
        i = index_of_1;
        j = index_of_0;
        ++i;
        --j;
    }

}

size_t GetIndexOf1(int ar[], size_t size, size_t i)
{
    while(i < size && ar[i] == 0)
    {
        ++i;
    }

    return i;
}

size_t GetIndexOf0(int ar[], size_t size, size_t j)
{
    while(j >= 0 && ar[j] == 1)
    {
        --j;
    }
    
    return j;
}

void Swap(int ar[], size_t i, size_t j)
{
    int temp = ar[i];
    ar[i] = ar[j];
    ar[j] = temp;
}

