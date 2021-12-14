#include "bintree.h"

int main()
{
	BinTree* pBinTree;
	BinTreeNode pBinTreeNode;
	
	pBinTreeNode.visited = 0;
	pBinTreeNode.pLeftChild = NULL;
	pBinTreeNode.pRightChild = NULL;
	pBinTreeNode.data = 'A';
	pBinTree = makeBinTree(pBinTreeNode);
	pBinTreeNode.data = 'B';
	insertLeftChildNodeBT(pBinTree->pRootNode, pBinTreeNode);
	pBinTreeNode.data = 'C';
	insertRightChildNodeBT(pBinTree->pRootNode, pBinTreeNode);
	pBinTreeNode.data = 'D';
	insertLeftChildNodeBT(pBinTree->pRootNode->pLeftChild, pBinTreeNode);
	pBinTreeNode.data = 'E';
	insertRightChildNodeBT(pBinTree->pRootNode->pLeftChild, pBinTreeNode);
	pBinTreeNode.data = 'F';
	insertLeftChildNodeBT(pBinTree->pRootNode->pRightChild, pBinTreeNode);
	pBinTreeNode.data = 'G';
	insertRightChildNodeBT(pBinTree->pRootNode->pRightChild, pBinTreeNode);
	pBinTreeNode.data = 'H';
	insertLeftChildNodeBT(pBinTree->pRootNode->pLeftChild->pLeftChild, pBinTreeNode);
	pBinTreeNode.data = 'I';
	insertRightChildNodeBT(pBinTree->pRootNode->pLeftChild->pLeftChild, pBinTreeNode);
	pBinTreeNode.data = 'J';
	insertLeftChildNodeBT(pBinTree->pRootNode->pLeftChild->pRightChild, pBinTreeNode);
	pBinTreeNode.data = 'K';
	insertRightChildNodeBT(pBinTree->pRootNode->pRightChild->pLeftChild, pBinTreeNode);
	pBinTreeNode.data = 'L';
	insertLeftChildNodeBT(pBinTree->pRootNode->pRightChild->pRightChild, pBinTreeNode);
	pBinTreeNode.data = 'M';
	insertRightChildNodeBT(pBinTree->pRootNode->pRightChild->pRightChild, pBinTreeNode);
	// printf("%c\n", getRootNodeBT(pBinTree)->data);
	// printf("%c\n", getLeftChildNodeBT(pBinTree->pRootNode)->data);
	// printf("%c\n", getRightChildNodeBT(pBinTree->pRootNode)->data);
	printf("====preorder====\n");
	preorderTraversalBinTree(pBinTree->pRootNode);
	printf("\n");
	printf("====Inorder====\n");
	inorderTraversalBinTree(pBinTree->pRootNode);
	printf("\n");
	printf("====postorder====\n");
	postorderTraversalBinTree(pBinTree->pRootNode);
	printf("\n");
}