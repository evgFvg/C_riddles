#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include <string.h>

#define WORD_SIZE (__WORDSIZE / __CHAR_BIT__)
#define ARRSIZE (9)

int Mymemcmp(const void *ptr1, const void *ptr2, size_t n);
static int CmpBytes(const void *ptr1, const void *ptr2, size_t offset, size_t n);
static int CmpWords(const void *ptr1, const void *ptr2, size_t offset, size_t num_words);

int main()
{
    int arr1[ARRSIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int arr2[ARRSIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int arr3[ARRSIZE] = {0, 1, 3, 3, 4, 5, 6, 7, 8};
    
    assert(Mymemcmp(arr1, arr2, sizeof(int) * ARRSIZE) == memcmp(arr1, arr2, sizeof(int) * ARRSIZE));
    assert(Mymemcmp(arr1, arr3, sizeof(int) * ARRSIZE) == memcmp(arr1, arr3, sizeof(int) * ARRSIZE));

    return 0;
}

int Mymemcmp(const void *ptr1, const void *ptr2, size_t n)
{
    size_t align_offset = 0;
    size_t num_words = 0;
    int res = 0;

    assert(NULL != ptr1);
    assert(NULL != ptr2);

    align_offset = (size_t)ptr1 & WORD_SIZE;

    /*COmpare bytes before alignment*/
    if (align_offset > 0)
    {
        res = CmpBytes(ptr1, ptr2, 0, align_offset);
    }

    /*Compare Words*/
    if (0 == res)
    {
        num_words = (n - align_offset) / WORD_SIZE;
        res = CmpWords(ptr1, ptr2, align_offset, num_words);
    }

    /*Compare any remaining bytes*/
    if (0 == res)
    {
        n = n - align_offset - (num_words * WORD_SIZE);
        res = CmpBytes(ptr1, ptr2, align_offset + (num_words * WORD_SIZE), n);
    }

    return res;
}

static int CmpBytes(const void *ptr1, const void *ptr2, size_t offset, size_t n)
{
    unsigned char *byte_runner1 = (unsigned char *)ptr1 + offset;
    unsigned char *byte_runner2 = (unsigned char *)ptr2 + offset;
    size_t i = 0;
    int res = 0;

    for (i = 0; i < n; ++i)
    {
        if (0 != (res = (*byte_runner1 - *byte_runner2)))
        {
            return res;
        }
        ++byte_runner1;
        ++byte_runner2;
    }

    return 0;
}

static int CmpWords(const void *ptr1, const void *ptr2, size_t offset, size_t num_words)
{

    size_t *word_runner1 = (size_t *)((unsigned char *)ptr1 + offset);
    size_t *word_runner2 = (size_t *)((unsigned char *)ptr2 + offset);
    size_t i = 0;
    int res = 0;

    for (i = 0; i < num_words; ++i)
    {
        if (0 != (res = (*word_runner1 - *word_runner2)))
        {
            return res;
        }
        ++word_runner1;
        ++word_runner2;
    }

    return 0;
}

