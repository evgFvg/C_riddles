#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;

struct node
{
    int *num;
    node_t *parent;
    node_t *left_child;
    node_t *right_child;
    node_t *next;
    node_t *prev;
};

typedef enum child_side
{
    LEFT = 0,
    RIGHT = 1,
    NONE = 2
} child_side_t;

node_t *GetSmallest(node_t *node);
node_t *GetNext(node_t *node);
child_side_t GetChildSide(node_t *node);
node_t *BSTToSDLL(node_t *root);
void PrintSDLL(node_t *head);
void InitNode(node_t *node, int *num, node_t *parent, node_t *left_child, node_t *right_child);
static void PrintTreeRec(node_t *node, int level);

node_t *GetSmallest(node_t *node)
{
    while (NULL != node->left_child)
    {
        node = node->left_child;
    }

    return node;
}

node_t *GetNext(node_t *node)
{
    child_side_t side = LEFT;

    if (NULL != node->right_child)
    {
        node = node->right_child;

        return GetSmallest(node);
    }

    side = GetChildSide(node);

    if (side == LEFT)
    {
        return node->parent;
    }

    while (RIGHT == side)
    {
        node = node->parent;
        side = GetChildSide(node);

        if (NONE == side)
        {
            return NULL;
        }
    }

    node = node->parent;

    return node;
}

node_t *BSTToSDLL(node_t *root)
{
    node_t *head = GetSmallest(root);
    node_t *runner = head;
    node_t *tmp = NULL;
    node_t *next = NULL;
    runner->prev = NULL;

    while (NULL != GetNext(runner))
    {
        next = GetNext(runner);
        runner->next = next;
        tmp = runner;
        runner = next;
        runner->prev = tmp;
    }

    return head;
}

child_side_t GetChildSide(node_t *node)
{
    if (NULL == node->parent)
    {
        return NONE;
    }

    if (node->parent->left_child == node)
    {
        return LEFT;
    }

    return RIGHT;
}

void InitNode(node_t *node, int *num, node_t *parent, node_t *left_child, node_t *right_child)
{
    node->num = num;
    node->parent = parent;
    node->left_child = left_child;
    node->right_child = right_child;
}

void PrintSDLL(node_t *head)
{
    node_t *run = GetSmallest(head);

    while (NULL != run)
    {
        printf("%2d -> ", *run->num);
        run = run->next;
    }

    printf("\n");
}

static void PrintTreeRec(node_t *node, int level)
{
    int i = 0;
    if (NULL == node)
        return;

    PrintTreeRec(node->right_child, level + 1);
    for (i = 0; i < level; ++i)
    {
        printf("        ");
    }
    printf("%d\n", *(int *)node->num);
    PrintTreeRec(node->left_child, level + 1);
}

int main()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    node_t *new_head = NULL;

    node_t node0 = {NULL};
    node_t node1 = {NULL};
    node_t node2 = {NULL};
    node_t node3 = {NULL};
    node_t node4 = {NULL};
    node_t node5 = {NULL};
    node_t node6 = {NULL};
    node_t node7 = {NULL};
    node_t node8 = {NULL};
    node_t node9 = {NULL};
    node_t node10 = {NULL};


    InitNode(&node0, &a[0], &node1, NULL, NULL);
    InitNode(&node1, &a[1], &node3, &node0, &node2);
    InitNode(&node2, &a[2], &node1, NULL, NULL);
    InitNode(&node3, &a[3], &node7, &node1, &node5);
    InitNode(&node4, &a[4], &node5, NULL, NULL);
    InitNode(&node5, &a[5], &node3, &node4, &node6);
    InitNode(&node6, &a[6], &node5, NULL, NULL);
    InitNode(&node7, &a[7], NULL, &node3, &node9); /*root*/
    InitNode(&node8, &a[8], &node9, NULL, NULL);
    InitNode(&node9, &a[9], &node7, &node8, &node10);
    InitNode(&node10, &a[10], &node9, NULL, NULL);

    PrintTreeRec(&node7,0);


	new_head = BSTToSDLL(&node7);

	PrintSDLL(new_head);


    return 0;
}

