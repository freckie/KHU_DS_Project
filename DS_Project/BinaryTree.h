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

	/**
	*	Binary Search Tree 구성하는 Node.
	*/
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

	/**
	*	Binary Search Tree
	*/
	template <typename _Ty>
	class BinaryTree
	{

	public:
		/**
		*	기본 생성자.
		*/
		BinaryTree();

		/**
		*	소멸자.
		*/
		~BinaryTree();

		/**
		*	@brief	Tree가 비었는지 확인한다.
		*	@pre	없음.
		*	@post	없음.
		*	@return	비었으면 true, 아니라면 false.
		*/
		bool is_empty() const;

		/**
		*	@brief	Tree에 추가할 수 있는지 확인한다.
		*	@pre	없음.
		*	@post	없음.
		*	@return	추가할 수 없다면 true, 아니라면 false.
		*/
		bool is_full() const;

		/**
		*	@brief	Tree를 모두 비운다.
		*	@pre	없음.
		*	@post	Tree가 비워진다.
		*/
		void make_empty();

		/**
		*	@brief	Tree에 데이터 수를 센다.
		*	@pre	없음.
		*	@post	없음.
		*	@return	Tree의 사이즈.
		*/
		int length() const;

		/**
		*	@brief	Tree에 데이터를 추가한다.
		*	@pre	없음.
		*	@post	없음.
		*	@param	_Item	추가할 데이터.
		*	@return	성공 여부.
		*/
		bool add(_Ty& _Item);

		/**
		*	@brief	Tree에 데이터를 추가하고, 데이터의 포인터를 반환한다.
		*	@pre	없음.
		*	@post	없음.
		*	@param	_Item	추가할 데이터.
		*	@return	추가한 데이터의 노드 포인터. 추가 실패라면 nullptr.
		*/
		BTreeNode<_Ty>* add_and_get(_Ty& _Item);

		/**
		*	@brief	Tree에서 데이터를 삭제한다.
		*	@pre	없음.
		*	@post	없음.
		*	@param	_Item	삭제할 데이터.
		*	@return	성공 여부.
		*/
		bool remove(_Ty& _Item);

		/**
		*	@brief	Tree에 데이터를 변경한다.
		*	@pre	없음.
		*	@post	없음.
		*	@param	_Item	변경할 데이터.
		*	@return	성공 여부.
		*/
		bool retrieve(_Ty& _Item);

		/**
		*	@brief	Tree에 데이터를 모두 출력한다.
		*	@pre	없음.
		*	@post	없음.
		*	@param	_Out ostream
		*/
		void print(std::ostream& _Out);

		/**
		*	@brief	Tree의 제일 작은 값의 iterator를 반환한다.
		*	@pre	없음.
		*	@post	없음.
		*	@return	제일 작은 값의 iterator.
		*/
		BinaryTreeIterator<_Ty> begin();

		/**
		*	@brief	Tree의 제일 큰 값 다음의 iterator를 반환한다.
		*	@pre	없음.
		*	@post	없음.
		*	@return	nullptr 담긴 iterator.
		*/
		BinaryTreeIterator<_Ty> end();

		/**
		*	@brief	Tree에서 item검색하여 iterator로 반환.
		*	@pre	없음.
		*	@post	없음.
		*	@param	_Item	iterator 얻고 싶은 값
		*	@return	일치하는 값을 가진 iterator.
		*/
		BinaryTreeIterator<_Ty> find(_Ty _Item);

		/**
		*	@brief	Tree서 일치하는 아이템을 담고 있는 노드 포인터 반환.
		*	@pre	없음.
		*	@post	없음.
		*	@param	_Item	반환할 데이터.
		*	@return	일치하는 아이템을 담고있는 노드 포인터 반환.
		*/
		BTreeNode<_Ty>* get_node(_Ty& _Item);

		/**
		*	@brief	Tree의 _Root를 반환한다.
		*	@pre	없음.
		*	@post	없음.
		*	@return	_Root.
		*/
		BTreeNode<_Ty>* get_root();

	private:
		BTreeNode<_Ty>* _Root;	///< Root Node

		int _count_nodes(BTreeNode<_Ty>* _Root);
		BTreeNode<_Ty>* _insert_node(BTreeNode<_Ty>*& _Prev, BTreeNode<_Ty>*& _Root, _Ty _Item);
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

	/***************/
	/* 비 멤버 함수 */
	/***************/
	template <typename _Ty>
	BTreeNode<_Ty>* _get_next_node(BTreeNode<_Ty>* _Node);

	template <typename _Ty, class Func>
	void in_order(BinaryTree<_Ty>& _Tree, Func _Func);

	template <typename _Ty, class Func>
	void _in_order(BTreeNode<_Ty>* _Node, Func _Func);

	template <typename _Ty, class Func>
	void pre_order(BinaryTree<_Ty>& _Tree, Func _Func);

	template <typename _Ty, class Func>
	void _pre_order(BTreeNode<_Ty>* _Node, Func _Func);

	template <typename _Ty, class Func>
	void post_order(BinaryTree<_Ty>& _Tree, Func _Func);

	template <typename _Ty, class Func>
	void _post_order(BTreeNode<_Ty>* _Node, Func _Func);

	/************/
	/* 멤버 함수 */
	/************/

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
		_post_order(_Root, [](BTreeNode<_Ty>* node) {delete node; });
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
	bool BinaryTree<_Ty>::add(_Ty& _Item)
	{
		_insert_node(_Root, _Root, _Item);
		return true;
	}

	template<typename _Ty>
	BTreeNode<_Ty>* BinaryTree<_Ty>::add_and_get(_Ty & _Item)
	{
		return _insert_node(_Root, _Root, _Item);
	}

	// Tree에서 BTreeNode 삭제
	template <typename _Ty>
	bool BinaryTree<_Ty>::remove(_Ty& _Item)
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

	template<typename _Ty>
	BTreeNode<_Ty>* BinaryTree<_Ty>::get_node(_Ty & _Item)
	{
		return _get_node(_Root, _Item);
	}

	template<typename _Ty>
	BTreeNode<_Ty>* BinaryTree<_Ty>::get_root()
	{
		return _Root;
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
	BTreeNode<_Ty>* BinaryTree<_Ty>::_insert_node(BTreeNode<_Ty>*& prev, BTreeNode<_Ty>*& _Root, _Ty _Item)
	{
		// nullptr일 경우
		if (_Root == nullptr)
		{
			_Root = new BTreeNode<_Ty>(prev, _Item);
			return _Root;
		}
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

	template<typename _Ty, class Func>
	void in_order(BinaryTree<_Ty>& _Tree, Func _Func)
	{
		BTreeNode<_Ty>* root = _Tree.get_root();

		// root가 존재하는 경우
		if (root != nullptr)
		{
			_in_order<_Ty, Func>(root->left, _Func);
			_Func(root);
			_in_order<_Ty, Func>(root->right, _Func);
		}
		// root가 nullptr인 경우
		else
			return;
	}

	template<typename _Ty, class Func>
	void _in_order(BTreeNode<_Ty>* _Node, Func _Func)
	{
		// root가 존재하는 경우
		if (_Node != nullptr)
		{
			_in_order<_Ty, Func>(_Node->left, _Func);
			_Func(_Node);
			_in_order<_Ty, Func>(_Node->right, _Func);
		}
		// root가 nullptr인 경우
		else
			return;
	}

	template<typename _Ty, class Func>
	void pre_order(BinaryTree<_Ty>& _Tree, Func _Func)
	{
		BTreeNode<_Ty>* root = _Tree.get_root();

		// root가 존재하는 경우
		if (root != nullptr)
		{
			_Func(root);
			_pre_order<_Ty, Func>(root->left, _Func);
			_pre_order<_Ty, Func>(root->right, _Func);
		}
		// root가 nullptr인 경우
		else
			return;
	}

	template<typename _Ty, class Func>
	void _pre_order(BTreeNode<_Ty>* _Node, Func _Func)
	{
		// root가 존재하는 경우
		if (_Node != nullptr)
		{
			_Func(_Node);
			_pre_order<_Ty, Func>(_Node->left, _Func);
			_pre_order<_Ty, Func>(_Node->right, _Func);
		}
		// root가 nullptr인 경우
		else
			return;
	}

	template<typename _Ty, class Func>
	void post_order(BinaryTree<_Ty>& _Tree, Func _Func)
	{
		BTreeNode<_Ty>* root = _Tree.get_root();

		// root가 존재하는 경우
		if (root != nullptr)
		{
			_post_order<_Ty, Func>(root->left, _Func);
			_post_order<_Ty, Func>(root->right, _Func);
			_Func(root);
		}
		// root가 nullptr인 경우
		else
			return;
	}

	template<typename _Ty, class Func>
	void _post_order(BTreeNode<_Ty>* _Node, Func _Func)
	{
		// root가 존재하는 경우
		if (_Node != nullptr)
		{
			_post_order<_Ty, Func>(_Node->left, _Func);
			_post_order<_Ty, Func>(_Node->right, _Func);
			_Func(_Node);
		}
		// root가 nullptr인 경우
		else
			return;
	}
}

#endif _BINARY_TREE_H