#include "binsearchtree.h"

int main()
{
    BinSearchTree *pTree;
    BinSearchTreeNode inputNode;
    int key;

    inputNode.pLeftChild = NULL;
    inputNode.pRightChild = NULL;
    inputNode.value = 0;
    pTree = createBinSearchTree();
    inputNode.key = 30;
    insertElementBST(pTree,inputNode);
    inputNode.key = 20;
    insertElementBST(pTree,inputNode);
    inputNode.key = 10;
    insertElementBST(pTree,inputNode);
    inputNode.key = 24;
    insertElementBST(pTree,inputNode);
    inputNode.key = 6;
    insertElementBST(pTree,inputNode);
    inputNode.key = 14;
    insertElementBST(pTree,inputNode);
    inputNode.key = 22;
    insertElementBST(pTree,inputNode);
    inputNode.key = 40;
    insertElementBST(pTree,inputNode);
    inputNode.key = 34;
    insertElementBST(pTree,inputNode);
    inputNode.key = 46;
    insertElementBST(pTree,inputNode);
    display_node(pTree->pRootNode);

    key = 30;
    deleteElementBST(pTree, key);
    printf("after : delete 30\n");
    display_node(pTree->pRootNode);
    BinSearchTreeNode *tmp;
    printf("%d",searchInternalRecursiveBST(pTree->pRootNode, 40)->key);
}