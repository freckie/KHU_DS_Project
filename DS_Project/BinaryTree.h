#pragma once

#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include <iostream>

#include"BinaryTreeIterator.h"

namespace kmh
{
	/**
	*	���漱��.
	*/
	template <typename _Ty>
	class BinaryTreeIterator;

	template <typename _Ty>
	class BinaryTree;

	/**
	*	using.
	*/
	template <typename _Ty>
	using BTree = BinaryTree<_Ty>;
	template <typename _Ty>
	using BIterator = BinaryTreeIterator<_Ty>;

	// Tree �����ϴ� BTreeNode
	template <typename _Ty>
	struct BTreeNode
	{
		_Ty data;
		BTreeNode* left;
		BTreeNode* right;
		BTreeNode* up;

		BTreeNode() : left(nullptr), right(nullptr), up(nullptr) {}
		BTreeNode(_Ty data) : left(nullptr), right(nullptr), up(nullptr), data(data) {}
		BTreeNode(BTreeNode* up, _Ty data) : left(nullptr), right(nullptr), up(up), data(data) {}
		BTreeNode(BTreeNode* left, BTreeNode* right, BTreeNode* up, _Ty data)
			: left(left), right(right), up(up), data(data) {}
	};

	// Binary Tree
	template <typename _Ty>
	class BinaryTree
	{

	public:
		BinaryTree();
		~BinaryTree();

		bool is_empty() const;
		bool is_full() const;
		void make_empty();
		int length() const;
		bool add(_Ty _Item);
		bool remove(_Ty _Item);
		bool retrieve(_Ty& _Item);
		void print(std::ostream& _Out);

		BinaryTreeIterator<_Ty> begin();
		BinaryTreeIterator<_Ty> end();
		BinaryTreeIterator<_Ty> find(_Ty _Item);

	private:
		BTreeNode<_Ty>* _Root;

		int _count_nodes(BTreeNode<_Ty>* _Root);
		void _insert_node(BTreeNode<_Ty>*& _Prev, BTreeNode<_Ty>*& _Root, _Ty _Item);
		void _remove_node(BTreeNode<_Ty>*& _Root, _Ty _Item);
		void _retrieve_node(BTreeNode<_Ty>* _Root, _Ty& _Item);
		BTreeNode<_Ty>* _get_node(BTreeNode<_Ty>* _Root, _Ty& _Item);
		void _get_predecessor(BTreeNode<_Ty>* _Root, _Ty& _Item);
		void _print_in_order(BTreeNode<_Ty>* _Root, std::ostream& _Out);
		void _print_pre_order(BTreeNode<_Ty>* _Root, std::ostream& _Out);
		void _print_post_order(BTreeNode<_Ty>* _Root, std::ostream& _Out);
		BTreeNode<_Ty>* _get_next_node(BTreeNode<_Ty>* _Node);
	};

	// ������
	template <typename _Ty>
	BinaryTree<_Ty>::BinaryTree()
	{
		_Root = nullptr;
	}

	// �Ҹ���
	template <typename _Ty>
	BinaryTree<_Ty>::~BinaryTree()
	{
		make_empty();
	}

	// Tree�� ������� Ȯ��
	template <typename _Ty>
	bool BinaryTree<_Ty>::is_empty() const
	{
		return (_Root == nullptr);
	}

	// Tree�� Full���� Ȯ��
	template <typename _Ty>
	bool BinaryTree<_Ty>::is_full() const
	{
		BTreeNode<_Ty>* temp;
		try
		{
			temp = new BTreeNode<_Ty>;
			delete temp;
			return false;
		}
		catch (std::bad_alloc exception)
		{
			return true;
		}
	}

	// Tree�� ���
	template <typename _Ty>
	void BinaryTree<_Ty>::make_empty()
	{
		/*
		* ��� ���� �ڵ� �߰��ϱ�
		*/
		_Root = nullptr;
	}

