#pragma once

#ifndef _LINKED_LIST_ITERATOR_H
#define _LINKED_LIST_ITERATOR_H

#include "LinkedList.h"

namespace kmh
{
	/**
	*	���漱��.
	*/
	template <typename _Ty>
	class LinkedListIterator;

	template <typename _Ty>
	class LinkedList;

	template <typename _Ty>
	struct NodeType;


	/**
	*	using.
	*/
	template <typename _Ty>
	using List = LinkedList<_Ty>;
	template <typename _Ty>
	using LIterator = LinkedListIterator<_Ty>;


	/**
	*	Iterator for Sorted Doubly-Linked-List.
	*/
	template <typename _Ty>
	class LinkedListIterator
	{
		friend LinkedList<_Ty>;

	public:

		/**
		*	�⺻ ������.
		*/
		LinkedListIterator();

		/**
		*	������.
		*/
		LinkedListIterator(NodeType<_Ty>* _node) : val(_node) {}

		/**
		*	���� ������.
		*/
		LinkedListIterator(const LinkedListIterator<_Ty>& _Iter) : val(_Iter.val) {}

		/**
		*	�Ҹ���.
		*/
		~LinkedListIterator() {}

		/**
		*	@brief	Iterator�� ������ �ִ� ��尡 nullptr���� Ȯ���Ѵ�.
		*	@pre	��带 ������ �־�� �Ѵ�.
		*	@return	nullptr�̸� true.
		*/
		bool isNull();

		/**
		*	@brief	NodeType�� data�� �����Ѵ�.
		*	@pre	NodeType�� �����ؾ� �Ѵ�.
		*	@return	NodeType->data�� ������.
		*/
		_Ty& operator*();

		/**
		*	@brief	NodeType�� data�� �����Ѵ�.
		*	@pre	NodeType�� �����ؾ� �Ѵ�.
		*	@return	NodeType->data�� �ּ�.
		*/
		_Ty& operator->() const;

		/**
		*	@brief	���� Iterator���� ���� Iterator�� �����´�. (���� ����)
		*	@pre	����.
		*	@return	���� NodeType.
		*/
		LinkedListIterator<_Ty> operator++();

		/**
		*	@brief	���� Iterator���� ���� Iterator�� �����´�. (���� ����)
		*	@pre	����.
		*	@return	���� NodeType.
		*/
		LinkedListIterator<_Ty> operator++(int);

		/**
		*	@brief	���� Iterator���� ���� Iterator�� �����´�. (���� ����)
		*	@pre	����.
		*	@return	���� NodeType.
		*/
		LinkedListIterator<_Ty> operator--();

		/**
		*	@brief	���� Iterator���� ���� Iterator�� �����´�. (���� ����)
		*	@pre	����.
		*	@return	���� NodeType.
		*/
		LinkedListIterator<_Ty> operator--(int);

		/**
		*	@brief	Iterator�� ���� ������ Ȯ���Ѵ�.
		*	@pre	����.
		*	@param	rhs	Ȯ���� ���.
		*	@return	���ٸ� true, �ƴ϶�� false.
		*/
		bool operator==(const LinkedListIterator<_Ty>& rhs);

		/**
		*	@brief	Iterator�� ���� ������ Ȯ���Ѵ�.
		*	@pre	����.
		*	@param	rhs	Ȯ���� ���.
		*	@return	���ٸ� true, �ƴ϶�� false.
		*/
		bool operator!=(const LinkedListIterator<_Ty>& rhs);

	private:
		NodeType<_Ty>* val;

	};

	// �⺻ ������.
	template <typename _Ty>
	LinkedListIterator<_Ty>::LinkedListIterator()
	{
		val = nullptr;
	}

	// nullptr���� Ȯ��.
	template <typename _Ty>
	bool LinkedListIterator<_Ty>::isNull()
	{
		return (val == nullptr);
	}

	// * ����.
	template <typename _Ty>
	_Ty& LinkedListIterator<_Ty>::operator*()
	{
		return val->data;
	}

	// -> ����.
	template <typename _Ty>
	_Ty& LinkedListIterator<_Ty>::operator->() const
	{
		return &(val->data);
	}

	// ++ ���� ����.
	template <typename _Ty>
	LinkedListIterator<_Ty> LinkedListIterator<_Ty>::operator++()
	{
		val = val->next;
		return *this;
	}

	// ++ ���� ����.
	template <typename _Ty>
	LinkedListIterator<_Ty> LinkedListIterator<_Ty>::operator++(int)
	{
		LinkedListIterator<_Ty> temp(val->next);
		return temp;
	}

	// -- ���� ����.
	template <typename _Ty>
	LinkedListIterator<_Ty> LinkedListIterator<_Ty>::operator--()
	{
		val = val->prev;
		return *this;
	}

	// -- ���� ����.
	template <typename _Ty>
	LinkedListIterator<_Ty> LinkedListIterator<_Ty>::operator--(int)
	{
		LinkedListIterator<_Ty> temp(val.prev);
		return temp;
	}

	// == ����.
	template<typename _Ty>
	bool LinkedListIterator<_Ty>::operator==(const LinkedListIterator<_Ty>& rhs)
	{
		return (this->val == rhs.val);
	}

	// != ����.
	template<typename _Ty>
	bool LinkedListIterator<_Ty>::operator!=(const LinkedListIterator<_Ty>& rhs)
	{
		return (this->val != rhs.val);
	}

} // namespace kmh end.

#endif _LINKED_LIST_ITERATOR_H