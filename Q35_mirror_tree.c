#include <assert.h> 
#include <stdio.h>  /* printf */

#include "bst.h"

static int CmpNumbers(const void *a, const void *b);
static void PrintTreeRec(bst_node_t *node, int level);
static void MirrorTree(bst_node_t *node);
static void TestMirror();
static void SwapNodes(bst_node_t **n1, bst_node_t **n2);


/*******************************************************/

int main()
{

    TestMirror();
    printf("All tests have been passed\n");
    
    return 0;
}


/********************************Static functions*********************/


static void TestMirror()
{
    int ar[] = {4, 2, 5, 1, 3};
    int i = 0;
    size_t ar_size = sizeof(ar) / sizeof(int);
    size_t height = 0;
    bst_t *bst = BSTCreate(CmpNumbers);

    for (i = 0; i < ar_size; ++i)
    {
        BSTInsert(bst, (void *)(&ar[i]));
    }
    PrintTreeRec(bst->dummy_root.children[LEFT], 0);
    printf("********************************\n");
    MirrorTree(bst->dummy_root.children[LEFT]);
    PrintTreeRec(bst->dummy_root.children[LEFT], 0);
}

static void PrintTreeRec(bst_node_t *node, int level)
{
    int i = 0;
    if (NULL == node)
        return;

    PrintTreeRec(node->children[RIGHT], level + 1);
    for (i = 0; i < level; ++i)
    {
        printf("        ");
    }
    printf("%d\n", *(int *)node->data);
    PrintTreeRec(node->children[LEFT], level + 1);
}

static void MirrorTree(bst_node_t *node)
{
    if (NULL == node)
    {
        return;
    }

    MirrorTree(node->children[LEFT]);
    MirrorTree(node->children[RIGHT]);

    SwapNodes(&node->children[LEFT], &node->children[RIGHT]);
}

static void SwapNodes(bst_node_t **n1, bst_node_t **n2)
{
    bst_node_t *tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

static int CmpNumbers(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}