	// Tree�� ������� Ȯ��
	template <typename _Ty>
	int BinaryTree<_Ty>::length() const
	{
		return _count_nodes(_Root);
	}

	// Tree�� BTreeNode �߰�
	template <typename _Ty>
	bool BinaryTree<_Ty>::add(_Ty _Item)
	{
		_insert_node(_Root, _Root, _Item);
		return true;
	}

	// Tree���� BTreeNode ����
	template <typename _Ty>
	bool BinaryTree<_Ty>::remove(_Ty _Item)
	{
		_remove_node(_Root, _Item);
		return true;
	}

	// Tree���� BTreeNode �˻�
	template <typename _Ty>
	bool BinaryTree<_Ty>::retrieve(_Ty& _Item)
	{
		_retrieve_node(_Root, _Item);
		return true;
	}

	// Tree ���
	template <typename _Ty>
	void BinaryTree<_Ty>::print(std::ostream& _Out)
	{
		cout << "[In-Order]" << endl;
		_print_in_order(_Root, _Out);
		cout << endl;
		cout << "[Pre-Order]" << endl;
		_print_pre_order(_Root, _Out);
		cout << endl;
		cout << "[Post-Order]" << endl;
		_print_post_order(_Root, _Out);
		cout << endl;
	}

	template<typename _Ty>
	BinaryTreeIterator<_Ty> BinaryTree<_Ty>::begin()
	{
		// �� ���� ��� ��ȯ
		BTreeNode<_Ty>* temp = _Root;
		while (temp->left != nullptr)
			temp = temp->left;

		return BinaryTreeIterator<_Ty>(temp);
	}

	template<typename _Ty>
	BinaryTreeIterator<_Ty> BinaryTree<_Ty>::end()
	{
		// �� ������ ��� ��ȯ
		BTreeNode<_Ty>* temp = _Root;
		while (temp->right != nullptr)
			temp = temp->right;

		return BinaryTreeIterator<_Ty>(temp->right);
	}

	template<typename _Ty>
	BinaryTreeIterator<_Ty> BinaryTree<_Ty>::find(_Ty _Item)
	{
		BTreeNode<_Ty>* temp = _get_node(_Root, _Item);
		return BinaryTreeIterator<_Ty>(temp);
	}

	///////////////////////
	// Private Functions //
	///////////////////////

	// node ���� count �Լ�
	template <typename _Ty>
	int BinaryTree<_Ty>::_count_nodes(BTreeNode<_Ty>* _Root)
	{
		if (_Root == nullptr)
			return 0;
		else
			return _count_nodes(_Root->left) + _count_nodes(_Root->right) + 1;
	}

	// node �߰�
	template <typename _Ty>
	void BinaryTree<_Ty>::_insert_node(BTreeNode<_Ty>*& prev, BTreeNode<_Ty>*& _Root, _Ty _Item)
	{
		// nullptr�� ���
		if (_Root == nullptr)
			_Root = new BTreeNode<_Ty>(prev, _Item);
		// root���� item�� ���� �� �������� Ž�� �� ����
		else if (_Root->data > _Item)
			_insert_node(_Root, _Root->left, _Item);
		// root���� item�� Ŭ �� ���������� Ž�� �� ����
		else if (_Root->data < _Item)
			_insert_node(_Root, _Root->right, _Item);
	}

