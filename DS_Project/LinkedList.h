#pragma once

#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include<iostream>

#include "LinkedListIterator.h"

namespace kmh
{
	/**
	*	���漱��.
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
	*	List�� ���Ǵ� NodeType ����ü
	*/
	template <typename _Ty>
	struct NodeType
	{
		_Ty data;	///< ����� ������
		NodeType* prev;	///< ���� ��� ����Ų��.
		NodeType* next;	///< ���� ��� ����Ų��.

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
		*	�⺻ ������.
		*/
		LinkedList();

		/**
		*	�Ҹ���.
		*/
		~LinkedList();

		/**
		*	@brief	���� ����Ʈ�� ������� Ȯ��.
		*	@pre	m_nLength�� ���� ������ �Ѵ�.
		*	@post	����.
		*	@return	����Ʈ�� ��������� true, �ƴ϶�� false.
		*/
		bool IsEmpty();

		/**
		*	@brief	����Ʈ�� ����.
		*	@pre	����.
		*	@post	��� �����͸� �����.
		*/
		void MakeEmpty();

		/**
		*	@brief	����Ʈ�� ���̸� ��ȯ�Ѵ�.
		*	@pre	����.
		*	@post	����.
		*	@return	m_Length ����Ʈ�� ���� ��ȯ.
		*/
		size_t GetLength() const;

		/**
		*	@brief	���ο� �����͸� ����Ʈ�� �߰��Ѵ�.
		*	@pre	����.
		*	@post	���ο� �����͸� ����Ʈ�� �߰��Ѵ�.
		*	@param	item	���ο� ������.
		*	@return �� �۵��ߴٸ� 1, �ƴ϶�� 0.
		*/
		int Add(_Ty item);

		/**
		*	@brief	�����͸� ã�� ����Ʈ���� �����Ѵ�.
		*	@pre	����.
		*	@post	�����͸� ����Ʈ���� �����Ѵ�.
		*	@param	item	������ ������.
		*	@return �� �۵��ߴٸ� 1, �ƴ϶�� 0.
		*/
		int Delete(_Ty item);

		/**
		*	@brief	�Է¹��� ���������� ������ �ٲ۴�.
		*	@pre	����.
		*	@post	���ο� �����ͷ� ��ü�Ѵ�.
		*	@param	item	���� ��ü�� ������.
		*	@return �� �۵��ߴٸ� 1, �ƴ϶�� 0.
		*/
		int Replace(_Ty item);

		/**
		*	@brief	����Ʈ�� �������� �����´�.
		*	@pre	����.
		*	@post	�˻��� �����͸� �����ۿ� �ִ´�.
		*	@param	item	������ ������.
		*	@return �� �۵��ߴٸ� 1, �ƴ϶�� 0.
		*/
		int Get(_Ty& item);

		/**
		*	@brief	����Ʈ�� �������� �˻��Ͽ� Iterator�� �����´�.
		*	@pre	����.
		*	@post	����Ʈ�� �������� �˻��Ͽ� Iterator�� �����´�.
		*	@return �˻��� ��尡 ��� Iterator.
		*/
		LIterator<_Ty> find(_Ty item);

		/**
		*	@brief	����Ʈ�� ù ��带 Iterator�� �����´�.
		*	@pre	����.
		*	@post	����Ʈ�� ù ��带 Iterator�� �־� �����´�.
		*	@return ����Ʈ�� ù ��尡 ��� Iterator.
		*/
		LIterator<_Ty> begin();

		/**
		*	@brief	����Ʈ�� ������ ��带 Iterator�� �����´�.
		*	@pre	����.
		*	@post	����Ʈ�� ������ ��带 Iterator�� �־� �����´�.
		*	@return ����Ʈ�� ������ ��尡 ��� Iterator.
		*/
		LIterator<_Ty> end();

	private:
		NodeType<_Ty>* m_First;		///< ����Ʈ�� ó��
		NodeType<_Ty>* m_Last;		///< ����Ʈ�� ��
		size_t m_Length;			///< ����Ʈ�� ����

	}; // class LinkedList end.

	   // �⺻ ������.
	template <typename _Ty>
	LinkedList<_Ty>::LinkedList()
	{
		m_First = nullptr;
		m_Last = nullptr;
		m_Length = 0;
	}

	// �Ҹ���.
	template <typename _Ty>
	LinkedList<_Ty>::~LinkedList()
	{
		MakeEmpty();
	}

	// ����Ʈ�� ������� Ȯ��.
	template <typename _Ty>
	bool LinkedList<_Ty>::IsEmpty()
	{
		return (m_Length == 0);
	}

