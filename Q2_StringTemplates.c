#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FALSE (1)
#define TRUE (0)

int IsSamePattern(char *str1, char *str2);

int main()
{
    char *str1 = "aba";
    char *str2 = "mom";

    int res = IsSamePattern(str1, str2);

    printf("res = %d\n", res);
    return 0;
}

int IsSamePattern(char *str1, char *str2)
{
    size_t length1 = strlen(str1);
    size_t length2 = strlen(str2);
    int offset1 = 0;
    int offset2 = 0;
    char *letter_position1 = NULL;
    char *letter_position2 = NULL;

    if (length1 != length2)
    {
        return FALSE;
    }

    for (int i = 0; i < length1; ++i, ++str1, ++str2)
    {
        letter_position1 = strchr(str1 + 1, *str1);
        letter_position2 = strchr(str2 + 1, *str2);

        if (NULL != letter_position1 || NULL != letter_position2)
        {
            offset1 = letter_position1 - str1;
            offset2 = letter_position2 - str2;

            if (offset1 != offset2)
            {
                return FALSE;
            }
        }
    }

    return TRUE;
}
