
#include <assert.h>

static int GetExp(int n);
int FlipNum_Rec(int n);

int main()
{
    int n = 4321;
    assert(1234 == FlipNum_Rec(n));

    return 0;
}

int FlipNum_Rec(int n)
{
    int exp = 0;
    int res = 0;

    if (0 == n)
    {
        return 0;
    }

    exp = GetExp(n);

    return  n % 10 * exp + FlipNum_Rec(n / 10);
}

static int GetExp(int n)
{
    int i = 0;
    int res = 1;
    while (n != 0)
    {
        n /= 10;
        res *= 10;
    }

    return res / 10;
}
