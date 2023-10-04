#include <assert.h>
#include <stddef.h> /*NULL*/

typedef struct Node node_t;

struct Node
{
    int *data;
    node_t *next;
};

int HasLoop(const node_t *head)
{
    int res = 0;
    node_t *fast_iter = (node_t *)head;
    node_t *slow_iter = (node_t *)head;

    assert(NULL != head);

    while (NULL != fast_iter && NULL != fast_iter->next)
    {
        slow_iter = slow_iter->next;
        fast_iter = fast_iter->next->next;
        if (slow_iter == fast_iter)
        {
            res = 1;
            RemoveLoop(slow_iter, head);
            break;
        }
    }

    return res;
}

void RemoveLoop(node_t *meet_point, node_t *head)
{
    node_t *tmp = head;

    /*this check is needed when slow and fast both meet
    at the head of the LL eg: 1->2->3->4->5 and then
    5->next = 1 i.e the head of the LL*/
    if(meet_point == head)
    {
        while(meet_point->next != head)
        {
            meet_point = meet_point->next;
        }
    }
    else
    {
        while (tmp->next != meet_point)
        {
            tmp = tmp->next;
            meet_point = meet_point->next;
        }
    }
    
    meet_point->next = NULL;
}
