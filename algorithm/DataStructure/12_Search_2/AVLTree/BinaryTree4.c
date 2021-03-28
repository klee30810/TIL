#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree4.h"

BTreeNode * MakeBTreeNode()
{
  BTreeNode * nd = (BTreeNode *)malloc(sizeof(BTreeNode));
  nd->left = NULL;
  nd->right = NULL;
  return nd;
}

BTData GetData(BTreeNode * bt)
{
  return bt->data;
}

void SetData(BTreeNode * bt, BTData data)
{
  bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt)
{
  return bt->left;
}

BTreeNode * GetRightSubTree(BTreeNode * bt)
{
  return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
  if(main->left != NULL)
    free(main->left);  // 만약 하부 노드가 있었으면 메모리 누수
  
  main->left = sub;
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
  if(main->right != NULL)
    free(main->right);
  
  main->right = sub;
}

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
  if(bt==NULL)
    return;

  action(bt->data);
  PreorderTraverse(bt->left, action);
  PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
  if(bt == NULL)
    return;

  InorderTraverse(bt->left, action);
  action(bt->data);
  InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
  if(bt==NULL)
    return;

  PostorderTraverse(bt->left, action);
  PostorderTraverse(bt->right, action);
  action(bt->data);
}

BTreeNode * RemoveLeftSubTree(BTreeNode * bt)
{
  BTreeNode * delNode;

  if (bt != NULL)
  {
    delNode = bt->left;
    bt->left = NULL;
  }

  return delNode;
}

BTreeNode * RemoveRightSubTree(BTreeNode * bt)
{
  BTreeNode * delNode;

  if(bt != NULL)
  {
    delNode = bt->right;
    bt->right = NULL;
  }

  return delNode;
}

void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
  main->left = sub;
}

void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
  main->right = sub;
}

void ShowIntData(int data)
{
  printf("%d ", data);
}

void DeleteTree(BTreeNode * bt)
{
  if(bt==NULL)
    return;

  free(bt->left);
  free(bt->right);

  printf("free data : %d \n", bt->data);
  free(bt);
}