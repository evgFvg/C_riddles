
#include <stdlib.h> /*malloc*/
#include <stdio.h>  /*perror*/
#include <string.h> /*memcpy*/
#include <assert.h>

typedef struct stack
{
    void *buffer;
    size_t top;
    size_t capacity;
    size_t element_size;
} stack_t;

stack_t *CreateStack(size_t capacity, size_t element_size)
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
        new_stack->element_size = element_size;
        new_stack->buffer = malloc(capacity * element_size);
        if (NULL == new_stack->buffer)
        {
            perror("Memory allocation error\n");
            res = NULL;
        }
    }
    return res;
}

void DestroyStack(stack_t *stack)
{
    free(stack->buffer);
    free(stack);
}
void Push(stack_t *stack, const void *item)
{
    assert(stack->top < stack->capacity);
    memcpy((char *)stack->buffer + (stack->top * stack->element_size), item, stack->element_size);
    ++stack->top;
}
void Pop(stack_t *stack)
{
    assert(stack->top != 0);
    --stack->top;
}

void *Peek(stack_t *stack)
{
    assert(stack->top != 0);
    return (char *)stack->buffer + ((stack->top - 1) * stack->element_size);
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

int isMatchingPair(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

int isClosedBreaking(char *str, stack_t *stack)
{
    int i = 0;
    size_t size = strlen(str);
    int is_matching = 0;
    int is_empty = 0;


    for (i = 0; i < size; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            Push(stack, (str + i));
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            is_matching = isMatchingPair(*(char*)Peek(stack), str[i]);
            is_empty = IsEmpty(stack);
            Pop(stack);
            if(is_empty || !is_matching)
            {
                return 0;
            }
        }
        
    }
    return IsEmpty(stack);;
}



int main()
{
    stack_t *new_stack = CreateStack(15, 1);
    assert(15 == StackCapacity(new_stack));
    char buff[]=  "[()]{}{[()()]()}";
    int gg = isClosedBreaking(buff, new_stack);
    DestroyStack(new_stack);
    return 0;
}
