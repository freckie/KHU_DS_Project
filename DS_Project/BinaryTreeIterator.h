#pragma once

#ifndef _BINARY_TREE_ITERATOR_H
#define _BINARY_TREE_ITERATOR_H

#include"BinaryTree.h"

namespace kmh
{
	/**
	*	���� ����.
	*/
	template <typename _Ty>
	struct BTreeNode;

	template <typename _Ty>
	class BinaryTreeIterator;

	template <typename _Ty>
	class BinaryTree;


	/**
	*	Iterator for Binary Search Tree (�ܹ���)
	*/
	template <typename _Ty>
	class BinaryTreeIterator
	{
		//friend class BinaryTree<_Ty>;

	public:

		/**
		*	�⺻ ������.
		*/
		BinaryTreeIterator();

		/**
		*	������.
		*/
		BinaryTreeIterator(BTreeNode<_Ty>* _node) : _Val(_node) {}

		/**
		*	�Ҹ���.
		*/
		~BinaryTreeIterator() = default;

		/**
		*	@brief	iterator�� ���� ������ �ִ��� Ȯ��.
		*	@pre	����.
		*	@post	����.
		*	@return	nullptr�̶�� true, �ƴ϶�� false.
		*/
		bool is_null() const;

		_Ty& operator*();
		_Ty& operator->() const;
		BinaryTreeIterator<_Ty> operator++();
		BinaryTreeIterator<_Ty> operator++(int);
		bool operator==(const BinaryTreeIterator<_Ty>& _Rhs);
		bool operator!=(const BinaryTreeIterator<_Ty>& _Rhs);

	private:
		BTreeNode<_Ty>* _Val;	///< ���� ��.

	};

	// �⺻ ������.
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

	// * ����.
	template <typename _Ty>
	_Ty& BinaryTreeIterator<_Ty>::operator*()
	{
		return _Val->data;
	}

	// -> ����.
	template <typename _Ty>
	_Ty& BinaryTreeIterator<_Ty>::operator->() const
	{
		return &(_Val->data);
	}

	template<typename _Ty>
	BinaryTreeIterator<_Ty> BinaryTreeIterator<_Ty>::operator++()
	{
		BTreeNode<_Ty>* temp = _get_next_node(this->_Val);
		_Val = temp;
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
