#pragma once

#ifndef _LINKED_LIST_ITERATOR_H
#define _LINKED_LIST_ITERATOR_H

#include "LinkedList.h"

namespace kmh
{
	/**
	*	전방선언.
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
		*	기본 생성자.
		*/
		LinkedListIterator();

		/**
		*	생성자.
		*/
		LinkedListIterator(NodeType<_Ty>* _node) : val(_node) {}

		/**
		*	복사 생성자.
		*/
		LinkedListIterator(const LinkedListIterator<_Ty>& _Iter) : val(_Iter.val) {}

		/**
		*	소멸자.
		*/
		~LinkedListIterator() {}

		/**
		*	@brief	Iterator가 가지고 있는 노드가 nullptr인지 확인한다.
		*	@pre	노드를 가지고 있어야 한다.
		*	@return	nullptr이면 true.
		*/
		bool isNull();

		/**
		*	@brief	NodeType의 data를 참조한다.
		*	@pre	NodeType이 존재해야 한다.
		*	@return	NodeType->data의 포인터.
		*/
		_Ty& operator*();

		/**
		*	@brief	NodeType의 data를 참조한다.
		*	@pre	NodeType이 존재해야 한다.
		*	@return	NodeType->data의 주소.
		*/
		_Ty& operator->() const;

		/**
		*	@brief	현재 Iterator에서 다음 Iterator를 가져온다. (전위 연산)
		*	@pre	없음.
		*	@return	다음 NodeType.
		*/
		LinkedListIterator<_Ty> operator++();

		/**
		*	@brief	현재 Iterator에서 다음 Iterator를 가져온다. (후위 연산)
		*	@pre	없음.
		*	@return	다음 NodeType.
		*/
		LinkedListIterator<_Ty> operator++(int);

		/**
		*	@brief	현재 Iterator에서 이전 Iterator를 가져온다. (전위 연산)
		*	@pre	없음.
		*	@return	이전 NodeType.
		*/
		LinkedListIterator<_Ty> operator--();

		/**
		*	@brief	현재 Iterator에서 이전 Iterator를 가져온다. (후위 연산)
		*	@pre	없음.
		*	@return	이전 NodeType.
		*/
		LinkedListIterator<_Ty> operator--(int);

		/**
		*	@brief	Iterator가 서로 같은지 확인한다.
		*	@pre	없음.
		*	@param	rhs	확인할 대상.
		*	@return	같다면 true, 아니라면 false.
		*/
		bool operator==(const LinkedListIterator<_Ty>& rhs);

		/**
		*	@brief	Iterator가 서로 같은지 확인한다.
		*	@pre	없음.
		*	@param	rhs	확인할 대상.
		*	@return	같다면 true, 아니라면 false.
		*/
		bool operator!=(const LinkedListIterator<_Ty>& rhs);

	private:
		NodeType<_Ty>* val;

	};

	// 기본 생성자.
	template <typename _Ty>
	LinkedListIterator<_Ty>::LinkedListIterator()
	{
		val = nullptr;
	}

	// nullptr인지 확인.
	template <typename _Ty>
	bool LinkedListIterator<_Ty>::isNull()
	{
		return (val == nullptr);
	}

	// * 연산.
	template <typename _Ty>
	_Ty& LinkedListIterator<_Ty>::operator*()
	{
		return val->data;
	}

	// -> 연산.
	template <typename _Ty>
	_Ty& LinkedListIterator<_Ty>::operator->() const
	{
		return &(val->data);
	}

	// ++ 전위 연산.
	template <typename _Ty>
	LinkedListIterator<_Ty> LinkedListIterator<_Ty>::operator++()
	{
		val = val->next;
		return *this;
	}

	// ++ 후위 연산.
	template <typename _Ty>
	LinkedListIterator<_Ty> LinkedListIterator<_Ty>::operator++(int)
	{
		LinkedListIterator<_Ty> temp(val->next);
		return temp;
	}

	// -- 전위 연산.
	template <typename _Ty>
	LinkedListIterator<_Ty> LinkedListIterator<_Ty>::operator--()
	{
		val = val->prev;
		return *this;
	}

	// -- 후위 연산.
	template <typename _Ty>
	LinkedListIterator<_Ty> LinkedListIterator<_Ty>::operator--(int)
	{
		LinkedListIterator<_Ty> temp(val.prev);
		return temp;
	}

	// == 연산.
	template<typename _Ty>
	bool LinkedListIterator<_Ty>::operator==(const LinkedListIterator<_Ty>& rhs)
	{
		return (this->val == rhs.val);
	}

	// != 연산.
	template<typename _Ty>
	bool LinkedListIterator<_Ty>::operator!=(const LinkedListIterator<_Ty>& rhs)
	{
		return (this->val != rhs.val);
	}

} // namespace kmh end.

#endif _LINKED_LIST_ITERATOR_H