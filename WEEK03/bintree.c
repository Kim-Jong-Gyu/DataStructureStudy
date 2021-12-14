#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
    BinTree *pBinTree;

    pBinTree = (BinTree *)malloc(sizeof(BinTree));
    if(!pBinTree)
        return (NULL);
    pBinTree->pRootNode = (BinTreeNode *)malloc(sizeof(BinTreeNode));
    if(!pBinTree->pRootNode)
        return (NULL);
    *(pBinTree->pRootNode) = rootNode;
    return (pBinTree);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
    if(!pBinTree)
        return (NULL);
    if(!pBinTree->pRootNode)
        return (NULL);
    return (pBinTree->pRootNode);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
    if(!pParentNode)
        return (NULL);
    pParentNode->pLeftChild = (BinTreeNode *)malloc(sizeof(BinTreeNode));
    if(!pParentNode->pLeftChild)
        return (NULL);
    *(pParentNode->pLeftChild) = element;
    return (pParentNode);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
    if(!pParentNode)
        return (NULL);
    pParentNode->pRightChild = (BinTreeNode *)malloc(sizeof(BinTreeNode));
    if(!pParentNode->pRightChild)
        return (NULL);
    *(pParentNode->pRightChild) = element;
    return (pParentNode);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
    if(!pNode)
        return (NULL);
    if(!pNode->pLeftChild)
        return (NULL);
    return (pNode->pLeftChild);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
    if(!pNode)
        return (NULL);
    if(!pNode->pRightChild)
        return (NULL);
    return (pNode->pRightChild);
}

void deleteBinTree(BinTree* pBinTree)
{
    deleteBinTreeNode(pBinTree->pRootNode);
    free(pBinTree);
    pBinTree = NULL;
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
    free(pNode->pLeftChild);
	pNode->pLeftChild = NULL;
	free(pNode->pRightChild);
	pNode->pRightChild = NULL;
	free(pNode);
	pNode = NULL;
}
// V -> L -> R
void preorderTraversalBinTree(BinTreeNode* pNode)
{
    if(!pNode)
        return ;
    printf("%c ", pNode->data);
    if(pNode->pLeftChild)
        preorderTraversalBinTree(pNode->pLeftChild);
    if(pNode->pRightChild)
        preorderTraversalBinTree(pNode->pRightChild);
}
// L -> V -> R
void inorderTraversalBinTree(BinTreeNode* pNode)
{
    if(!pNode)
        return ;
    if(pNode->pLeftChild)
        inorderTraversalBinTree(pNode->pLeftChild);
    printf("%c ", pNode->data);
    if(pNode->pRightChild)
        inorderTraversalBinTree(pNode->pRightChild);
}
// L -> R -> V
void postorderTraversalBinTree(BinTreeNode* pNode)
{
     if(!pNode)
        return ;
    if(pNode->pLeftChild)
        inorderTraversalBinTree(pNode->pLeftChild);
    if(pNode->pRightChild)
        inorderTraversalBinTree(pNode->pRightChild);
    printf("%c ", pNode->data);
}
// 위 쪽 node들 부터 아래방향으로 차례로 방문
void levelorderTraversalBinTree(BinTreeNode* pNode);