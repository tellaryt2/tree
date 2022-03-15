#include "Treap.h"

using namespace std;

TreapNode* CreationOfTreap(TreapNode* node, int key, int priority, TreapNode* left, TreapNode* right)
{
	node = new TreapNode;
	node->Key = key;
	node->Priority = priority;
	node->Left = left;
	node->Right = right;
	
	return node;
}

void Split(TreapNode* treapNode, int key, TreapNode*& left, TreapNode*& right)
{
	if (treapNode == nullptr)
	{
		left = right = nullptr;
	}
	else if (key >= treapNode->Key)
	{
		Split(treapNode->Right, key, treapNode->Right, right);
		left = treapNode;
	}
	else if (key < treapNode->Key)
	{
		Split(treapNode->Left, key, left, treapNode->Left);
		right = treapNode;
	}
}


TreapNode* Merge(TreapNode* left, TreapNode* right)
{
	if (left == nullptr)
	{
		return right;
	}
	if (right == nullptr)
	{
		return left;
	}
	if (left->Priority > right->Priority)
	{
		left->Right = Merge(left->Right, right);
		return left;
	}
	else
	{
		right->Left = Merge(left, right->Left);
		return right;
	}
}

void AddInTreapUnoptimised(Treap* node, int key, int priority)
{
	TreapNode* left = nullptr;
	TreapNode* right = nullptr;
	Split(node->Root, key, left, right);
	TreapNode* newNode = nullptr;
	newNode = CreationOfTreap(newNode, key, priority, nullptr, nullptr);
	left = Merge(left, newNode);
	node->Root = Merge(left, right);
}

void AddInTreapOptomised(Treap* treap, TreapNode* node, TreapNode* parent, int key, int priority)
{
	if (node == nullptr)
	{
		node = CreationOfTreap(node, key, priority, nullptr, nullptr);
		if (treap->Root == nullptr)
		{
			treap->Root = node;
		}
		else if (parent != nullptr)
		{
			if (node->Key > parent->Key)
			{
				parent->Right = node;
			}
			else
			{
				parent->Left = node;
			}
		}
		return;
	}
	else if (node->Priority < priority)
	{
		TreapNode* left = nullptr;
		TreapNode* right = nullptr;
		Split(node, key, left, right);
		TreapNode* newNode = nullptr;
		newNode = CreationOfTreap(newNode, key, priority, left, right);
		if (parent != nullptr)
		{
			if (parent->Left == node)
			{
				parent->Left = newNode;
			}
			else
			{
				parent->Right = newNode;
			}
		}
		else
		{
			treap->Root = newNode;
		}
		return;
	}
	else if (key < node->Key)
	{
		return AddInTreapOptomised(treap, node->Left, node, key, priority);
	}
	else if (key > node->Key)
	{
		return AddInTreapOptomised(treap, node->Right, node, key, priority);
	}
}

TreapNode* SearhElementInTreap(TreapNode* node, int key)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	if (node->Key == key)
	{
		return node;
	}
	if (key < node->Key)
	{
		return SearhElementInTreap(node->Left, key);
	}
	else
	{
		return SearhElementInTreap(node->Right, key);
	}
}

void DeleteTreapUnoptimised(Treap* treap, int key)
{
	TreapNode* left = nullptr;
	TreapNode* right = nullptr;
	Split(treap->Root, key, left, right);
	TreapNode* newLeft = nullptr;
	TreapNode* newRight = nullptr;
	Split(left, key - 1, newLeft, newRight);
	treap->Root = Merge(newLeft, right);
	delete newRight;
}

void DeleteTreapOptimised(Treap* treap, TreapNode* node, TreapNode* parent, int key)
{
	if (key < node->Key)
	{
		DeleteTreapOptimised(treap, node->Left, node, key);
	}
	else if (key > node->Key)
	{
		DeleteTreapOptimised(treap, node->Right, node, key);
	}
	else
	{
		TreapNode* newNode = Merge(node->Left, node->Right);
		if (parent != nullptr)
		{
			if (parent->Left == node)
			{
				parent->Left = newNode;
			}
			else
			{
				parent->Right = newNode;
			}
		}
		else
		{
			treap->Root = newNode;
		}
		delete node;
	}
}

void DeleteTreap(TreapNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	DeleteTreap(node->Left);
	DeleteTreap(node->Right);
	delete node;
}