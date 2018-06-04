#pragma once

#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include<iostream>

#include "LinkedListIterator.h"

namespace kmh
{
	/**
	*	전방선언.
	*/
	template <typename _Ty>
	class LinkedListIterator;

	template <typename _Ty>
	class LinkedList;


	/**
	*	using.
	*/
	template <typename _Ty>
	using List = LinkedList<_Ty>;
	template <typename _Ty>
	using LIterator = LinkedListIterator<_Ty>;


	/**
	*	List에 사용되는 NodeType 구조체
	*/
	template <typename _Ty>
	struct NodeType
	{
		_Ty data;	///< 노드의 데이터
		NodeType* prev;	///< 이전 노드 가리킨다.
		NodeType* next;	///< 다음 노드 가리킨다.

		NodeType(_Ty data) : data(data), prev(nullptr), next(nullptr) {}
	};


	/**
	*	Sorted Doubly-Linked-List
	*/
	template <typename _Ty>
	class LinkedList
	{

		friend class LinkedListIterator<_Ty>;

	public:
		/**
		*	기본 생성자.
		*/
		LinkedList();

		/**
		*	소멸자.
		*/
		~LinkedList();

		/**
		*	@brief	현재 리스트가 비었는지 확인.
		*	@pre	m_nLength가 값을 가져야 한다.
		*	@post	없음.
		*	@return	리스트가 비어있으면 true, 아니라면 false.
		*/
		bool is_empty();

		/**
		*	@brief	리스트를 비운다.
		*	@pre	없음.
		*	@post	모든 데이터를 지운다.
		*/
		void make_empty();

		/**
		*	@brief	리스트의 길이를 반환한다.
		*	@pre	없음.
		*	@post	없음.
		*	@return	m_Length 리스트의 길이 반환.
		*/
		size_t length() const;

		/**
		*	@brief	새로운 데이터를 리스트에 추가한다.
		*	@pre	없음.
		*	@post	새로운 데이터를 리스트에 추가한다.
		*	@param	item	새로운 데이터.
		*	@return 잘 작동했다면 1, 아니라면 0.
		*/
		bool add(_Ty& item);

		/**
		*	@brief	새로운 데이터를 리스트에 추가한다.
		*	@pre	없음.
		*	@post	새로운 데이터를 리스트에 추가한다.
		*	@param	item	새로운 데이터.
		*	@return 잘 작동했다면 1, 아니라면 0.
		*/
		bool add(_Ty&& item);

		/**
		*	@brief	새로운 데이터를 리스트에 추가한다.
		*	@pre	없음.
		*	@post	새로운 데이터를 리스트에 추가한다.
		*	@param	item	새로운 데이터.
		*	@return 잘 작동했다면 1, 아니라면 0.
		*/
		NodeType<_Ty>* add_and_get(_Ty& item);

		/**
		*	@brief	데이터를 찾아 리스트에서 삭제한다.
		*	@pre	없음.
		*	@post	데이터를 리스트에서 삭제한다.
		*	@param	item	삭제할 데이터.
		*	@return 잘 작동했다면 1, 아니라면 0.
		*/
		bool remove(_Ty& item);

		/**
		*	@brief	입력받은 아이템으로 정보를 바꾼다.
		*	@pre	없음.
		*	@post	새로운 데이터로 교체한다.
		*	@param	item	새로 교체할 데이터.
		*	@return 잘 작동했다면 1, 아니라면 0.
		*/
		bool replace(_Ty& item);

		/**
		*	@brief	리스트에 아이템을 가져온다.
		*	@pre	없음.
		*	@post	검색된 데이터를 아이템에 넣는다.
		*	@param	item	가져올 데이터.
		*	@return 잘 작동했다면 1, 아니라면 0.
		*/
		bool get(_Ty& item);

		/**
		*	@brief	리스트의 아이템을 검색하여 Iterator로 가져온다.
		*	@pre	없음.
		*	@post	리스트의 아이템을 검색하여 Iterator로 가져온다.
		*	@return 검색할 노드가 담긴 Iterator.
		*/
		LIterator<_Ty> find(_Ty item);

		/**
		*	@brief	리스트의 첫 노드를 Iterator로 가져온다.
		*	@pre	없음.
		*	@post	리스트의 첫 노드를 Iterator에 넣어 가져온다.
		*	@return 리스트의 첫 노드가 담긴 Iterator.
		*/
		LIterator<_Ty> begin();

