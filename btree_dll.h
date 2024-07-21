#ifndef __BINARY_TREE_DLL__
#define __BINARY_TREE_DLL__

#ifndef BT__NODE_DLL__
#define BT__NODE_DLL__
typedef struct node{
    int data;
    struct node *lchild, *rchild;
}node;
#endif

void conNode(int data){
    node* nw = (node*)malloc(sizeof(node));
    node->data = data;
    node->lchild = node->rchild = NULL;
}

#endif