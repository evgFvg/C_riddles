#include <stdio.h>

int ArrJump(int ar[], int size, int index)
{
    int jump = 0;

    if (index >= size || index < 0 || ar[index] <= 0 )
    {
        return 0;
    }

    if (index == size - 1)
    {
        return 1;
    }

    jump = ar[index];
    ar[index] = -1;

    return ArrJump(ar, size, index + jump) || ArrJump(ar, size, index - jump);
}

int main()
{
    int ar_test[] = {2, 4, 1, 6, 4, 2, 4, 3, 5};
    int nums1[] = {2, 3, 1, 1, 4};
    int nums2[] = {3, 2, 1, 0, 4};
    int nums3[] = {1, 1, 0, 1};

    int numsSizeTest = sizeof(ar_test) / sizeof(int);
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);

    if (ArrJump(ar_test, numsSizeTest, 0))
    {
        printf("It's possible to traverse ar_test.\n");
    }
    else
    {
        printf("It's not possible to traverse ar_test.\n");
    }

    if (ArrJump(nums1, numsSize1, 0))
    {
        printf("It's possible to traverse nums1.\n");
    }
    else
    {
        printf("It's not possible to traverse nums1.\n");
    }

    if (ArrJump(nums2, numsSize2, 0))
    {
        printf("It's possible to traverse nums2.\n");
    }
    else
    {
        printf("It's not possible to traverse nums2.\n");
    }

    if (ArrJump(nums3, numsSize3, 0))
    {
        printf("It's possible to traverse nums3.\n");
    }
    else
    {
        printf("It's not possible to traverse nums3.\n");
    }
    return 0;
}