	// ����Ʈ�� ����.
	template <typename _Ty>
	void LinkedList<_Ty>::MakeEmpty()
	{
		NodeType<_Ty>* temp = m_First;

		// ����Ʈ�� ����ִٸ� �Լ��� ������.
		if (IsEmpty())
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

	// ����Ʈ�� ���̸� ��ȯ�Ѵ�.
	template <typename _Ty>
	size_t LinkedList<_Ty>::GetLength() const
	{
		return m_Length;
	}

	// ����Ʈ�� �����͸� �߰��Ѵ�.
	template <typename _Ty>
	int LinkedList<_Ty>::Add(_Ty item)
	{
		NodeType<_Ty>* target = new NodeType<_Ty>(item);
		NodeType<_Ty>* cur;

		// ����Ʈ�� ����ִٸ� ó�� ����.
		if (IsEmpty())
		{
			m_First = target;
			m_Last = target;
			m_Length = 1;
			return 1;
		}
		else
		{
			cur = m_First;
			while (cur != nullptr)
			{
				// ���� ���� �����Ͱ� �� ���� ����
				if (item < cur->data)
				{
					// ���� ���� �� ���̶��
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
					return 1;
				}
				// ���� ���� �����Ͱ� �ִٸ�
				else if (item == cur->data)
					return 0;
				// ������ �������� �ʴ´ٸ�
				else
					cur = cur->next;
			}
			// ������ ���� ���� �� ���̴�.
			m_Last->next = target;
			target->prev = m_Last;
			m_Last = target;
			m_Length++;
			return 1;
		}
	}

	// �����͸� �����Ѵ�.
	template <typename _Ty>
	int LinkedList<_Ty>::Delete(_Ty item)
	{
		NodeType<_Ty>* temp = m_First;

		// ����Ʈ�� ����ٸ�
		if (IsEmpty())
			return 0;
		// ����Ʈ�� 1���� �ִٸ�
		else if (m_Length == 1)
		{
			delete temp;
			m_First = nullptr;
			m_Last = nullptr;
			m_Length = 0;
			return 1;
		}
		else
		{
			while (temp != nullptr)
			{
				// �����Ͱ� ���ٸ�
				if (item == temp->data)
				{
					// ���� ù��° �����Ͷ��
					if (temp == m_First)
					{
						(temp->next)->prev = nullptr;
						m_First = temp->next;
					}
					// ���� ������ �����Ͷ��
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
					return 1;
				}
				else
					temp = temp->next;
			}
		}
		return 0;
	}

	// ����Ʈ�� �����͸� �����Ѵ�.
	template <typename _Ty>
	int LinkedList<_Ty>::Replace(_Ty item)
	{
		NodeType<_Ty>* temp = m_First;

		// ����Ʈ�� ����ٸ�
		if (IsEmpty())
			return 0;
		else
		{
			while (temp != nullptr)
			{
				// �����Ͱ� ���ٸ�
				if (item == temp->data)
				{
					temp->data = item;
					return 1;
				}
				else
					temp = temp->next;
			}
		}
		return 0;
	}

	// �����۰� ��ġ�ϴ� �������� ����Ʈ���� �����´�.
	template <typename _Ty>
	int LinkedList<_Ty>::Get(_Ty& item)
	{
		NodeType<_Ty>* temp = m_First;

		// ����Ʈ�� ����ٸ�
		if (IsEmpty())
			return 0;
		else
		{
			while (temp != nullptr)
			{
				// �����Ͱ� ���ٸ�
				if (item == temp->data)
				{
					item = temp->data;
					return 1;
				}
				else
					temp = temp->next;
			}
		}
		return 0;
	}

	template<typename _Ty>
	inline LIterator<_Ty> LinkedList<_Ty>::find(_Ty item)
	{
		NodeType<_Ty>* temp = m_First;

		// ����Ʈ�� ����ٸ�
		if (IsEmpty())
			return LIterator<_Ty>(nullptr);
		else
		{
			while (temp != nullptr)
			{
				// �����Ͱ� ���ٸ�
				if (item == temp->data)
					return LIterator<_Ty>(temp);
				else
					temp = temp->next;
			}
		}
		return LIterator<_Ty>(nullptr);
	}

	// ����Ʈ�� ù ��带 �����´�.
	template <typename _Ty>
	LIterator<_Ty> LinkedList<_Ty>::begin()
	{
		return LIterator<_Ty>(m_First);
	}

	// ����Ʈ�� ������ ��带 �����´�.
	template <typename _Ty>
	LIterator<_Ty> LinkedList<_Ty>::end()
	{
		return LIterator<_Ty>(m_Last->next);
	}


} // namespace kmh end.

#endif _LINKED_LIST_H