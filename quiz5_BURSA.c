
#include <stdio.h>

int bursa(int ar[], int size, int *left_index, int *right_index);
int main()
{

    int ar[] = {6, 12, 3, 5, 1, 4, 9, 2};
    int size = 8;
    int left = 0, right = 0;
    int res = bursa(ar, size, &left, &right);
    printf("left is %d\n", left);
    printf("right is %d\n", right);
    printf("sum is %d\n", res);

    return 0;
}

int bursa(int ar[], int size, int *left_index, int *right_index)
{
    int indexOffset = 0, i = 0, sum = 0, maxSum = 0;
    for (i = 0; i < size - 1; i++)
    {
        sum += ar[i + 1] - ar[i];
        indexOffset++;

        if (sum < 0)
        {
            sum = 0;
            indexOffset = 0;
        }
        if (sum > maxSum)
        {
            maxSum = sum;
            *left_index = i - indexOffset + 1;
            *right_index = i + 1;
        }
    }
    return maxSum;
}
