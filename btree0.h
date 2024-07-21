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

void preOrder(node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

#endif