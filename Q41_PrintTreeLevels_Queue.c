#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE (10)

typedef struct node node_t;

struct node
{
    int data;
    node_t *left;
    node_t *right;
};

typedef struct queue
{
    node_t **arr;
    int front;
    int rear;
} q_t;

node_t *NewNode(int data);
int Height(node_t *node);
void CurrentLevel(node_t *root, int level);
void PrintByLevel(node_t *root);

/***********************Functions***********************************/

node_t *NewNode(int data)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));

    if (NULL != node)
    {
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }

    return node;
}
q_t *CreateQueue()
{
    q_t *q = (q_t *)malloc(sizeof(q_t));

    if (NULL != q)
    {
        q->arr = (node_t **)malloc(sizeof(node_t *) * MAX_SIZE);
        if (NULL == q->arr)
        {
            free(q);
            return NULL;
        }

        q->front = -1;
        q->rear = -1;
    }
}

int QueueisEmpty(q_t *q)
{
    if (q->front == -1 || q->front > q->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int QueueisFull(q_t *q)
{
    if (q->rear == MAX_SIZE - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Enqueue(q_t *q, node_t *data)
{
    if (1 == QueueisFull(q))
    {
        return;
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = data;
    }
}

void Dequeue(q_t *q)
{
    if (1 == QueueisEmpty(q))
    {
        return;
    }
    else
    {
        q->front++;
    }
}

node_t *QueuePeek(q_t *q)
{
    node_t *res = NULL;

    if (1 == QueueisEmpty(q))
    {
        return NULL;
    }
    else
    {
        res = q->arr[q->front];
        return res;
    }
}

void LevelOrder(node_t *root)
{
    if (root == NULL)
    {
        return;
    }

    q_t *q = CreateQueue();

    if (NULL == q)
    {
        return;
    }

    Enqueue(q, root);

    while (QueueisEmpty(q) == 0)
    {
        node_t *node = QueuePeek(q);
        printf("%d ", node->data);
        Dequeue(q);

        if (node->left != NULL)
        {
            Enqueue(q, node->left);
        }
        if (node->right != NULL)
        {
            Enqueue(q, node->right);
        }
    }
    printf("\n");
    /*DstroyQueue*/
}

int main()
{
    node_t *root = NewNode(1);
    root->left = NewNode(2);
    root->right = NewNode(3);
    root->left->left = NewNode(4);
    root->left->right = NewNode(5);

    LevelOrder(root);

    return 0;
}
