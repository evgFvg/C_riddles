
#include <stdlib.h> /*malloc*/
#include <stdio.h>  /*perror*/
#include <string.h> /*memcpy*/
#include <assert.h>

typedef struct stack stack_t;
typedef struct queue queue_t;

stack_t *CreateStack(size_t capacity, size_t element_size);
void DestroyStack(stack_t *stack);
void Push(stack_t *stack, const void *item);
void Pop(stack_t *stack);
void *Peek(stack_t *stack);
int IsEmpty(const stack_t *stack);
size_t StackSize(const stack_t *stack);
size_t StackCapacity(const stack_t *stack);

void QueueEnqueue(queue_t *que, const void *data);
void *QueueDequeue(queue_t *que);

struct stack
{
    void *buffer;
    size_t top;
    size_t capacity;
    size_t element_size;
};

struct queue
{
    stack_t *in;
    stack_t *out;
};

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
    return (void *)((char *)stack->buffer + ((stack->top - 1) * stack->element_size));
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

void QueueEnqueue(queue_t *q, const void *data)
{
    Push(q->in, data);
}

void *QueueDequeue(queue_t *q)
{
    void *elm = NULL;
    if (1 == IsEmpty(q->out))
    {
        while (IsEmpty(q->in) == 0)
        {
            elm = Peek(q->in);
            Push(q->out, elm);
            Pop(q->in);
        }
    }
    elm = Peek(q->out);
    Pop(q->out);

    return elm;
}

int main(void)
{
    stack_t *st1 = NULL;
    stack_t *st2 = NULL;
    queue_t *que = (queue_t *)malloc(sizeof(queue_t));

    int num1 = 1;
    int num2 = 2;
    int num3 = 3;

    st1 = CreateStack(10, 4);
    st2 = CreateStack(10, 4);

    que->in = st1;
    que->out = st2;

    QueueEnqueue(que, (void *)&num1);
    QueueEnqueue(que, (void *)&num2);
    QueueEnqueue(que, (void *)&num3);

    assert(num1 == *(int *)QueueDequeue(que));
    assert(num2 == *(int *)QueueDequeue(que));
    assert(num3 == *(int *)QueueDequeue(que));

    return 0;
}

