#include <iostream>
#include "BinaryThree.h"
#include "Treap.h"
#include <string>

using namespace std;

/// <summary>
/// �� ���� ������� ����� � int ����������
/// </summary>
/// <returns>��������</returns>
int GetInteger()
{
	int value;
	while (!(cin >> value))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "������� �����, � �� ������" << endl;
	}
	return value;
}

 ///<summary>
 ///������� ����� ��������
 ///</summary>
 ///<param name="messenger">���������</param>
 ///<returns>�����</returns>
int GetCount(string messenge)
{
	cout << messenge;
	while (true)
	{
		int size = GetInteger();
		if (size < 0)
		{
			cout << "������! �� ����� ������������� �����!" << endl;
		}
		else
		{
			return size;
		}
	}
}

//TODO: XML

/// <summary>
/// ����� �������� ������
/// </summary>
/// <param name="nodeTree">����</param>
/// <param name="tabCount">���������� ��������</param>
void ShowTreeNew(BinaryTreeNode* nodeTree, int tabCount)
{
	if (nodeTree != nullptr)
	{
		ShowTreeNew(nodeTree->Right, tabCount + 1);
		cout << string(tabCount, '\t') << nodeTree->Data << endl;
		ShowTreeNew(nodeTree->Left, tabCount + 1);
	}
	else
	{
		cout << string(tabCount, '\t') << '_' << endl;
	}
}

/// <summary>
/// ����� ����������� ������
/// </summary>
/// <param name="node">����</param>
/// <param name="tabCount">���������� ��������</param>
void PrintTreapNew(TreapNode* node, int tabCount)
{
	if (node != nullptr)
	{
		
		PrintTreapNew(node->Right, tabCount + 1);
		cout << string(tabCount, '\t') << node->Key << "(" << node->Priority << ")" << endl;
		PrintTreapNew(node->Left, tabCount + 1);
	}
	else
	{
		cout << string(tabCount, '\t') << '_' << endl;
	}
}

void MenuBinaryTree()
{
	//BinaryTreeNode* newTreeNode = new BinaryTreeNode();
	BinaryTree* newTree = new BinaryTree();
	cout << "1 - �������� ��������� ������" << endl;
	cout << "2 - ���������� �������� � �������� ������" << endl;
	cout << "3 - �������� �������� ��������� ������" << endl;
	cout << "4 - ����� ������������ �������� � ������" << endl;
	cout << "5 - ����� ������������� �������� � ������" << endl;
	cout << "6 - ����� �������� � ������" << endl;
	cout << "7 - �������� ��������� ������" << endl;


	while(true)
	{
		
		cout << "������� �������: ";
		int command = GetInteger();
		switch (command)
		{
			case 1:
			{
				/*int StartPush[10];
				int lenght = GetCount("������� ����� ��������� ������: ");
				cout << "������� ��������� ������ ������: ";
				for (int i = 0; i < lenght; i++)
				{
					StartPush[i] = GetInteger();
					if (i == 0)
					{
						CreateTree(newTreeNode, StartPush[0]);
					}
					else
					{
						BinaryTreeNode* tempNode = AddElement(newTreeNode, StartPush[i]);
					}
					ShowTreeNew(newTreeNode, 0);
				}*/

				cout << "������� ������ ������: ";
				int element = GetInteger();
				newTree->Root = CreateTree(newTree->Root, element);
				ShowTreeNew(newTree->Root, 0);
				break;

			}

			case 2:
			{
				/*cout << "������� �������, ������� ������ ��������: ";
				int element = GetInteger();
				AddElement(newTreeNode, element);
				ShowTreeNew(newTreeNode, 0);*/

				cout << "������� �������, ������� ������ ��������: ";
				int element = GetInteger();
				AddElement(newTree->Root, element);
				ShowTreeNew(newTree->Root, 0);
				break;
			}

			case 3:
			{
				/*cout << "������� �������, ������� ������ �������: ";
				int element = GetInteger();
				BinaryTreeNode* deleteNode = DeleteElement(newTreeNode, element);
				cout << "������� ������";
				ShowTreeNew(newTreeNode, 0);*/

				cout << "������� �������, ������� ������ �������: ";
				int element = GetInteger();
				BinaryTreeNode* deleteNode = DeleteElement(newTree->Root, element);
				cout << "������� ������";
				ShowTreeNew(newTree->Root, 0);
				break;
			}

			case 4:
			{
				/*BinaryTreeNode* minElement = MinimumElement(newTreeNode);
				cout << "����������� ������� � ������: " << minElement->Data << endl;*/

				BinaryTreeNode* minElement = MinimumElement(newTree->Root);
				cout << "����������� ������� � ������: " << minElement->Data << endl;
				break;
			}

			case 5:
			{
				/*BinaryTreeNode* maxElement = MaximumElement(newTreeNode);
				cout << "������������ ������� � ������: " << maxElement->Data << endl;*/
				BinaryTreeNode* maxElement = MaximumElement(newTree->Root);
				cout << "������������ ������� � ������: " << maxElement->Data << endl;
				break;
			}

			case 6:
			{
				/*cout << "������� �������, ������� ������ �����: ";
				int element = GetInteger();
				BinaryTreeNode* search = SearchElement(newTreeNode, element);
				if (search == nullptr)
				{
					cout << "������ �������� ���" << endl;
				}
				else
				{
					cout << "����� ������� ����" << endl;
				}*/

				cout << "������� �������, ������� ������ �����: ";
				int element = GetInteger();
				BinaryTreeNode* search = SearchElement(newTree->Root, element);
				if (search == nullptr)
				{
					cout << "������ �������� ���" << endl;
				}
				else
				{
					cout << "����� ������� ����" << endl;
				}
				break;
			}

			case 7:
			{
				/*DeleteBinaryTree(newTreeNode);
				cout << "������ �������" << endl;*/

				DeleteBinaryTree(newTree->Root);
				cout << "������ �������" << endl;
				return;
			}

			default:
			{
				cout << "������� ����� �� 1 �� 7" << endl;
				break;
			}

		}
	}
}

