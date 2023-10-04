#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;

struct node
{
    int data;
    node_t *left;
    node_t *right;
};

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

int Height(node_t *node)
{
    int left_h = 0;
    int right_h = 0;

    if (node == NULL)
    {
        return 0;
    }
    else
    {
        left_h = Height(node->left);
        right_h = Height(node->right);

        return left_h > right_h ? left_h + 1 : right_h + 1;
    }
}

void CurrentLevel(node_t *root, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (level == 1)
    {
        printf("%d ", root->data);
    }

    CurrentLevel(root->left, level - 1);
    CurrentLevel(root->right, level - 1);
}

void PrintByLevel(node_t *root)
{
    int height = Height(root);
    int i = 0;

    for (i = 1; i <= height; i++)
    {
        CurrentLevel(root, i);
    }

    printf("\n");
}

int main()
{
    node_t *root = NewNode(1);
    root->left = NewNode(2);
    root->right = NewNode(3);
    root->left->left = NewNode(4);
    root->left->right = NewNode(5);

    PrintByLevel(root);

    return 0;
}

