#include <stdio.h>
#include <assert.h>

int JosephusForK2Only(int n);
int GetLog2N(int n);

/*Each ieration comutes the index of the soldier staying alive for i soldiers, knowing that for 1 soldier the right index would be 0*/
int Josephus(int n, int k)
{
    int i = 1, ans = 0;

    while (i <= n)
    {
        ans = (ans + k) % i;
        i++;
    }

    return ans + 1;
}

int main()
{

    int n = 100, k = 2;
    assert( JosephusForK2Only(n) == Josephus(n, k));

    printf("%d\n", JosephusForK2Only(n));
    return 0;
}

/*Each number could be represented as n = 2 ^ a + l, for example 100 = 2 ^ 6 + 36. We know that if amount of soldiers is (2 ^ any) (16 , 32, 128)
means that index of the survivior is always 1. So we can claim that for any amount of soldiers , when we killed first l soldiers, next killer soldier
is a lucky one, because all he needs to do is to kill the rest (2 ^ a ) soldiers. Since every step we jump 2 soldiers, the needed index is 2 * l + 1*/
int JosephusForK2Only(int n)
{
    int pow = GetLog2N(n);

    return 2 * (n - (2 << (pow - 1))) + 1;;
}

int GetLog2N(int n)
{
    int pow = 1;
    int count = 0;

    while (pow < n)
    {
        pow *= 2;
        ++count;
    }

    return count - 1;
}
