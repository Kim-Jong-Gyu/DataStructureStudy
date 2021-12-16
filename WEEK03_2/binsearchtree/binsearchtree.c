#include "binsearchtree.h"

BinSearchTree* createBinSearchTree()
{
    BinSearchTree *pBinSearchTree;

    pBinSearchTree = (BinSearchTree *)malloc(sizeof(BinSearchTree));
    if(!pBinSearchTree)
        return (NULL);
    pBinSearchTree->pRootNode = NULL;
    return (pBinSearchTree);
}

int insertElementBST(BinSearchTree* pBinSearchTree, BinSearchTreeNode element)
{
    BinSearchTreeNode *pNewNode;
    BinSearchTreeNode *pParentNode;

    if(!pBinSearchTree)
        return (FALSE);
    // 루트 노드가 없는경우
    pNewNode = (BinSearchTreeNode *)malloc(sizeof(BinSearchTreeNode));
    *pNewNode = element;
    if(pBinSearchTree->pRootNode == NULL)
    {
        pBinSearchTree->pRootNode = pNewNode;
        return(TRUE);
    }
    //위치 찾기
    pParentNode = pBinSearchTree->pRootNode;
    while(pParentNode != NULL)
    {
        if(element.key == pParentNode->key)
        {
            printf("중복된 키 : %d",element.key);
            return (FALSE);
        }
        else if(element.key < pParentNode->key)
        {
            if(pParentNode->pLeftChild == NULL)
            {
                pParentNode->pLeftChild = pNewNode;
                return (TRUE);
            }
            else
                pParentNode = pParentNode->pLeftChild;
        }
        else
        {
            if(pParentNode->pRightChild == NULL)
            {
                pParentNode->pRightChild = pNewNode;
                return (TRUE);
            }
            else
                pParentNode = pParentNode->pRightChild;
        }
    }
    return (FALSE);
}

int deleteElementBST(BinSearchTree* pBinSearchTree, int key)
{
    BinSearchTreeNode *pDelNode = NULL;
    BinSearchTreeNode *pParentNode = NULL;
    BinSearchTreeNode *pSuccessorNode = NULL;
    BinSearchTreeNode *pPreNode = NULL;
    BinSearchTreeNode *pChildNode = NULL;

    if(!pBinSearchTree)
        return (FALSE);
    pDelNode = pBinSearchTree->pRootNode;
    while(pDelNode != NULL)
    {
        if(key == pDelNode->key)
            break;
        pParentNode = pDelNode;
        if(key < pDelNode->key)
            pDelNode = pDelNode->pLeftChild;
        else
            pDelNode = pDelNode->pRightChild;
    }
    // 해당하는 key 값이 없다.
    if(pDelNode == NULL)
        return(FALSE);
    if(pDelNode->pLeftChild == NULL && pDelNode->pRightChild == NULL)
    {
        if(pParentNode != NULL)
        {
            if(pParentNode->pLeftChild == pDelNode)
                pParentNode->pLeftChild = NULL;
            else
                pParentNode->pRightChild = NULL;
        }
        else
            pBinSearchTree->pRootNode = NULL;
    }
    else if(pDelNode->pLeftChild != NULL && pDelNode->pRightChild != NULL)
    {
        pPreNode = pDelNode;
        pSuccessorNode = pDelNode->pLeftChild;
        //왼족 subtree에서 가장 큰값 찾기 .
        while(pSuccessorNode->pRightChild != NULL)
        {
            // successor parent node 를 가르키기위해
            pPreNode = pSuccessorNode;
            pSuccessorNode = pSuccessorNode->pRightChild;
        }
        pPreNode->pRightChild = pSuccessorNode->pLeftChild;
        pSuccessorNode->pLeftChild = pDelNode->pLeftChild;
        pSuccessorNode->pRightChild = pDelNode->pRightChild;
        if(pParentNode != NULL)
        {
            if(pParentNode->pLeftChild == pDelNode)
                pParentNode->pLeftChild = pSuccessorNode;
            else
                pParentNode->pRightChild = pSuccessorNode;
        }
        else
            pBinSearchTree->pRootNode = pSuccessorNode;
    }
    else
    {
        if(pDelNode->pLeftChild != NULL)
            pChildNode = pDelNode->pLeftChild;
        else
            pChildNode = pDelNode->pRightChild;
        if(pParentNode != NULL)
        {
            if(pParentNode->pLeftChild == pDelNode)
                pParentNode->pLeftChild = pChildNode;
            else
                pParentNode->pRightChild = pChildNode;
        }
        else
            pBinSearchTree->pRootNode = pChildNode;
    }
    free(pDelNode);
    return (TRUE);
}
// 재귀 부분은 모르겠습니다. 
BinSearchTreeNode* searchRecursiveBST(BinSearchTree* pBinSearchTree, int key)
{
    return(searchInternalRecursiveBST(pBinSearchTree->pRootNode,key));
}

BinSearchTreeNode* searchInternalRecursiveBST(BinSearchTreeNode* pTreeNode, int key)
{
    BinSearchTreeNode *pReturn = NULL;

    if(!pTreeNode)
        return (NULL);
    if(pTreeNode->key > key)
        return(searchInternalRecursiveBST(pTreeNode->pLeftChild,key));
    else if(pTreeNode->key < key)
        return(searchInternalRecursiveBST(pTreeNode->pRightChild,key));
    else
        return (pTreeNode);
}

BinSearchTreeNode* searchBST(BinSearchTree* pBinSearchTree, int key)
{
    BinSearchTreeNode *pReturn;

    if (!pBinSearchTree)
        return (NULL);
    pReturn = pBinSearchTree->pRootNode;
    while(pReturn != NULL)
    {
        if(key == pReturn->key)
            break;
        else if(key < pReturn->key)
            pReturn = pReturn->pLeftChild;
        else
            pReturn = pReturn->pRightChild;
    }
    return (pReturn);
}

void deleteBinSearchTree(BinSearchTree* pBinSearchTree)
{
    deleteBinSearchTreeInternal(pBinSearchTree->pRootNode);
}

void deleteBinSearchTreeInternal(BinSearchTreeNode* pTreeNode)
{
    deleteBinSearchTreeInternal(pTreeNode->pLeftChild);
    deleteBinSearchTreeInternal(pTreeNode->pRightChild);
    free(pTreeNode);
}

void display_node(BinSearchTreeNode* t)
{
    if(t == NULL)
    {
        return;
    }
    printf("NODE [%d] > ", t->key);

    if(t->pLeftChild != NULL)
    {
        printf("LEFT [%d] ", t->pLeftChild->key);
    }
    if(t->pRightChild != NULL)
    {
        printf("RIGHT [%d]", t->pRightChild->key);
    }
    printf("\n");

    if(t->pLeftChild)
    {
        display_node(t->pLeftChild);
    }
    if(t->pRightChild)
    {
        display_node(t->pRightChild);
    }
}