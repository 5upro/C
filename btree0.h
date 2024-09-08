#ifndef __BINARY_TREE_DLL__
#define __BINARY_TREE_DLL__

#ifndef BT__NODE_DLL__
#define BT__NODE_DLL__
typedef struct node{
    int data;
    struct node *lchild, *rchild;
}node;
#endif

node* conNode(int data){
    node* nw = (node*)malloc(sizeof(node));
    nw->data = data;
    nw->rchild = NULL;
    nw->lchild = NULL;
    return nw;
}

void preOrder(node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}

void postOrder(node* root){
    if(root!=NULL){
        postOrder(root->lchild);
        postOrder(root->rchild);
        printf("%d ", root->data);
    }
}

void inOrder(node* root){
    if(root!=NULL){
        inOrder(root->lchild);
        printf("%d ", root->data);
        inOrder(root->rchild);
    }
}

int isBST(node* root){
    static node* prev = NULL; 
    if(root!=NULL){
        if(!isBST(root->lchild)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        isBST(root->rchild);
    }
    else{
        return 1;
    }
}

void morrisinOrder(node* root){
    node *current = root;
    while(current!=NULL){
        if(current->lchild!=NULL){
            node* pred = current->lchild;
            while(pred->rchild!=NULL && pred->rchild != current) pred = pred->rchild;
            if(pred->rchild==NULL){
                pred->rchild = current;
                current = current->lchild;
            }
            else{
                pred->rchild = NULL;
                printf("%d ", current->data);
                current = current->rchild;
            }
        }
        else{
            printf("%d ", current->data);
            current = current->rchild;
        }
    }
}

void morrispreOrder(node* root){
    node* current = root;
    while(current!=NULL){
        if(current->lchild==NULL){
            printf("%d ", current->data);
            current = current->rchild;
        }
        else{
            node* pred = current->lchild;
            for(; pred->rchild!=NULL && pred->rchild!=current; pred = pred->rchild);
            if(pred->rchild==NULL){
                printf("%d ", current->data);
                pred->rchild = current;
                current = current->lchild;
            }
            else{
                pred->rchild = NULL;
                current = current->rchild;
            }
        }
    }
}

int morrisBST(node* root){
    node *current = root, *prev = NULL;
    while(current!=NULL){
        if(current->lchild!=NULL){
            node* pred = current->lchild;
            while(pred->rchild!=NULL && pred->rchild != current) pred = pred->rchild;
            if(pred->rchild==NULL){
                pred->rchild = current;
                current = current->lchild;
            }
            else{
                pred->rchild = NULL;
                if(prev!=NULL && prev->data >= current->data) return 0;
                prev = current;
                current = current->rchild;
            }
        }
        else{
            if(prev!=NULL && prev->data >= current->data) return 0;
            prev = current;
            current = current->rchild;
        }
    }
    return 1;
}

int maxDepth(node *root){
    int currLevel=0, maxD = 0;
    void maxDepth_helper(node *root){
        if(root->lchild!=NULL || root->rchild!=NULL){
            if(currLevel==maxD){
                maxD++;
            }
            if(root->lchild!=NULL){
                currLevel++;
                maxDepth_helper(root->lchild);
            }
            if(root->rchild!=NULL){
                currLevel++;
                maxDepth_helper(root->rchild);
            }
        }
        currLevel--;
    }
    maxDepth_helper(root);
    return maxD;
}

#endif