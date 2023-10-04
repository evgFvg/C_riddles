#include <stdio.h>/*printf*/
#include <assert.h>

typedef struct Node node_t;

struct Node
{
    int data;
    node_t *next;
};

void RearrangeSLL(node_t *head);
void SwapNodesData(node_t *n1, node_t *n2);
int Is_SLL_Rearranged(node_t *head);

int main()
{
    int a = 5, b = 6, c = 7, d = 8, e = 9, w = 3;
    node_t head, n2, n3, n4, n5, tail;

    head.data = a;
    head.next = &n2;

    n2.data = b;
    n2.next = &n3;

    n3.data = c;
    n3.next = &n4;

    n4.data = d;
    n4.next = &n5;

    n5.data = e;
    n5.next = &tail;

    tail.data = w;
    tail.next = NULL;

    RearrangeSLL(&head);
    assert(0 == Is_SLL_Rearranged(&head));
    
    printf("All tests have been passed\n");

    return 0;
}

int Is_SLL_Rearranged(node_t *head)
{
    node_t *prev = head;
    node_t *curr = head->next;
    int res = 1;

    while (NULL != curr && 1 == res)
    {
        res = curr->data > prev->data;
        prev = curr->next;

        if (NULL == curr->next)
        {
            break;
        }

        curr = curr->next->next;
    }

    return !res;
}

void RearrangeSLL(node_t *head)
{
    node_t *prev = NULL;
    node_t *curr = NULL;

    assert(NULL != head);

    prev = head;
    curr = head->next;

    while (curr != NULL)
    {
        if (prev->data > curr->data)
        {
            SwapNodesData(prev, curr);
        }
        if (NULL != curr->next && curr->next->data > curr->data)
        {
            SwapNodesData(curr, curr->next);
        }

        prev = curr->next;

        if (NULL == curr->next)
        {
            break;
        }

        curr = curr->next->next;
    }
}

void SwapNodesData(node_t *n1, node_t *n2)
{
    int tmp = n1->data;
    n1->data = n2->data;
    n2->data = tmp;
}
