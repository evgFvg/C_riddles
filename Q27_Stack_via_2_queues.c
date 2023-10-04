#include <stddef.h>
#include <assert.h>
#include "../ds/include/queue.h"

typedef struct stack stack_t;

struct stack 
{
	queue_t *q1;
	queue_t *q2;
};

stack_t *CreateStack()
{
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
    if (NULL == stack)
    {
        return NULL;
    }
    stack->q1 = QueueCreate();

    if (NULL == stack->q1)
    {
        free(stack);
        return NULL;
    }

    stack->q2 = QueueCreate();

    if (NULL == stack->q2)
    {
        QueueDestroy(stack->q1);
        free(stack);
        return NULL;
    }

    return stack;
}

void StackDestroy(stack_t *stack)
{
    QueueDestroy(stack->q1);
    QueueDestroy(stack->q2);
    free(stack);

}

void StackPush(stack_t *stack, void *data)
{
    QueueEnqueue(stack->q1, data);
}

void StackPop(stack_t *stack)
{
    void *data_q1 = NULL;

    while(1 != QueueSize(stack->q1))
    {
        data_q1 = QueuePeek(stack->q1);
        QueueEnqueue(stack->q2, data_q1);
        QueueDequeue(stack->q1);
    }

    QueueDequeue(stack->q1);
    SwapQueues(stack);
}

static void SwapQueues(stack_t *stack)
{
    queue_t *tmp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = tmp;
}

void *StackPeek(stack_t *stack)
{
    void *data = NULL;

    while( 0 == QueueIsEmpty(stack->q1))
    {
        data = QueuePeek(stack->q1);
        QueueEnqueue(stack->q2, data);
        QueueDequeue(stack->q1);
    }
    
    SwapQueues(stack);
    return data;
}


int main()
{
    stack_t *stack = CreateStack();
    int a = 5, b = 6, c = 7, d = 8;
    int data = 0;

    StackPush(stack, &a);
    StackPush(stack, &b);
    StackPush(stack, &c);
    StackPush(stack, &d);

    assert(d ==  *(int *)StackPeek(stack));
    StackPop(stack);

    assert(c ==  *(int *)StackPeek(stack));

    StackPop(stack);
    
    assert(b ==  *(int *)StackPeek(stack));


    StackDestroy(stack);
    printf("All Queue tests have been passed\n");
    return 0;
}

