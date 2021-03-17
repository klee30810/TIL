#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "ExpressionTree.h"
#include "ListBaseStack.h"

BTreeNode * MakeExpTree(char exp[])
{
  /*
  - 피연산자는 스택으로 옮긴다.
  - 연산자를 만나면 스택에서 두 개의 피연산자 꺼내 자식노드로 연결
  - 자식 노드를 연결해서 만들어진 트리는 다시 스택으로 옮긴다.
  - 완성 결과를 스택에 저장하고, 수식트리의 root node 주소값을 반환한다.
  */
  Stack stack;
  BTreeNode * pnode;
  int expLen = strlen(exp);
  int i;
  
  for(i=0; i<expLen; i++)
  {
    pnode = MakeBTreeNode();

    if(isdigit(exp[i]))					// 피연산자라면
    {
      SetData(pnode, exp[i]-'0');  // 문자를 정수로 변경
    }
    else	// 연산자라면
    {
      MakeRightSubTree(pnode, SPop(&stack));
      MakeLeftSubTree(pnode, SPop(&stack));
      SetData(pnode, exp[i]);
    }

    SPush(&stack, pnode);
  }
  
  return SPop(&stack);
}

int EvaluateExpTree(BTreeNode * bt)    // 수식 트리 계산
{
    int op1, op2;

    op1 = GetData(GetLeftSubTree(bt));      // 첫 연산자
    op2 = GetData(GetRightSubTree(bt));      // 둘째 연산자

    switch(GetData(bt))
    {
        case '+':
            return op1 + op2;
            
        case '-':
            return op1 - op2;
            
        case '*':
            return op1 * op2;
            
        case '/':
            return op1 / op2;
            
    }

    return 0;
}

void ShowNodeData(int data)
{
    if(0<=data && data <=9)
        printf("%d ", data);     // 피연산자 출력
    else
        printf("%c ", data);     // 연산자 출력
}

void ShowPrefixTypeExp(BTreeNode * bt)
{
    PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode * bt)
{
    InorderTraverse(bt, ShowNodeData);
}

void ShowPostfixTypeExp(BTreeNode * bt)
{
    PostorderTraverse(bt, ShowNodeData);
}