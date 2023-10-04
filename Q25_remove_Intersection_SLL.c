#include <assert.h>
#include <stddef.h> /*NULL*/

typedef struct Node node_t;

struct Node
{
    int *data;
    node_t *next;
};

node_t *FindIntersection(node_t *head_1, node_t *head_2);
void RemoveIntersection(node_t *head_1, node_t *intersec);

int main()
{
    node_t *intersection = NULL;

    node_t node_1, node_2, node_3, node_4, node_5;
    int num_1 = 1, num_2 = 2, num_3 = 3, num_4 = 4, num_5 = 5;
    node_t node_6, node_7, node_8;
    int num_6 = 6, num_7 = 7, num_8 = 8, num_9 = 9;

    node_1.data = &num_1;
    node_1.next = &node_2;

    node_2.data = &num_2;
    node_2.next = &node_3;

    node_3.data = &num_3;
    node_3.next = &node_4;

    node_4.data = &num_4;
    node_4.next = &node_5;

    node_5.data = &num_5;
    node_5.next = NULL;
    /*************************************/

    node_6.data = (void *)&num_6;
    node_6.next = &node_7;

    node_7.data = (void *)&num_7;
    node_7.next = &node_8;

    node_8.data = (void *)&num_8;
    node_8.next = &node_3;  /*intersec*/


    intersection = FindIntersection(&node_1, &node_6);

    if(NULL != intersection)
    {
        RemoveIntersection(&node_6, intersection);
    }

    return 0;
}
void RemoveIntersection(node_t *head_1, node_t *intersec)
{
    node_t *current = head_1;

    while(current->next != intersec)
    {
        current = current->next;
    }

    current->next = NULL;
}

node_t *FindIntersection(node_t *head_1, node_t *head_2)
{
    node_t *iter_1 = head_1;
    node_t *iter_2 = head_2;

    assert(NULL != head_1);
    assert(NULL != head_2);

    while (iter_1 != iter_2)
    {
        /* When the first list reaches its end, redirect it to the
        head of the second list*/
        iter_1 = (NULL == iter_1) ? head_2 : iter_1->next;
        iter_2 = (NULL == iter_2) ? head_1 : iter_2->next;
    }

    return iter_1;
}
