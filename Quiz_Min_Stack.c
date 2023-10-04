
#include <stdlib.h> /*malloc*/
#include <stdio.h>  /*perror*/
#include <string.h> /*memcpy*/
#include <assert.h>

#include <stddef.h> /*size_t*/

typedef struct stack stack_t;

struct stack
{
    int *buffer;
    size_t top;
    size_t capacity;
    stack_t *min_stack;
};

stack_t *CreateStack(size_t capacity)
{
    stack_t *new_stack = (stack_t *)malloc(sizeof(stack_t));
    stack_t *res = new_stack;

    if (NULL == (new_stack))
    {
        perror("Memory allocation error\n");
        res = NULL;
    }
    else
    {
        new_stack->top = 0;
        new_stack->capacity = capacity;
        new_stack->buffer = malloc(capacity * sizeof(int));
        new_stack->min_stack = (stack_t *)malloc(sizeof(stack_t));

        if (NULL == new_stack->buffer || NULL == new_stack->min_stack)
        {
            perror("Memory allocation error\n");
            res = NULL;
        }
        else
        {
            new_stack->min_stack->top = 0;
            new_stack->min_stack->capacity = capacity;
            new_stack->min_stack->buffer = malloc(capacity * sizeof(int));
            if (NULL == new_stack->min_stack->buffer)
            {
                perror("Memory allocation error\n");
                res = NULL;
            }
        }
    }
    return res;
}

void DestroyStack(stack_t *stack)
{
    free(stack->min_stack->buffer);
    free(stack->min_stack);
    free(stack->buffer);
    free(stack);
}

static void AddElmToStack(stack_t *stack, const int *item)
{
    memcpy((char *)stack->buffer + (stack->top * sizeof(int)), item, sizeof(int));
    ++stack->top;
}

int *Peek(stack_t *stack)
{
    assert(stack->top != 0);
    return stack->buffer + (stack->top - 1);
}

void Push(stack_t *stack, const int *item)
{
    assert(stack->top < stack->capacity);
    if (0 == stack->top)
    {
        AddElmToStack(stack, item);
        AddElmToStack(stack->min_stack, item);
    }
    else
    {
        if (*item < *Peek(stack->min_stack))
        {
            AddElmToStack(stack, item);
            AddElmToStack(stack->min_stack, item);
        }
        else
        {
            AddElmToStack(stack, item);
        }
    }
}

void Pop(stack_t *stack)
{
    int min_item = *Peek(stack->min_stack);
    int peek_item = *Peek(stack);;
    assert(stack->top != 0);
    if (min_item == peek_item)
    {
        --stack->top;
        --stack->min_stack->top;
    }
    else
    {
        --stack->top;
    }
        
}

int GetMin(stack_t *stack)
{
    int *res = Peek(stack->min_stack);
    return *res;
}



int IsEmpty(const stack_t *stack)
{
    return 0 == stack->top ? 1 : 0;
}

size_t StackSize(const stack_t *stack)
{
    return stack->top;
}

size_t StackCapacity(const stack_t *stack)
{
    return stack->capacity;
}

int main()
{
    int a = 5, b = 100, c = 3, d = 54;
    int min = 0;
    int item = 0;
    stack_t *new_stack = CreateStack(10);
    Push(new_stack, &a);
    Push(new_stack, &b);
    Push(new_stack, &c);
    Push(new_stack, &d);
    min = GetMin(new_stack);
    item = *Peek(new_stack);
    assert(min == 3);
    assert(item == 54);





    return 0;
}
