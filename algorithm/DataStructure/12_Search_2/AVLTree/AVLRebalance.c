#include <stdio.h>
#include "BinaryTree4.h"

// 트리 높이 계산
int GetHeight(BTreeNode * bst)
{
    int leftH, rightH;

    if(bst == NULL)
        return 0;

    leftH = GetHeight(GetLeftSubTree(bst));     // 완쪽 계산
    rightH = GetHeight(GetRightSubTree(bst));   // 오른쪽 계산

    // 큰 값의 높이 반환
    if(leftH > rightH)
        return leftH + 1;
    else
        return rightH + 1;
}

// 두 서브트리의 높이의 차(균형 인수) 반환
int GetHeightDiff(BTreeNode * bst)
{
    int lsh, rsh;       // left right sub tree height

    if(bst==NULL)
        return 0;

    lsh = GetHeight(GetLeftSubTree(bst));       // left subtree height
    rsh = GetHeight(GetRightSubTree(bst));      // right subtree height

    return lsh - rsh;       // 균형 인수 계산 결과 반환
}

BTreeNode * RotateLL(BTreeNode * bst)
{
    BTreeNode * pNode, * cNode;

    // pNode & cNode가 LL회전을 위해 적절한 위치를 가리킴
    pNode = bst;
    cNode = GetLeftSubTree(pNode);

    // LL회전
    ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
    ChangeRightSubTree(cNode, pNode);

    // 변경된 주소값 반환
    return cNode;
}

BTreeNode * RotateRR(BTreeNode * bst)
{
    BTreeNode * pNode, * cNode;

    // pNode & cNode가 RR회전을 위해 적절한 위치를 가리킴
    pNode = bst;
    cNode = GetRightSubTree(pNode);

    // LL회전
    ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
    ChangeLeftSubTree(cNode, pNode);

    // 변경된 주소값 반환
    return cNode;
}

BTreeNode * RotateLR(BTreeNode * bst)
{
    BTreeNode * pNode, * cNode;

    // pNode & cNode가 LR회전을 위해 적절한 위치 가리킴
    pNode = bst;
    cNode = GetLeftSubTree(pNode);

    // LR회전
    ChangeLeftSubTree(pNode, RotateRR(cNode));      // 부분 RR회전
    return RotateLL(pNode);
}

BTreeNode * RotateRL(BTreeNode * bst)
{
    BTreeNode * pNode, * cNode;

    pNode = bst;
    cNode = GetRightSubTree(pNode);

    ChangeRightSubTree(pNode, RotateLL(cNode));
    return RotateRR(pNode);
}

// 트리 리밸런싱
BTreeNode * Rebalance(BTreeNode ** pRoot)
{
    int hDiff = GetHeightDiff(*pRoot);

    // 균형 인수가 +2 이상이면 LL or LR 상태
    if(hDiff > 1)           // 왼쪽 서브트리 방향으로 높이가 2 이상 크다면
    {
        if(GetHeightDiff(GetLeftSubTree(*pRoot))>0)
            *pRoot = RotateLL(*pRoot);
        else
            *pRoot = RotateLR(*pRoot);
    }

    // 균형 인수가 -2 이하이면 RR or RL 상태
    if(hDiff < -1)          // 오른쪽 서브트리 방향으로 2 이상 크다면
    {
        if(GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
            *pRoot = RotateRR(*pRoot);
        else
            *pRoot = RotateRL(*pRoot);
    }

    return *pRoot;
}