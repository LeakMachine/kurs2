#pragma once
#include <stddef.h>

template <class Type> class CNode;
template <class Type> class CTree;

template <class Type>
class CNode {
public:
	Type data;
	CNode* left;
	CNode* right;
	CNode* parent;

public:
	CNode() {
		left = nullptr;
		right = nullptr;
	}
	CNode(Type _data) {
		data = _data;
		left = nullptr;
		right = nullptr;
	}

	friend class CTree<Type>;
};

template <class Type>
class CTree {
protected:
	CNode<Type>* root;
	CNode<Type>* insert(CNode<Type>* _node, Type _data);
public:
	void insert(Type _data);
	bool find(Type _data);
	void remove(Type _data);
};

template <class Type>
class CTreeF : private CTree<Type> {
private:
	int size = 0;
protected:
	CNode<Type>* insert(CNode<Type>* _node, Type _data) {
		if (_node == NULL || size == 0 )
		{
			_node = new CNode<Type>;
			_node->data = _data;
			_node->left = NULL;
			_node->right = NULL;
			_node->parent = NULL;
			size++;
		}
		else if (_node->data < _data)
		{
			_node->right = insert(_node->right, _data);
			_node->right->parent = _node;
			size++;
		}
		else
		{
			_node->left = insert(_node->left, _data);
			_node->left->parent = _node;
			size++;
		}

		return _node;
	}
	CNode<Type>* find(CNode<Type>* _node, Type _data) {
		if (_node == NULL) {
			return NULL;
		}
		if (_node->data == _data) {
			return _node;
		}
		if (_node->data < _data) {
			return find(_node->right, _data);
		}
		else {
			return find(_node->left, _data);
		}
	}
	Type findMin(CNode<Type>* _node) {
		if (_node == NULL) {
			return -1;
		} if (_node->left == NULL) {
			return _node->data;
		}
		else {
			return findMin(_node->left);
		}
	}
	Type findMax(CNode<Type>* _node) {
		if (_node == NULL) {
			return -1;
		} if (_node->right == NULL) {
			return _node->data;
		}
		else {
			return findMin(_node->right);
		}
	}
	Type successor(CNode<Type>* _node) {
		if (_node->right == NULL) {
			return findMin(_node->right);
		}
		else {
			CNode<Type>* parentNode = _node->parent;
			CNode<Type>* currentNode = _node;

			while ((parentNode != NULL) &&
				(currentNode == parentNode->right))
			{
				currentNode = parentNode;
				parentNode = currentNode->parent;
			}

			if (parentNode == NULL) {
				return -1;
			}
			else {
				parentNode->data;
			}
		}

	}
	Type predecessor(CNode<Type>* _node) {
		if (node->Left != NULL)
		{
			return FindMax(node->left);
		}
		else
		{
			CNode<Type>* parentNode = _node->parent;
			CNode<Type>* currentNode = _node;

			while ((parentNode != NULL) &&
				(currentNode == parentNode->left))
			{
				currentNode = parentNode;
				parentNode = currentNode->parent;
			}

			if (parentNode == NULL) {
				return -1;
			}
			else {
				parentNode->data;
			}
		}
	}
	CNode<Type>* remove(CNode<Type>* _node, Type _data) {
		if (_node == NULL) {
			return NULL;
		}
		if (_node->data == _data) {
			if (_node->left == NULL && _node->right == NULL) {
				_node == NULL;
			}
			if (_node->left == NULL && _node->right != NULL) {
				_node->right->parent = _node->parent;
				_node = _node->right;
			}
			if (_node->left != NULL && _node->right == NULL) {
				_node->left->parent = _node->parent;
				_node = _node->left;
			}
			else
			{
				int successorKey = successor(_data);
				node->data = successorKey;
				node->right = remove(node->right, successorKey);
			}
		}
		else if (node->data < _data)
			node->right = remove(node->right, _data);
		else
			node->left = remove(node->left, _data);

		return _node;
	}
public:
	Type predecessor(Type _data)
	{
		CNode<Type>* keyNode = find(root, _data);

		if (keyNode == NULL) {
			return -1;
		}
		else {
			return predecessor(keyNode);
		}
	}
	Type successor(Type _data) {
		CNode<Type>* keyNode = find(root, _data);
		if (keyNode == NULL) {
			return -1;
		}
		else {
			return successor(keyNode);
		}
	}
	void insert(Type _data) {
		root = insert(root, _data);
	}
	bool find(Type _data) {
		CNode<Type>* result = find(root, _data);
		if (result == NULL) {
			return false;
		}
		else {
			return true;
		}
	}
	void remove(Type _data) {
		root = remove(root, key);
	}
	Type findMin(Type _data) {
		return findMin(root);
	}
	Type findMax(Type _data) {
		return findMax(root);
	}
};