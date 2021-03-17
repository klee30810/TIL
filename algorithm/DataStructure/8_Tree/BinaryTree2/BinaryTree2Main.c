#include <stdio.h>
#include "BinaryTree2.h"

int main()
{
  BTreeNode * bt1 = MakeBTreeNode();  // 노드 bt1 생성
  BTreeNode * bt2 = MakeBTreeNode();  // 노드 bt2 생성
  BTreeNode * bt3 = MakeBTreeNode();  // 노드 bt3 생성
  BTreeNode * bt4 = MakeBTreeNode();  // 노드 bt4 생성
  BTreeNode * bt5 = MakeBTreeNode();
  BTreeNode * bt6 = MakeBTreeNode();
  
  SetData(bt1, 1);
  SetData(bt2, 2);
  SetData(bt3, 3);
  SetData(bt4, 4);
  SetData(bt5, 5);
  SetData(bt6, 6);

  MakeLeftSubTree(bt1, bt2);
  MakeRightSubTree(bt1, bt3);
  MakeLeftSubTree(bt2, bt4);
  MakeRightSubTree(bt2, bt5);
  MakeRightSubTree(bt3, bt6);
  
  PreorderTraverse(bt1, ShowIntData);
  printf("\n");
  InorderTraverse(bt1, ShowIntData);
  printf("\n");
  PostorderTraverse(bt1, ShowIntData);
  printf("\n");
  
  return 0;
}