	// BTreeNode ����
	template <typename _Ty>
	void BinaryTree<_Ty>::_remove_node(BTreeNode<_Ty>*& _Root, _Ty _Item)
	{
		// root���� ������ �������� Ž�� �� ����
		if (_Item < _Root->data)
			_remove_node(_Root->left, _Item);
		// root���� ũ�� ���������� Ž�� �� ����
		else if (_Item > _Root->data)
			_remove_node(_Root->right, _Item);
		// �����ϰ��� �ϴ� �������� ��
		else
		{
			BTreeNode<_Ty>* temp = _Root;

			// ����, ������ node�� ���� ��
			if (_Root->left == nullptr && _Root->right == nullptr)
			{
				// ���� �θ� ����� �����̶��
				if (_Root->up->data > _Item)
				{
					(_Root->up)->left = nullptr;
					delete _Root;
				}
				// ���� �θ� ����� �������̶��
				else if (_Root->up->data < _Item)
				{
					(_Root->up)->right = nullptr;
					delete _Root;
				}

			}
			// ���� node�� ���� ��
			else if (_Root->left == nullptr)
			{
				(_Root->right)->up = _Root->up;
				_Root = _Root->right;
				delete temp;
			}
			// ������ node�� ���� ��
			else if (_Root->right == nullptr)
			{
				(_Root->left)->up = _Root->up;
				_Root = _Root->left;
				delete temp;
			}
			// node�� �� �� ���� ��
			else
			{
				_get_predecessor(_Root->left, _Item);
				_Root->data = _Item;
				_remove_node(_Root->left, _Item);
			}
		}
	}

	// Tree���� BTreeNode �˻�
	template <typename _Ty>
	void BinaryTree<_Ty>::_retrieve_node(BTreeNode<_Ty>* _Root, _Ty& _Item)
	{
		if (_Root == nullptr)
			return;
		else if (_Item < _Root->data)
			_retrieve_node(_Root->left, _Item);
		else if (_Item < _Root->data)
			_retrieve_node(_Root->right, _Item);
		else
			_Item = _Root->data;
	}

	template<typename _Ty>
	BTreeNode<_Ty>* BinaryTree<_Ty>::_get_node(BTreeNode<_Ty>* _Root, _Ty& _Item)
	{
		// ã�� ���� �۴ٸ�
		if (_Root->data > _Item)
			return _get_node(_Root->left, _Item);
		// ã�� ���� ũ�ٸ�
		else if (_Root->data < _Item)
			return _get_node(_Root->right, _Item);
		// ã�� ���̶��
		else
			return _Root;
	}

	// ���� ū ���� ã�� �Լ�
	template <typename _Ty>
	void BinaryTree<_Ty>::_get_predecessor(BTreeNode<_Ty>* _Root, _Ty& _Item)
	{
		while (_Root->right != nullptr)
			_Root = _Root->right;
		_Item = _Root->data;
	}

	// in-order ���
	template <typename _Ty>
	void BinaryTree<_Ty>::_print_in_order(BTreeNode<_Ty>* _Root, std::ostream& _Out)
	{
		// root�� �����ϴ� ���
		if (_Root != nullptr)
		{
			_print_in_order(_Root->left, _Out);
			_Out << _Root->data;
			_print_in_order(_Root->right, _Out);
		}
		// root�� nulltpr�� ���
		else
			return;
	}

	// pre-order ���
	template <typename _Ty>
	void BinaryTree<_Ty>::_print_pre_order(BTreeNode<_Ty>* _Root, std::ostream& _Out)
	{
		// root�� �����ϴ� ���
		if (_Root != nullptr)
		{
			_Out << _Root->data;
			_print_in_order(_Root->left, _Out);
			_print_in_order(_Root->right, _Out);
		}
		// root�� nulltpr�� ���
		else
			return;
	}

	// post-order ���
	template <typename _Ty>
	void BinaryTree<_Ty>::_print_post_order(BTreeNode<_Ty>* _Root, std::ostream& _Out)
	{
		// root�� �����ϴ� ���
		if (_Root != nullptr)
		{
			_print_in_order(_Root->left, _Out);
			_print_in_order(_Root->right, _Out);
			_Out << _Root->data;
		}
		// root�� nulltpr�� ���
		else
			return;
	}

	template<typename _Ty>
	BTreeNode<_Ty>* BinaryTree<_Ty>::_get_next_node(BTreeNode<_Ty>* _Node)
	{
		return NULL;
	}
}

#endif _BINARY_TREE_H