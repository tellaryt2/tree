#include <iostream>
#include "BinaryThree.h"
#include "Treap.h"
#include <string>

using namespace std;

/// <summary>
/// не дает вводить буквы в int переменные
/// </summary>
/// <returns>значение</returns>
int GetInteger()
{
	int value;
	while (!(cin >> value))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "Введите число, а не символ" << endl;
	}
	return value;
}

 ///<summary>
 ///функция ввода значения
 ///</summary>
 ///<param name="messenger">сообщение</param>
 ///<returns>число</returns>
int GetCount(string messenge)
{
	cout << messenge;
	while (true)
	{
		int size = GetInteger();
		if (size < 0)
		{
			cout << "ошибка! вы ввели отрицательную длину!" << endl;
		}
		else
		{
			return size;
		}
	}
}

//TODO: XML

/// <summary>
/// вывод бинарого дерева
/// </summary>
/// <param name="nodeTree">узел</param>
/// <param name="tabCount">количество отступов</param>
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
/// вывод декартового дерева
/// </summary>
/// <param name="node">узел</param>
/// <param name="tabCount">количество отступов</param>
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
	cout << "1 - создание бинарного дерева" << endl;
	cout << "2 - добавление элемента в бинарное дерево" << endl;
	cout << "3 - удаление элемента бинарного дерева" << endl;
	cout << "4 - поиск минимального элемента в дереве" << endl;
	cout << "5 - поиск максимального элемента в дереве" << endl;
	cout << "6 - поиск элемента в дереве" << endl;
	cout << "7 - удаление бинарного дерева" << endl;


	while(true)
	{
		
		cout << "введите команду: ";
		int command = GetInteger();
		switch (command)
		{
			case 1:
			{
				/*int StartPush[10];
				int lenght = GetCount("Введите длину начальных данных: ");
				cout << "Введите начальные данные дерева: ";
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

				cout << "Введите корень дерева: ";
				int element = GetInteger();
				newTree->Root = CreateTree(newTree->Root, element);
				ShowTreeNew(newTree->Root, 0);
				break;

			}

			case 2:
			{
				/*cout << "Введите элемент, который хотите добавить: ";
				int element = GetInteger();
				AddElement(newTreeNode, element);
				ShowTreeNew(newTreeNode, 0);*/

				cout << "Введите элемент, который хотите добавить: ";
				int element = GetInteger();
				AddElement(newTree->Root, element);
				ShowTreeNew(newTree->Root, 0);
				break;
			}

			case 3:
			{
				/*cout << "Введите элемент, который хотите удалить: ";
				int element = GetInteger();
				BinaryTreeNode* deleteNode = DeleteElement(newTreeNode, element);
				cout << "элемент удален";
				ShowTreeNew(newTreeNode, 0);*/

				cout << "Введите элемент, который хотите удалить: ";
				int element = GetInteger();
				BinaryTreeNode* deleteNode = DeleteElement(newTree->Root, element);
				cout << "элемент удален";
				ShowTreeNew(newTree->Root, 0);
				break;
			}

			case 4:
			{
				/*BinaryTreeNode* minElement = MinimumElement(newTreeNode);
				cout << "минимальный элемент в дереве: " << minElement->Data << endl;*/

				BinaryTreeNode* minElement = MinimumElement(newTree->Root);
				cout << "минимальный элемент в дереве: " << minElement->Data << endl;
				break;
			}

			case 5:
			{
				/*BinaryTreeNode* maxElement = MaximumElement(newTreeNode);
				cout << "максимальный элемент в дереве: " << maxElement->Data << endl;*/
				BinaryTreeNode* maxElement = MaximumElement(newTree->Root);
				cout << "максимальный элемент в дереве: " << maxElement->Data << endl;
				break;
			}

			case 6:
			{
				/*cout << "Введите элемент, который хотите найти: ";
				int element = GetInteger();
				BinaryTreeNode* search = SearchElement(newTreeNode, element);
				if (search == nullptr)
				{
					cout << "Такого элемента нет" << endl;
				}
				else
				{
					cout << "такой элемент есть" << endl;
				}*/

				cout << "Введите элемент, который хотите найти: ";
				int element = GetInteger();
				BinaryTreeNode* search = SearchElement(newTree->Root, element);
				if (search == nullptr)
				{
					cout << "Такого элемента нет" << endl;
				}
				else
				{
					cout << "такой элемент есть" << endl;
				}
				break;
			}

			case 7:
			{
				/*DeleteBinaryTree(newTreeNode);
				cout << "дерево удалено" << endl;*/

				DeleteBinaryTree(newTree->Root);
				cout << "дерево удалено" << endl;
				return;
			}

			default:
			{
				cout << "Введите число от 1 до 7" << endl;
				break;
			}

		}
	}
}

void MenuTreap()
{
	Treap* newTreap = new Treap();
	cout << "1 - создание декартового дерева" << endl;
	cout << "2 - добавление в декартовое дерево (неоптимизированное)" << endl;
	cout << "3 - добавление в декартовое дерево (оптимизированно)" << endl;
	cout << "4 - поиск элемента в дереве" << endl;
	cout << "5 - удаление элемента (неоптимизированно)" << endl;
	cout << "6 - удаление элемента (оптимизировано)" << endl;
	cout << "10 - удаление дерева" << endl;

	while(true)
	{
		cout << "введите команду: ";
		int command = GetInteger();

		switch (command)
		{
			case 1:
			{
				cout << "введите ключ корня дерева: ";
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
				cout << "введите ключ который хотите добавить: ";
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
				cout << "введите ключ который хотите добавить: ";
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
				cout << "Введите ключ искомого элемента: ";
				int key = GetInteger();
				TreapNode* answer = nullptr;
				answer = SearhElementInTreap(newTreap->Root, key);
				if (answer == nullptr)
				{
					cout << "Элемент не найден!;" << endl;
				}
				else
				{
					cout << "Элемент с ключем " << answer->Key << " имеет приоритет " << answer->Priority << endl;
				}
				PrintTreapNew(newTreap->Root, 0);
				break;
			}

			case 5:
			{
				//TODO: duplication
				cout << "Введите ключ элемента: ";
				int key = GetInteger();
				TreapNode* tempNode = nullptr;
				tempNode = SearhElementInTreap(newTreap->Root, key);
				if (tempNode == nullptr)
				{
					cout << "Данного элемента нет в дереве!" << endl;
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
				cout << "Введите ключ удаляемого элемента: ";
				int key = GetInteger();
				TreapNode* tempNode = nullptr;
				tempNode = SearhElementInTreap(newTreap->Root, key);
				if (tempNode == nullptr)
				{
					cout << "Данного элемента нет в дереве!" << endl;
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
				cout << "дерево удалено!" << endl;
				return;
			}

			default:
			{
				cout << "некорректная команда" << endl;
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
		cout << "1 - меню работы с бинарным деревом" << endl;
		cout << "2 - меню работы с декартовым деревом" << endl;
		cout << "3 - выход и из программы" << endl;

		cout << "введите команду: ";
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
				cout << "некорректная команда" << endl;
				break;
			}
		}
	}

	return 0;
}

