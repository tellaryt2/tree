#pragma once

/// <summary>
/// струтура узла декартового дерева
/// </summary>
struct TreapNode
{
	/// <summary>
	/// данные узла
	/// </summary>
	int Key;
	/// <summary>
	/// приоритет узла
	/// </summary>
	int Priority;
	/// <summary>
	/// указатель на левый узел
	/// </summary>
	TreapNode* Left = nullptr;
	/// <summary>
	/// указатель на правый узел
	/// </summary>
	TreapNode* Right = nullptr;
};

/// <summary>
/// структура декартового дерева
/// </summary>
struct Treap
{
	/// <summary>
	/// корневой узел
	/// </summary>
	TreapNode* Root;
};


/// <summary>
/// создание декартового дерева
/// </summary>
/// <param name="node">узел</param>
/// <param name="key">ключ</param>
/// <param name="priority">приоритет</param>
/// <param name="left">левый узел</param>
/// <param name="right">правый узел</param>
/// <returns>узел</returns>
TreapNode* CreationOfTreap(TreapNode* node, int key, int priority, TreapNode* left, TreapNode* right);

/// <summary>
/// неоптимизированное добавление узла
/// </summary>
/// <param name="node">узел</param>
/// <param name="key">ключ</param>
/// <param name="priority">приоритет</param>
void AddInTreapUnoptimised(Treap* node, int key, int priority);

/// <summary>
/// оптимизированное добавление
/// </summary>
/// <param name="treap">указатель на корень</param>
/// <param name="node">узел</param>
/// <param name="parent">указатель на родителя</param>
/// <param name="key">ключ</param>
/// <param name="priority">приоритет</param>
void AddInTreapOptomised(Treap* treap, TreapNode* node, TreapNode* parent, int key, int priority);

/// <summary>
/// разрезание дерева
/// </summary>
/// <param name="treapNode">уузел по которому режет</param>
/// <param name="key">ключ</param>
/// <param name="left">левый узел</param>
/// <param name="right">правый узел</param>
void Split(TreapNode* treapNode, int key, TreapNode*& left, TreapNode*& right);


void PrintTreapNew(TreapNode* node, int tabCount);

/// <summary>
/// удалить дерево
/// </summary>
/// <param name="node">узел</param>
void DeleteTreap(TreapNode* node);

/// <summary>
/// удалить дерево неоптимизированно
/// </summary>
/// <param name="treap">корень дерева</param>
/// <param name="key">ключ</param>
void DeleteTreapUnoptimised(Treap* treap, int key);

/// <summary>
/// удалить дерево оптимизированно
/// </summary>
/// <param name="treap">дерево декартово</param>
/// <param name="node">узел</param>
/// <param name="parent">указатель на родителя</param>
/// <param name="key">ключ</param>
void DeleteTreapOptimised(Treap* treap, TreapNode* node, TreapNode* parent, int key);

/// <summary>
/// поиск элемента в дереве
/// </summary>
/// <param name="node">узел</param>
/// <param name="key">ключ</param>
/// <returns>узел</returns>
TreapNode* SearhElementInTreap(TreapNode* node, int key);

/// <summary>
/// склеиваение дерева
/// </summary>
/// <param name="left">узел</param>
/// <param name="right">узел</param>
/// <returns>узел</returns>
TreapNode* Merge(TreapNode* left, TreapNode* right);

