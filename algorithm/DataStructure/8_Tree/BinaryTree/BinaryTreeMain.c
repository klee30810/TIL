#include <stdio.h>
#include "BinaryTree.h"

int main()
{
  BTreeNode * bt1 = MakeBTreeNode();  // 노드 bt1 생성
  BTreeNode * bt2 = MakeBTreeNode();  // 노드 bt2 생성
  BTreeNode * bt3 = MakeBTreeNode();  // 노드 bt3 생성
  BTreeNode * bt4 = MakeBTreeNode();  // 노드 bt4 생성
  
  SetData(bt1, 1);
  SetData(bt2, 2);
  SetData(bt3, 3);
  SetData(bt4, 4);
  

  MakeLeftSubTree(bt1, bt2);
  MakeRightSubTree(bt1, bt3);
  MakeLeftSubTree(bt2, bt4);
  
  printf("%d \n", GetData(GetLeftSubTree(bt1)));
  printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));

  return 0;
}