		/**
		*	@brief	리스트의 마지막 노드를 Iterator로 가져온다.
		*	@pre	없음.
		*	@post	리스트의 마지막 노드를 Iterator에 넣어 가져온다.
		*	@return 리스트의 마지막 노드가 담긴 Iterator.
		*/
		LIterator<_Ty> end();

	private:
		NodeType<_Ty>* m_First;		///< 리스트의 처음
		NodeType<_Ty>* m_Last;		///< 리스트의 끝
		size_t m_Length;			///< 리스트의 길이

	}; // class LinkedList end.

	   // 기본 생성자.
	template <typename _Ty>
	LinkedList<_Ty>::LinkedList()
	{
		m_First = nullptr;
		m_Last = nullptr;
		m_Length = 0;
	}

	// 소멸자.
	template <typename _Ty>
	LinkedList<_Ty>::~LinkedList()
	{
		make_empty();
	}

	// 리스트가 비었는지 확인.
	template <typename _Ty>
	bool LinkedList<_Ty>::is_empty()
	{
		return (m_Length == 0);
	}

	// 리스트를 비운다.
	template <typename _Ty>
	void LinkedList<_Ty>::make_empty()
	{
		NodeType<_Ty>* temp = m_First;

		// 리스트가 비어있다면 함수를 끝낸다.
		if (is_empty())
			return;
		else
		{
			while (temp->next != nullptr)
			{
				temp = temp->next;
				delete temp->prev;
			}
			delete temp;
			m_First = nullptr;
			m_Last = nullptr;
			m_Length = 0;
		}
	}

	// 리스트의 길이를 반환한다.
	template <typename _Ty>
	size_t LinkedList<_Ty>::length() const
	{
		return m_Length;
	}

	// 리스트에 데이터를 추가한다.
	template <typename _Ty>
	bool LinkedList<_Ty>::add(_Ty& item)
	{
		NodeType<_Ty>* target = new NodeType<_Ty>(item);
		NodeType<_Ty>* cur;

		// 리스트가 비어있다면 처음 삽입.
		if (is_empty())
		{
			m_First = target;
			m_Last = target;
			m_Length = 1;
			return true;
		}
		else
		{
			cur = m_First;
			while (cur != nullptr)
			{
				// 새로 넣을 데이터가 더 작은 순간
				if (item < cur->data)
				{
					// 넣을 곳이 맨 앞이라면
					if (cur == m_First)
					{
						target->next = cur;
						cur->prev = target;
						m_First = target;
					}
					else
					{
						target->prev = cur->prev;
						target->next = cur;
						(cur->prev)->next = target;
						cur->prev = target;
					}

					m_Length++;
					return true;
				}
				// 만약 같은 데이터가 있다면
				else if (item == cur->data)
					return false;
				// 조건이 만족하지 않는다면
				else
					cur = cur->next;
			}
			// 이제는 넣을 곳이 맨 뒤이다.
			m_Last->next = target;
			target->prev = m_Last;
			m_Last = target;
			m_Length++;
			return true;
		}
	}

	template<typename _Ty>
	bool LinkedList<_Ty>::add(_Ty && item)
	{
		NodeType<_Ty>* target = new NodeType<_Ty>(item);
		NodeType<_Ty>* cur;

		// 리스트가 비어있다면 처음 삽입.
		if (is_empty())
		{
			m_First = target;
			m_Last = target;
			m_Length = 1;
			return true;
		}
		else
		{
			cur = m_First;
			while (cur != nullptr)
			{
				// 새로 넣을 데이터가 더 작은 순간
				if (item < cur->data)
				{
					// 넣을 곳이 맨 앞이라면
					if (cur == m_First)
					{
						target->next = cur;
						cur->prev = target;
						m_First = target;
					}
					else
					{
						target->prev = cur->prev;
						target->next = cur;
						(cur->prev)->next = target;
						cur->prev = target;
					}

					m_Length++;
					return true;
				}
				// 만약 같은 데이터가 있다면
				else if (item == cur->data)
					return false;
				// 조건이 만족하지 않는다면
				else
					cur = cur->next;
			}
			// 이제는 넣을 곳이 맨 뒤이다.
			m_Last->next = target;
			target->prev = m_Last;
			m_Last = target;
			m_Length++;
			return true;
		}
	}

