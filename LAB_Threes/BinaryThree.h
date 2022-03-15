#pragma once
/// <summary>
/// ��������� ��������� ������
/// </summary>
struct BinaryTreeNode
{
	/// <summary>
	/// ������ ����
	/// </summary>
	int Data = 0;
	/// <summary>
	/// ��������� �� ����� ����
	/// </summary>
	BinaryTreeNode* Left = nullptr;
	/// <summary>
	/// ��������� �� ������ ����
	/// </summary>
	BinaryTreeNode* Right = nullptr;
};

//TODO: ��������� ������
struct BinaryTree
{
	BinaryTreeNode* Root;
};


/// <summary>
/// �������� ������
/// </summary>
/// <param name="nodeTree">���� ������</param>
/// <param name="element">�������</param>
// void CreateTree(BinaryTreeNode* nodeTree, int element);

/// <summary>
/// �������� ��������� ������
/// </summary>
/// <param name="nodeTree">������ ������</param>
/// <param name="element">����������� �������</param>
/// <returns>������ ������</returns>
BinaryTreeNode* CreateTree(BinaryTreeNode* nodeTree, int element);

/// <summary>
/// ���������� �������� � ������
/// </summary>
/// <param name="nodeTree">����</param>
/// <param name="element">�������</param>
/// <returns>����</returns>
BinaryTreeNode* AddElement(BinaryTreeNode* nodeTree, int element);


void ShowTreeNew(BinaryTreeNode* nodeTree, int tabCount);

/// <summary>
/// ����� ��������
/// </summary>
/// <param name="nodeTree">����</param>
/// <param name="element">�������</param>
/// <returns>��������� ����</returns>
BinaryTreeNode* SearchElement(BinaryTreeNode* nodeTree, int element);

/// <summary>
/// �������� ��������
/// </summary>
/// <param name="nodeTree">����</param>
/// <param name="element">�������</param>
/// <returns>����</returns>
BinaryTreeNode* DeleteElement(BinaryTreeNode* nodeTree, int element);

/// <summary>
/// ����� ������������� �������� � ������
/// </summary>
/// <param name="nodeTree">����</param>
/// <returns>����</returns>
BinaryTreeNode* MaximumElement(BinaryTreeNode* nodeTree);

/// <summary>
/// ����� ������������ �������� � ������
/// </summary>
/// <param name="nodeTree">����</param>
/// <returns>����</returns>
BinaryTreeNode* MinimumElement(BinaryTreeNode* nodeTree);

/// <summary>
/// �������� ������
/// </summary>
/// <param name="nodeTree">����</param>
void DeleteBinaryTree(BinaryTreeNode* nodeTree);