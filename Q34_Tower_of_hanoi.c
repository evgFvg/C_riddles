#include <stdio.h>

static void TOH(int n, char source, char temp, char dest);
int main()
{
    char source = 'S';
    char dest = 'D';
    char temp = 'T';

    TOH(3, source, temp, dest);
    return 0;
}

static void TOH(int n, char source, char temp, char dest)
{
    if(n > 0)
    {
        TOH(n-1, source, dest, temp);
        printf("Moving from %c to %c\n", source, dest);
        TOH(n - 1, temp, source, dest);
    }
}
