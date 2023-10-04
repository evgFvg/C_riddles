
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void SubStr(const char *str, const char *sub);
int main()
{
    const char *str = "12345";
    const char *sub = "45123";
    SubStr(str, sub);
    return 0;
}

void SubStr(const char *str, const char *sub)
{

    char *double_sub = (char *)malloc(sizeof(char) * (2 * strlen(sub) +1));
    char *is_rotation = NULL;
    if (NULL == double_sub)
    {
        perror("Memory Allocation error");
        return ;
    }
    else
    {
        strcpy(double_sub, sub);
        strcpy(double_sub + strlen(sub), sub);
        is_rotation = strstr(double_sub, str);
        if (NULL == is_rotation)
        {
            printf("%s is NOT a rotation of the %s\n", sub, str);
        }
        else{
            printf("%s is a rotation of the %s\n", sub, str);
        }
    }

    free(double_sub);
}
