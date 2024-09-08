#include <stdio.h>
#include <btree0.h>
#include <stdlib.h>

int main(){
    node* r0 = conNode(4);
    node* r1 = conNode(2);
    node* r2 = conNode(6);
    node* r3 = conNode(1);
    node* r4 = conNode(3);
    node* r5 = conNode(5);
    node* r6 = conNode(7);
    node* r7 = conNode(8);
    node* r8 = conNode(10);
    r0->lchild = r1;
    r0->rchild = r2;
    r1->lchild = r3;
    r1->rchild = r4;
    r2->lchild = r5;
    r2->rchild = r6;
    r6->rchild = r7;
    r7->lchild = r8;
    /*      _4_
     *     /   \
     *    2     6
     *   / \   / \
     *  1   3 5   7
     *             \
     *              8
     *             /  
     *            10  
     */
    // r0->lchild = r1;
    // r1->lchild = r2;
    // r2->lchild = r3;
    // r3->lchild = r4;
    // r4->lchild = r5;
    // r5->lchild = r6;
    // r6->lchild = r7;
    /*               r0
     *              /
     *             r1
     *            /
     *           r2
     *          /
     *         r3 
     *        /
     *       r4 
     *      /
     *     r5
     *    /
     *   r6
     *  /
     * r7
     * 
     */
    // r0->rchild = r1;
    // r1->rchild = r2;
    // r2->rchild = r3;
    // r3->rchild = r4;
    // r4->rchild = r5;
    // r5->rchild = r6;
    // r6->rchild = r7;
    /* r0
     *  \
     *   r1
     *    \
     *     r2
     *      \
     *       r3 
     *        \
     *         r4 
     *          \
     *           r5
     *            \
     *             r6
     *              \
     *               r7
     * 
     */
    printf("postorder using recursion: ");   
    postOrder(r0);
    printf("\ninorder using recursion: ");   
    inOrder(r0);
    printf("\ninorder using mossisTrav: ");
    morrisinOrder(r0);
    printf("\ndeducing whether the B-tree is a BST or not: %d", morrisBST(r0));
    printf("\npreorder using morrisTrav: ");
    morrispreOrder(r0);
    int val = maxDepth(r0);
    printf("\nMax Depth using Recursion: %d", val);
}