void MenuTreap()
{
	Treap* newTreap = new Treap();
	cout << "1 - �������� ����������� ������" << endl;
	cout << "2 - ���������� � ���������� ������ (������������������)" << endl;
	cout << "3 - ���������� � ���������� ������ (���������������)" << endl;
	cout << "4 - ����� �������� � ������" << endl;
	cout << "5 - �������� �������� (�����������������)" << endl;
	cout << "6 - �������� �������� (��������������)" << endl;
	cout << "10 - �������� ������" << endl;

	while(true)
	{
		cout << "������� �������: ";
		int command = GetInteger();

		switch (command)
		{
			case 1:
			{
				cout << "������� ���� ����� ������: ";
				int key = GetInteger();
				srand(time(nullptr));
				int priority = rand() % 100;
				newTreap->Root = CreationOfTreap(newTreap->Root, key, priority, nullptr, nullptr);
				PrintTreapNew(newTreap->Root, 0);
				break;
			}

			case 2:
			{
				//TODO: duplication
				cout << "������� ���� ������� ������ ��������: ";
				int key = GetInteger();
				srand(time(nullptr));
				int priority = rand() % 100;
				AddInTreapUnoptimised(newTreap, key, priority);
				PrintTreapNew(newTreap->Root, 0);
				break;
			}

			case 3:
			{
				//TODO: duplication
				cout << "������� ���� ������� ������ ��������: ";
				int key = GetInteger();
				srand(time(nullptr));
				int priority = rand() % 100;
				AddInTreapOptomised(newTreap, newTreap->Root, nullptr, key, priority);
				PrintTreapNew(newTreap->Root, 0);
				break;
			}

			case 4:
			{
				//TODO: duplication
				cout << "������� ���� �������� ��������: ";
				int key = GetInteger();
				TreapNode* answer = nullptr;
				answer = SearhElementInTreap(newTreap->Root, key);
				if (answer == nullptr)
				{
					cout << "������� �� ������!;" << endl;
				}
				else
				{
					cout << "������� � ������ " << answer->Key << " ����� ��������� " << answer->Priority << endl;
				}
				PrintTreapNew(newTreap->Root, 0);
				break;
			}

			case 5:
			{
				//TODO: duplication
				cout << "������� ���� ��������: ";
				int key = GetInteger();
				TreapNode* tempNode = nullptr;
				tempNode = SearhElementInTreap(newTreap->Root, key);
				if (tempNode == nullptr)
				{
					cout << "������� �������� ��� � ������!" << endl;
				}
				else
				{
					DeleteTreapUnoptimised(newTreap, key);
				}
				PrintTreapNew(newTreap->Root, 0);
				break;
			}

			case 6:
			{
				//TODO: duplication
				cout << "������� ���� ���������� ��������: ";
				int key = GetInteger();
				TreapNode* tempNode = nullptr;
				tempNode = SearhElementInTreap(newTreap->Root, key);
				if (tempNode == nullptr)
				{
					cout << "������� �������� ��� � ������!" << endl;
				}
				else
				{
					DeleteTreapOptimised(newTreap, newTreap->Root, nullptr, key);
				}
				PrintTreapNew(newTreap->Root, 0);
				break;
			}

			case 10:
			{
				DeleteTreap(newTreap->Root);
				cout << "������ �������!" << endl;
				return;
			}

			default:
			{
				cout << "������������ �������" << endl;
				break;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	while(true)
	{
		cout << "1 - ���� ������ � �������� �������" << endl;
		cout << "2 - ���� ������ � ���������� �������" << endl;
		cout << "3 - ����� � �� ���������" << endl;

		cout << "������� �������: ";
		int command = GetInteger();
		switch (command)
		{
			case 1:
			{
				MenuBinaryTree();
				break;
			}

			case 2:
			{
				MenuTreap();
				break;
			}

			case 3:
			{
				return 0;
			}

			default:
			{
				cout << "������������ �������" << endl;
				break;
			}
		}
	}

	return 0;
}

