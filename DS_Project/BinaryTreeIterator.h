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
	*	Iterator for Binary Search Tree
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
		// ������ ��尡 ������ ��, �����ʿ��� ���� ���� ���
		if (_Val->right != nullptr)
		{
			_Val = _Val->right;
			while (_Val->left != nullptr)
				_Val = _Val->left;
		}
		// �ڽ� ��尡 ���� ��
		else if ((_Val->left == nullptr) && (_Val->right == nullptr))
		{
			// �θ��� �����̾��ٸ�
			if (_Val == (_Val->up)->left)
				_Val = _Val->up;
			// �θ��� �������̾��ٸ�, ��� �ö�
			else if (_Val == (_Val->up)->right)
			{
				while (true)
				{
					// �θ� ���ٸ� ���� ��
					if (_Val->up == nullptr)
						break;
					// �θ��� �����̾��ٸ� ���� ��
					else if (_Val == (_Val->up)->left)
						break;
					// �θ��� �������̾��ٸ� ���� ��� ����
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
		// ���� ��尡 ������ ��, ���ʿ��� ���� ū ���
		if (_Val->left != nullptr)
		{
			_Val = _Val->left;
			while (_Val->right != nullptr)
				_Val = _Val->right;
		}
		// �ڽ� ��尡 ���� ��
		else if ((_Val->left == nullptr) && (_Val->right == nullptr))
		{
			// �θ��� �������̾��ٸ�
			if (_Val == (_Val->up)->right)
				_Val = _Val->up;
			// �θ��� �����̾��ٸ�, ��� �ö�
			else if (_Val == (_Val->up)->left)
			{
				while (true)
				{
					// �θ� ���ٸ� ���� ��
					if (_Val->up == nullptr)
						break;
					// �θ��� �������̾��ٸ� ���� ��
					else if (_Val == (_Val->up)->right)
						break;
					// �θ��� �������̾��ٸ� ���� ��� ����
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