	template<typename _Ty>
	NodeType<_Ty>* LinkedList<_Ty>::add_and_get(_Ty & item)
	{
		NodeType<_Ty>* target = new NodeType<_Ty>(item);
		NodeType<_Ty>* cur;

		// 리스트가 비어있다면 처음 삽입.
		if (is_empty())
		{
			m_First = target;
			m_Last = target;
			m_Length = 1;
			return target;
		}
		else
		{
			cur = m_First;
			while (cur != nullptr)
			{
				// 새로 넣을 데이터가 더 작은 순간
				if (item < cur->data)
				{
					// 넣을 곳이 맨 앞이라면
					if (cur == m_First)
					{
						target->next = cur;
						cur->prev = target;
						m_First = target;
					}
					else
					{
						target->prev = cur->prev;
						target->next = cur;
						(cur->prev)->next = target;
						cur->prev = target;
					}

					m_Length++;
					return target;
				}
				// 만약 같은 데이터가 있다면
				else if (item == cur->data)
					return nullptr;
				// 조건이 만족하지 않는다면
				else
					cur = cur->next;
			}
			// 이제는 넣을 곳이 맨 뒤이다.
			m_Last->next = target;
			target->prev = m_Last;
			m_Last = target;
			m_Length++;
			return target;
		}
	}

	// 데이터를 삭제한다.
	template <typename _Ty>
	bool LinkedList<_Ty>::remove(_Ty& item)
	{
		NodeType<_Ty>* temp = m_First;

		// 리스트가 비었다면
		if (is_empty())
			return false;
		// 리스트가 1개만 있다면
		else if (m_Length == 1)
		{
			delete temp;
			m_First = nullptr;
			m_Last = nullptr;
			m_Length = 0;
			return true;
		}
		else
		{
			while (temp != nullptr)
			{
				// 데이터가 같다면
				if (item == temp->data)
				{
					// 만약 첫번째 데이터라면
					if (temp == m_First)
					{
						(temp->next)->prev = nullptr;
						m_First = temp->next;
					}
					// 만약 마지막 데이터라면
					else if (temp == m_Last)
					{
						(temp->prev)->next = nullptr;
						m_Last = temp->prev;
					}
					else
					{
						(temp->prev)->next = temp->next;
						(temp->next)->prev = temp->prev;
					}
					m_Length--;
					delete temp;
					return true;
				}
				else
					temp = temp->next;
			}
		}
		return false;
	}

	// 리스트의 데이터를 변경한다.
	template <typename _Ty>
	bool LinkedList<_Ty>::replace(_Ty& item)
	{
		NodeType<_Ty>* temp = m_First;

		// 리스트가 비었다면
		if (is_empty())
			return false;
		else
		{
			while (temp != nullptr)
			{
				// 데이터가 같다면
				if (item == temp->data)
				{
					temp->data = item;
					return true;
				}
				else
					temp = temp->next;
			}
		}
		return false;
	}

	// 아이템과 일치하는 아이템을 리스트에서 가져온다.
	template <typename _Ty>
	bool LinkedList<_Ty>::get(_Ty& item)
	{
		NodeType<_Ty>* temp = m_First;

		// 리스트가 비었다면
		if (is_empty())
			return false;
		else
		{
			while (temp != nullptr)
			{
				// 데이터가 같다면
				if (item == temp->data)
				{
					item = temp->data;
					return true;
				}
				else
					temp = temp->next;
			}
		}
		return false;
	}

	template<typename _Ty>
	LIterator<_Ty> LinkedList<_Ty>::find(_Ty item)
	{
		NodeType<_Ty>* temp = m_First;

		// 리스트가 비었다면
		if (is_empty())
			return LIterator<_Ty>(nullptr);
		else
		{
			while (temp != nullptr)
			{
				// 데이터가 같다면
				if (item == temp->data)
					return LIterator<_Ty>(temp);
				else
					temp = temp->next;
			}
		}
		return LIterator<_Ty>(nullptr);
	}

	// 리스트의 첫 노드를 가져온다.
	template <typename _Ty>
	LIterator<_Ty> LinkedList<_Ty>::begin()
	{
		return LIterator<_Ty>(m_First);
	}

	// 리스트의 마지막 노드를 가져온다.
	template <typename _Ty>
	LIterator<_Ty> LinkedList<_Ty>::end()
	{
		return LIterator<_Ty>(m_Last->next);
	}


} // namespace kmh end.

#endif _LINKED_LIST_H