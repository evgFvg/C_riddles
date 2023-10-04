#include <stdio.h> /* errno */
void Find_Two_missing_numbers(int ar[], int size);

int main()
{
    int ar[7] = {1, 5, 4, 2, 7};
    int size = 7;
    Find_Two_missing_numbers(ar,size);

    return 0;
}

void Find_Two_missing_numbers(int ar[], int size)
{
    int sum_of_actual = 0, sum_of_n = 0, i = 0, avg = 0, diff = 0, sum_less = 0, sum_bigger = 0, miss_1 = 0, miss_2 = 0;
    
    for(i = 0; i < size-2; i++)
    {
        sum_of_actual += ar[i];
    }

    sum_of_n = (size * (size + 1)) / 2; /*sum of numbers in range 1...n =  (n * (n+1)) / 2 */
    diff = sum_of_n - sum_of_actual;
    avg = (diff / 2) + (diff % 2); /* Round up to the nearest integer */

    for(i = 0; i < size - 2; i++)
    {
        if(ar[i] <= avg) 
        {
            sum_less += ar[i];
        }
        else
        {
            sum_bigger += ar[i];
        }
    }
    miss_1 = (avg * (avg + 1)) / 2 - sum_less;
    miss_2 = diff - miss_1;

    printf("Missing numbers are %d and %d\n", miss_1, miss_2);
}












