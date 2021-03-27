#include <stdio.h>
#include "BinarySearchTree.h"
#include "BinaryTree3.h"

int main()
{
    BTreeNode * bstRoot;            // bstRoot : BST 루트 노드 가리킴
    BTreeNode * sNode;

    BSTMakeAndInit(&bstRoot);       // Binary Search Tree 생성 및 초기화

    BSTInsert(&bstRoot, 9);         
    BSTInsert(&bstRoot, 1);         
    BSTInsert(&bstRoot, 6);         
    BSTInsert(&bstRoot, 2);         
    BSTInsert(&bstRoot, 8);         
    BSTInsert(&bstRoot, 3);         
    BSTInsert(&bstRoot, 5);         
    BSTInsert(&bstRoot, 1);         

    // 1 탐색
    sNode = BSTSearch(bstRoot, 1);
    if(sNode == NULL)
        printf("Search failure \n");
    else
        printf("Searched key : %d \n", BSTGetNodeData(sNode));

    // 4 탐색
    sNode = BSTSearch(bstRoot, 4);
    if(sNode == NULL)
        printf("Search failure \n");
    else
        printf("Searched key : %d \n", BSTGetNodeData(sNode));

    // 6 탐색
    sNode = BSTSearch(bstRoot, 6);
    if(sNode == NULL)
        printf("Search failure \n");
    else
        printf("Searched key : %d \n", BSTGetNodeData(sNode));

    // 7 탐색
    sNode = BSTSearch(bstRoot, 7);
    if(sNode == NULL)
        printf("Search failure \n");
    else
        printf("Searched key : %d \n", BSTGetNodeData(sNode));

    return 0;
}