#include <stdio.h>
#include <string.h>

static void Swap(char *a, char *b);
static void RecPermute(char *str, size_t left, size_t right);
void Permute(char *str);

int main()
{
    char buff[] = "ABC";
    Permute(buff);
    
    return 0;
}


void Permute(char *str)
{
    RecPermute(str, 0, strlen(str) - 1);
}

static void RecPermute(char *str, size_t left, size_t right)
{
    size_t i = 0;

    if(left == right)
    {
        printf("%s\n", str);
    }
    else
    {
        for( i = left; i <= right; ++i)
        {
            Swap(str + left, str + i);
            RecPermute(str, left + 1, right);
            Swap(str + left, str + i);
        }
    }
}

static void Swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
