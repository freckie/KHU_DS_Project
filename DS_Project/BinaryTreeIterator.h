#pragma once

#ifndef _BINARY_TREE_ITERATOR_H
#define _BINARY_TREE_ITERATOR_H

#include"BinaryTree.h"

namespace kmh
{
	/**
	*	전방 선언.
	*/
	template <typename _Ty>
	struct BTreeNode;

	template <typename _Ty>
	class BinaryTreeIterator;

	template <typename _Ty>
	class BinaryTree;


	/**
	*	Iterator for Binary Search Tree
	*/
	template <typename _Ty>
	class BinaryTreeIterator
	{
		//friend class BinaryTree<_Ty>;

	public:

		/**
		*	기본 생성자.
		*/
		BinaryTreeIterator();

		/**
		*	생성자.
		*/
		BinaryTreeIterator(BTreeNode<_Ty>* _node) : _Val(_node) {}

		/**
		*	소멸자.
		*/
		~BinaryTreeIterator() = default;

		bool is_null() const;

		_Ty& operator*();
		_Ty& operator->() const;
		BinaryTreeIterator<_Ty> operator++();
		BinaryTreeIterator<_Ty> operator++(int);
		BinaryTreeIterator<_Ty> operator--();
		BinaryTreeIterator<_Ty> operator--(int);
		bool operator==(const BinaryTreeIterator<_Ty>& _Rhs);
		bool operator!=(const BinaryTreeIterator<_Ty>& _Rhs);

	private:
		BTreeNode<_Ty>* _Val;

	};

	// 기본 생성자.
	template <typename _Ty>
	BinaryTreeIterator<_Ty>::BinaryTreeIterator()
	{
		_Val = nullptr;
	}

	template <typename _Ty>
	bool BinaryTreeIterator<_Ty>::is_null() const
	{
		return (_Val == nullptr);
	}

	// * 연산.
	template <typename _Ty>
	_Ty& BinaryTreeIterator<_Ty>::operator*()
	{
		return _Val->data;
	}

	// -> 연산.
	template <typename _Ty>
	_Ty& BinaryTreeIterator<_Ty>::operator->() const
	{
		return &(_Val->data);
	}

	template<typename _Ty>
	BinaryTreeIterator<_Ty> BinaryTreeIterator<_Ty>::operator++()
	{
		// 오른쪽 노드가 존재할 때, 오른쪽에서 가장 작은 노드
		if (_Val->right != nullptr)
		{
			_Val = _Val->right;
			while (_Val->left != nullptr)
				_Val = _Val->left;
		}
		// 자식 노드가 없을 때
		else if ((_Val->left == nullptr) && (_Val->right == nullptr))
		{
			// 부모의 왼쪽이었다면
			if (_Val == (_Val->up)->left)
				_Val = _Val->up;
			// 부모의 오른쪽이었다면, 계속 올라감
			else if (_Val == (_Val->up)->right)
			{
				while (true)
				{
					// 부모가 없다면 루프 끝
					if (_Val->up == nullptr)
						break;
					// 부모의 왼쪽이었다면 루프 끝
					else if (_Val == (_Val->up)->left)
						break;
					// 부모의 오른쪽이었다면 루프 계속 진행
					else
						_Val = _Val->up;
				}
				_Val = _Val->up;
			}
		}
		return *this;
	}

	template<typename _Ty>
	BinaryTreeIterator<_Ty> BinaryTreeIterator<_Ty>::operator++(int)
	{
		BinaryTreeIterator<_Ty> temp = *this;
		++(*this);
		return temp;
	}

	template<typename _Ty>
	BinaryTreeIterator<_Ty> BinaryTreeIterator<_Ty>::operator--()
	{
		// 왼쪽 노드가 존재할 때, 왼쪽에서 가장 큰 노드
		if (_Val->left != nullptr)
		{
			_Val = _Val->left;
			while (_Val->right != nullptr)
				_Val = _Val->right;
		}
		// 자식 노드가 없을 때
		else if ((_Val->left == nullptr) && (_Val->right == nullptr))
		{
			// 부모의 오른쪽이었다면
			if (_Val == (_Val->up)->right)
				_Val = _Val->up;
			// 부모의 왼쪽이었다면, 계속 올라감
			else if (_Val == (_Val->up)->left)
			{
				while (true)
				{
					// 부모가 없다면 루프 끝
					if (_Val->up == nullptr)
						break;
					// 부모의 오른쪽이었다면 루프 끝
					else if (_Val == (_Val->up)->right)
						break;
					// 부모의 오른쪽이었다면 루프 계속 진행
					else
						_Val = _Val->up;
				}
				_Val = _Val->up;
			}
		}
		return *this;
	}

	template<typename _Ty>
	BinaryTreeIterator<_Ty> BinaryTreeIterator<_Ty>::operator--(int)
	{
		BinaryTreeIterator<_Ty> temp = *this;
		--(*this);
		return temp;
	}

	template<typename _Ty>
	bool BinaryTreeIterator<_Ty>::operator==(const BinaryTreeIterator<_Ty>& _Rhs)
	{
		return (this->_Val == _Rhs._Val);
	}

	template<typename _Ty>
	bool BinaryTreeIterator<_Ty>::operator!=(const BinaryTreeIterator<_Ty>& _Rhs)
	{
		return (this->_Val != _Rhs._Val);
	}
}

#endif _BINARY_TREE_ITERATOR_H
