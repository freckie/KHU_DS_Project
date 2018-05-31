#pragma once

#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include <iostream>

#include"BinaryTreeIterator.h"

namespace kmh
{
	/**
	*	전방선언.
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

	// Tree 구성하는 BTreeNode
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
		BTreeNode<_Ty>* _get_min_node(BTreeNode<_Ty>* _Node);
		BTreeNode<_Ty>* _get_max_node(BTreeNode<_Ty>* _Node);
	};

	template <typename _Ty>
	BTreeNode<_Ty>* _get_next_node(BTreeNode<_Ty>* _Node);

	// 생성자
	template <typename _Ty>
	BinaryTree<_Ty>::BinaryTree()
	{
		_Root = nullptr;
	}

	// 소멸자
	template <typename _Ty>
	BinaryTree<_Ty>::~BinaryTree()
	{
		make_empty();
	}

	// Tree가 비었는지 확인
	template <typename _Ty>
	bool BinaryTree<_Ty>::is_empty() const
	{
		return (_Root == nullptr);
	}

	// Tree가 Full인지 확인
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

	// Tree를 비움
	template <typename _Ty>
	void BinaryTree<_Ty>::make_empty()
	{
		/*
		* 모두 삭제 코드 추가하기
		*/
		_Root = nullptr;
	}

	// Tree가 비었는지 확인
	template <typename _Ty>
	int BinaryTree<_Ty>::length() const
	{
		return _count_nodes(_Root);
	}

	// Tree에 BTreeNode 추가
	template <typename _Ty>
	bool BinaryTree<_Ty>::add(_Ty _Item)
	{
		_insert_node(_Root, _Root, _Item);
		return true;
	}

	// Tree에서 BTreeNode 삭제
	template <typename _Ty>
	bool BinaryTree<_Ty>::remove(_Ty _Item)
	{
		_remove_node(_Root, _Item);
		return true;
	}

	// Tree에서 BTreeNode 검색
	template <typename _Ty>
	bool BinaryTree<_Ty>::retrieve(_Ty& _Item)
	{
		_retrieve_node(_Root, _Item);
		return true;
	}

	// Tree 출력
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
		// 맨 왼쪽 노드 반환
		BTreeNode<_Ty>* temp = _Root;
		while (temp->left != nullptr)
			temp = temp->left;

		return BinaryTreeIterator<_Ty>(temp);
	}

	template<typename _Ty>
	BinaryTreeIterator<_Ty> BinaryTree<_Ty>::end()
	{
		// 맨 오른쪽 노드 반환
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

	// node 개수 count 함수
	template <typename _Ty>
	int BinaryTree<_Ty>::_count_nodes(BTreeNode<_Ty>* _Root)
	{
		if (_Root == nullptr)
			return 0;
		else
			return _count_nodes(_Root->left) + _count_nodes(_Root->right) + 1;
	}

	// node 추가
	template <typename _Ty>
	void BinaryTree<_Ty>::_insert_node(BTreeNode<_Ty>*& prev, BTreeNode<_Ty>*& _Root, _Ty _Item)
	{
		// nullptr일 경우
		if (_Root == nullptr)
			_Root = new BTreeNode<_Ty>(prev, _Item);
		// root보다 item이 작을 때 왼쪽으로 탐색 후 삽입
		else if (_Root->data > _Item)
			_insert_node(_Root, _Root->left, _Item);
		// root보다 item이 클 때 오른쪽으로 탐색 후 삽입
		else if (_Root->data < _Item)
			_insert_node(_Root, _Root->right, _Item);
	}

	// BTreeNode 삭제
	template <typename _Ty>
	void BinaryTree<_Ty>::_remove_node(BTreeNode<_Ty>*& _Root, _Ty _Item)
	{
		// root보다 작으면 왼쪽으로 탐색 후 삭제
		if (_Item < _Root->data)
			_remove_node(_Root->left, _Item);
		// root보다 크면 오른쪽으로 탐색 후 삭제
		else if (_Item > _Root->data)
			_remove_node(_Root->right, _Item);
		// 삭제하고자 하는 아이템일 때
		else
		{
			BTreeNode<_Ty>* temp = _Root;

			// 왼쪽, 오른쪽 node가 없을 때
			if (_Root->left == nullptr && _Root->right == nullptr)
			{
				// 만약 부모 노드의 왼쪽이라면
				if (_Root->up->data > _Item)
				{
					(_Root->up)->left = nullptr;
					delete _Root;
				}
				// 만약 부모 노드의 오른쪽이라면
				else if (_Root->up->data < _Item)
				{
					(_Root->up)->right = nullptr;
					delete _Root;
				}

			}
			// 왼쪽 node만 없을 떄
			else if (_Root->left == nullptr)
			{
				(_Root->right)->up = _Root->up;
				_Root = _Root->right;
				delete temp;
			}
			// 오른쪽 node만 없을 때
			else if (_Root->right == nullptr)
			{
				(_Root->left)->up = _Root->up;
				_Root = _Root->left;
				delete temp;
			}
			// node가 둘 다 있을 때
			else
			{
				_get_predecessor(_Root->left, _Item);
				_Root->data = _Item;
				_remove_node(_Root->left, _Item);
			}
		}
	}

	// Tree에서 BTreeNode 검색
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
		// 찾는 값이 작다면
		if (_Root->data > _Item)
			return _get_node(_Root->left, _Item);
		// 찾는 값이 크다면
		else if (_Root->data < _Item)
			return _get_node(_Root->right, _Item);
		// 찾는 값이라면
		else
			return _Root;
	}

	// 가장 큰 값을 찾는 함수
	template <typename _Ty>
	void BinaryTree<_Ty>::_get_predecessor(BTreeNode<_Ty>* _Root, _Ty& _Item)
	{
		while (_Root->right != nullptr)
			_Root = _Root->right;
		_Item = _Root->data;
	}

	// in-order 출력
	template <typename _Ty>
	void BinaryTree<_Ty>::_print_in_order(BTreeNode<_Ty>* _Root, std::ostream& _Out)
	{
		// root가 존재하는 경우
		if (_Root != nullptr)
		{
			_print_in_order(_Root->left, _Out);
			_Out << _Root->data;
			_print_in_order(_Root->right, _Out);
		}
		// root가 nulltpr인 경우
		else
			return;
	}

	// pre-order 출력
	template <typename _Ty>
	void BinaryTree<_Ty>::_print_pre_order(BTreeNode<_Ty>* _Root, std::ostream& _Out)
	{
		// root가 존재하는 경우
		if (_Root != nullptr)
		{
			_Out << _Root->data;
			_print_in_order(_Root->left, _Out);
			_print_in_order(_Root->right, _Out);
		}
		// root가 nulltpr인 경우
		else
			return;
	}

	// post-order 출력
	template <typename _Ty>
	void BinaryTree<_Ty>::_print_post_order(BTreeNode<_Ty>* _Root, std::ostream& _Out)
	{
		// root가 존재하는 경우
		if (_Root != nullptr)
		{
			_print_in_order(_Root->left, _Out);
			_print_in_order(_Root->right, _Out);
			_Out << _Root->data;
		}
		// root가 nulltpr인 경우
		else
			return;
	}

	template<typename _Ty>
	BTreeNode<_Ty>* BinaryTree<_Ty>::_get_min_node(BTreeNode<_Ty>* _Node)
	{
		BTreeNode<_Ty>* cur = _Node;

		// 제일 왼쪽.
		while (cur->left != nullptr)
			cur = cur->left;

		return cur;
	}

	template<typename _Ty>
	BTreeNode<_Ty>* BinaryTree<_Ty>::_get_max_node(BTreeNode<_Ty>* _Node)
	{
		BTreeNode<_Ty>* cur = _Node;

		// 제일 오른쪽.
		while (cur->right != nullptr)
			cur = cur->right;

		return cur;
	}

	// 외부 함수.
	template<typename _Ty>
	BTreeNode<_Ty>* _get_next_node(BTreeNode<_Ty>* _Node)
	{
		if (_Node->right != nullptr)
		{
			BTreeNode<_Ty>* cur = _Node->right;
			while (cur->left != nullptr)
				cur = cur->left;

			return cur;
		}

		BTreeNode<_Ty>* ptr = _Node->up;
		while (ptr != nullptr && _Node == ptr->right)
		{
			_Node = ptr;
			ptr = ptr->up;
		}

		return ptr;
	}

}

#endif _BINARY_TREE_H