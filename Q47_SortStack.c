#include <assert.h>
#include <stdio.h>  /*printf*/

#include "stack.h"

static void TestStack();
static void SortStack();

void FillTmpStack(stack_t *tmp, int *x);

int main()
{
    SortStack();
    return 0;
}

static void SortStack()
{
    int ar[] = {3, 10, -1, 0, 15, 2};
    int i = 0;
    int x = 0;
    stack_t *new_stack = StackCreate(15, 4);
    stack_t *tmp = StackCreate(15, 4);

    for (i = 0; i < 6; ++i)
    {
        StackPush(new_stack, &ar[i]);
    }

    assert(6 == StackSize(new_stack));

    while(0 == StackIsEmpty(new_stack))
    {
        x = *(int *)StackPeek(new_stack);
        FillTmpStack(tmp, &x);
        StackPop(new_stack);
    }

    assert(6 == StackSize(tmp));

    while(0 == StackIsEmpty(tmp))
    {
        x = *(int *)StackPeek(tmp);
        StackPush(new_stack, &x);
        StackPop(tmp);
    }

    StackDestroy(tmp);
    
    for(i = 0; i < 6; i++)
    {
        printf("%d\n", *(int *)StackPeek(new_stack));
        StackPop(new_stack);
    }

    StackDestroy(new_stack);
}

void FillTmpStack(stack_t *tmp, int *x)
{
    int y = 0;
    if(1 == StackIsEmpty(tmp))
    {
        StackPush(tmp, x);
    }
    else
    {
        y = *( int *)StackPeek(tmp);
        if(y < *x)
        {
            StackPush(tmp, x);
        }
        else
        {
            StackPop(tmp);
            FillTmpStack(tmp, x);
            StackPush(tmp, &y);
        }
    }
}
