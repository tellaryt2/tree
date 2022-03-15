#include "BinaryThree.h"

using namespace std;

//void CreateTree(BinaryTreeNode* nodeTree, int element)
//{
//	nodeTree->Data = element;
//}

BinaryTreeNode* CreateTree(BinaryTreeNode* nodeTree, int element)
{
	nodeTree = new BinaryTreeNode;
	nodeTree->Data = element;

	return nodeTree;
}

BinaryTreeNode* AddElement(BinaryTreeNode* nodeTree, int element)
{
	if (nodeTree == nullptr)
	{
		nodeTree = new BinaryTreeNode;
		nodeTree->Data = element;
		nodeTree->Left = nullptr;
		nodeTree->Right = nullptr;
	}
	else if (nodeTree->Data > element)
	{
		nodeTree->Left = AddElement(nodeTree->Left, element);
	}
	else if (nodeTree->Data <= element)
	{
	nodeTree->Right = AddElement(nodeTree->Right, element);
	}
	return nodeTree;
}

BinaryTreeNode* SearchElement(BinaryTreeNode* nodeTree, int element)
{
	while (true)
	{
		if (nodeTree == nullptr)
		{
			return nodeTree;
		}
		if (element > nodeTree->Data)
		{
			nodeTree = nodeTree->Right;
			continue;
		}
		if (element < nodeTree->Data)
		{
			nodeTree = nodeTree->Left;
			continue;
		}
		if (element == nodeTree->Data)
		{
			return nodeTree;
		}
	}
}

BinaryTreeNode* DeleteElement(BinaryTreeNode* nodeTree, int element)
{
	if (nodeTree == nullptr)
	{
		return nodeTree;
	}

	if (nodeTree->Data > element)
	{
		nodeTree->Left = DeleteElement(nodeTree->Left, element);
	}
	else if (nodeTree->Data < element)
	{
		nodeTree->Right = DeleteElement(nodeTree->Right, element);
	}
	else if (nodeTree->Data = element)
	{
		if (nodeTree->Left == nullptr && nodeTree->Right == nullptr)
		{
			delete nodeTree;
			nodeTree = nullptr;
		}
		else if (nodeTree->Left == nullptr && nodeTree->Right != nullptr)
		{
			BinaryTreeNode* tempNode = nodeTree;
			nodeTree = nodeTree->Right;
			delete tempNode;
			tempNode = nullptr;
		}
		else if (nodeTree->Left != nullptr && nodeTree->Right == nullptr)
		{
			BinaryTreeNode* tempNode = nodeTree;
			nodeTree = nodeTree->Left;
			delete tempNode;
			tempNode = nullptr;
		}
		else if (nodeTree->Left != nullptr && nodeTree->Right != nullptr)
		{
			BinaryTreeNode* min = MinimumElement(nodeTree->Right);
			nodeTree->Data = min->Data;
			nodeTree->Right = DeleteElement(nodeTree->Right, min->Data);
		}
	}
	return nodeTree;
}


BinaryTreeNode* MaximumElement(BinaryTreeNode* nodeTree)
{
	while (nodeTree->Right != nullptr)
	{
		nodeTree = nodeTree->Right;
	}
	return nodeTree;
}

BinaryTreeNode* MinimumElement(BinaryTreeNode* nodeTree)
{
	while (nodeTree->Left != nullptr)
	{
		nodeTree = nodeTree->Left;
	}
	return nodeTree;
}

void DeleteBinaryTree(BinaryTreeNode* nodeTree)
{
	if (nodeTree == nullptr)
	{
		return;
	}
	DeleteBinaryTree(nodeTree->Left);
	DeleteBinaryTree(nodeTree->Right);
	delete nodeTree;
}