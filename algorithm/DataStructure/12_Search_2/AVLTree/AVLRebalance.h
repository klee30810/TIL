#ifndef __AVL_REBALANCE_H__
#define __AVL_REBALANCE_H__

#include "BinaryTree4.h"

// 트리 리밸런싱
// 다른 함수들은 Rebalance 함수 실행시 모두 함께 호출되므로 
// 굳이 헤더파일에 모든 함수 선언을 쓸 필요는 없다.
BTreeNode * Rebalance(BTreeNode ** pRoot);

#endif