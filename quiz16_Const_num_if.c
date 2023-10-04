
int ConstIf(int ar[] , int size, int num);
int main()
{
    int ar[ ]= {0, 2, -8, 5, 2, 19, 2};
    int size = *(&ar +1) - ar;
    int num = 2;
    int res = ConstIf(ar, size, num);
    return 0;
}

int ConstIf(int ar[], int size, int num)
{
    int res = 0;
    int i = 0;
    for ( i = 0; i < size; ++i)
    {
        res += (ar[i] == num);
    }
    
    return res >= 1;
}
