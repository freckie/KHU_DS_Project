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
		bool is_empty();

		/**
		*	@brief	����Ʈ�� ����.
		*	@pre	����.
		*	@post	��� �����͸� �����.
		*/
		void make_empty();

		/**
		*	@brief	����Ʈ�� ���̸� ��ȯ�Ѵ�.
		*	@pre	����.
		*	@post	����.
		*	@return	m_Length ����Ʈ�� ���� ��ȯ.
		*/
		size_t length() const;

		/**
		*	@brief	���ο� �����͸� ����Ʈ�� �߰��Ѵ�.
		*	@pre	����.
		*	@post	���ο� �����͸� ����Ʈ�� �߰��Ѵ�.
		*	@param	item	���ο� ������.
		*	@return �� �۵��ߴٸ� 1, �ƴ϶�� 0.
		*/
		bool add(_Ty& item);

		/**
		*	@brief	���ο� �����͸� ����Ʈ�� �߰��Ѵ�.
		*	@pre	����.
		*	@post	���ο� �����͸� ����Ʈ�� �߰��Ѵ�.
		*	@param	item	���ο� ������.
		*	@return �� �۵��ߴٸ� 1, �ƴ϶�� 0.
		*/
		bool add(_Ty&& item);

		/**
		*	@brief	���ο� �����͸� ����Ʈ�� �߰��Ѵ�.
		*	@pre	����.
		*	@post	���ο� �����͸� ����Ʈ�� �߰��Ѵ�.
		*	@param	item	���ο� ������.
		*	@return �� �۵��ߴٸ� 1, �ƴ϶�� 0.
		*/
		NodeType<_Ty>* add_and_get(_Ty& item);

		/**
		*	@brief	�����͸� ã�� ����Ʈ���� �����Ѵ�.
		*	@pre	����.
		*	@post	�����͸� ����Ʈ���� �����Ѵ�.
		*	@param	item	������ ������.
		*	@return �� �۵��ߴٸ� 1, �ƴ϶�� 0.
		*/
		bool remove(_Ty& item);

		/**
		*	@brief	�Է¹��� ���������� ������ �ٲ۴�.
		*	@pre	����.
		*	@post	���ο� �����ͷ� ��ü�Ѵ�.
		*	@param	item	���� ��ü�� ������.
		*	@return �� �۵��ߴٸ� 1, �ƴ϶�� 0.
		*/
		bool replace(_Ty& item);

		/**
		*	@brief	����Ʈ�� �������� �����´�.
		*	@pre	����.
		*	@post	�˻��� �����͸� �����ۿ� �ִ´�.
		*	@param	item	������ ������.
		*	@return �� �۵��ߴٸ� 1, �ƴ϶�� 0.
		*/
		bool get(_Ty& item);

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
		make_empty();
	}

	// ����Ʈ�� ������� Ȯ��.
	template <typename _Ty>
	bool LinkedList<_Ty>::is_empty()
	{
		return (m_Length == 0);
	}

	// ����Ʈ�� ����.
	template <typename _Ty>
	void LinkedList<_Ty>::make_empty()
	{
		NodeType<_Ty>* temp = m_First;

		// ����Ʈ�� ����ִٸ� �Լ��� ������.
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

	// ����Ʈ�� ���̸� ��ȯ�Ѵ�.
	template <typename _Ty>
	size_t LinkedList<_Ty>::length() const
	{
		return m_Length;
	}

	// ����Ʈ�� �����͸� �߰��Ѵ�.
	template <typename _Ty>
	bool LinkedList<_Ty>::add(_Ty& item)
	{
		NodeType<_Ty>* target = new NodeType<_Ty>(item);
		NodeType<_Ty>* cur;

		// ����Ʈ�� ����ִٸ� ó�� ����.
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
					return true;
				}
				// ���� ���� �����Ͱ� �ִٸ�
				else if (item == cur->data)
					return false;
				// ������ �������� �ʴ´ٸ�
				else
					cur = cur->next;
			}
			// ������ ���� ���� �� ���̴�.
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

		// ����Ʈ�� ����ִٸ� ó�� ����.
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
					return true;
				}
				// ���� ���� �����Ͱ� �ִٸ�
				else if (item == cur->data)
					return false;
				// ������ �������� �ʴ´ٸ�
				else
					cur = cur->next;
			}
			// ������ ���� ���� �� ���̴�.
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

		// ����Ʈ�� ����ִٸ� ó�� ����.
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
					return target;
				}
				// ���� ���� �����Ͱ� �ִٸ�
				else if (item == cur->data)
					return nullptr;
				// ������ �������� �ʴ´ٸ�
				else
					cur = cur->next;
			}
			// ������ ���� ���� �� ���̴�.
			m_Last->next = target;
			target->prev = m_Last;
			m_Last = target;
			m_Length++;
			return target;
		}
	}

	// �����͸� �����Ѵ�.
	template <typename _Ty>
	bool LinkedList<_Ty>::remove(_Ty& item)
	{
		NodeType<_Ty>* temp = m_First;

		// ����Ʈ�� ����ٸ�
		if (is_empty())
			return false;
		// ����Ʈ�� 1���� �ִٸ�
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
					return true;
				}
				else
					temp = temp->next;
			}
		}
		return false;
	}

	// ����Ʈ�� �����͸� �����Ѵ�.
	template <typename _Ty>
	bool LinkedList<_Ty>::replace(_Ty& item)
	{
		NodeType<_Ty>* temp = m_First;

		// ����Ʈ�� ����ٸ�
		if (is_empty())
			return false;
		else
		{
			while (temp != nullptr)
			{
				// �����Ͱ� ���ٸ�
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

	// �����۰� ��ġ�ϴ� �������� ����Ʈ���� �����´�.
	template <typename _Ty>
	bool LinkedList<_Ty>::get(_Ty& item)
	{
		NodeType<_Ty>* temp = m_First;

		// ����Ʈ�� ����ٸ�
		if (is_empty())
			return false;
		else
		{
			while (temp != nullptr)
			{
				// �����Ͱ� ���ٸ�
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

		// ����Ʈ�� ����ٸ�
		if (is_empty())
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