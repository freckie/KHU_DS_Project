#pragma once

#ifndef _LIST_ListMap_H
#define _LIST_ListMap_H

#include"LinkedListIterator.h"
#include"LinkedList.h"

namespace kmh
{
	/**
	*	ListMap�� ����ϴ� Struct
	*/
	template <typename Key, typename Val>
	struct Pair
	{
		Key key;
		Val val;

		Pair() {}
		Pair(Key key, Val val) : key(key), val(val) {}

		friend bool operator<(Pair<Key, Val>& lhs, Pair<Key, Val>& rhs)
		{
			return (lhs.key < rhs.key);
		}

		friend bool operator>(Pair<Key, Val>& lhs, Pair<Key, Val>& rhs)
		{
			return (lhs.key > rhs.key);
		}

		friend bool operator==(Pair<Key, Val>& lhs, Pair<Key, Val>& rhs)
		{
			return (lhs.key == rhs.key);
		}

		friend bool operator!=(Pair<Key, Val>& lhs, Pair<Key, Val>& rhs)
		{
			return (lhs.key != rhs.key);
		}
	};

	template <typename Key, typename Val>
	Pair<Key, Val> make_ListMap_pair(Key key, Val val)
	{
		return Pair<Key, Val>(key, val);
	}

	/**
	*	Doubly-Linked List�� �̿��� ListMap
	*/
	template <typename Key, typename Val>
	class ListMap
	{

	public:
		/**
		*	�⺻ ������.
		*/
		ListMap() {}

		/**
		*	�Ҹ���.
		*/
		~ListMap() {}

		/**
		*	@brief	Tree�� ������� Ȯ���Ѵ�.
		*	@pre	����.
		*	@post	����.
		*	@return	������� true, �ƴ϶�� false.
		*/
		bool is_empty();

		/**
		*	@brief	Tree�� ��� ����.
		*	@pre	����.
		*	@post	Tree�� �������.
		*/
		void make_empty();

		/**
		*	@brief	Tree�� ������ ���� ����.
		*	@pre	����.
		*	@post	����.
		*	@return	Tree�� ������.
		*/
		int length() const;

		/**
		*	@brief	Tree�� �����͸� �߰��Ѵ�.
		*	@pre	����.
		*	@post	����.
		*	@param	_Pair	�߰��� ������.
		*	@return	���� ����.
		*/
		bool add(Pair<Key, Val>& _Pair);

		/**
		*	@brief	Tree�� �����͸� �߰��Ѵ�.
		*	@pre	����.
		*	@post	����.
		*	@param	_Pair	�߰��� ������.
		*	@return	���� ����.
		*/
		bool add(Pair<Key, Val>&& _Pair);

		/**
		*	@brief	Tree�� Pair ��ü�� ������߰��Ѵ�.
		*	@pre	����.
		*	@post	����.
		*	@param	_Key	�߰��� Ű.
		*	@param	_Val	�߰��� ������.
		*	@return	���� ����.
		*/
		bool emplace(Key _Key, Val _Val);

		/**
		*	@brief	Tree���� �����͸� �����Ѵ�.
		*	@pre	����.
		*	@post	����.
		*	@param	Key	������ Key
		*	@return	���� ����.
		*/
		bool remove(Key _Key);

		/**
		*	@brief	Tree�� ���� ���� ���� iterator�� ��ȯ�Ѵ�.
		*	@pre	����.
		*	@post	����.
		*	@return	���� ���� ���� iterator.
		*/
		LinkedListIterator<Pair<Key, Val>> begin();

		/**
		*	@brief	Tree�� ���� ū �� ������ iterator�� ��ȯ�Ѵ�.
		*	@pre	����.
		*	@post	����.
		*	@return	nullptr ��� iterator.
		*/
		LinkedListIterator<Pair<Key, Val>> end();

		/**
		*	@brief	Tree���� item�˻��Ͽ� iterator�� ��ȯ.
		*	@pre	����.
		*	@post	����.
		*	@param	_Key	iterator ��� ���� key
		*	@return	��ġ�ϴ� ���� ���� iterator.
		*/
		LinkedListIterator<Pair<Key, Val>> find(Key _Key);

	private:
		kmh::LinkedList<Pair<Key, Val>> _List;

	};

	template<typename Key, typename Val>
	bool ListMap<Key, Val>::is_empty()
	{
		return _List.is_empty();
	}

	template<typename Key, typename Val>
	void ListMap<Key, Val>::make_empty()
	{
		_List.make_empty();
	}

	template<typename Key, typename Val>
	int ListMap<Key, Val>::length() const
	{
		return _List.length();
	}

	template<typename Key, typename Val>
	bool ListMap<Key, Val>::add(Pair<Key, Val>& _Pair)
	{
		return _List.add(_Pair);
	}

	template<typename Key, typename Val>
	bool ListMap<Key, Val>::add(Pair<Key, Val>&& _Pair)
	{
		return _List.add(_Pair);
	}

	template<typename Key, typename Val>
	bool ListMap<Key, Val>::emplace(Key _Key, Val _Val)
	{
		return _List.add(make_ListMap_pair(_Key, _Val));
	}

	template<typename Key, typename Val>
	bool ListMap<Key, Val>::remove(Key _Key)
	{
		Pair<Key, Val> temp;
		temp.key = _Key;

		return _List.remove(temp);
	}

	template<typename Key, typename Val>
	LinkedListIterator<Pair<Key, Val>> ListMap<Key, Val>::begin()
	{
		return _List.begin();
	}

	template<typename Key, typename Val>
	LinkedListIterator<Pair<Key, Val>> ListMap<Key, Val>::end()
	{
		return _List.end();
	}

	template<typename Key, typename Val>
	LinkedListIterator<Pair<Key, Val>> ListMap<Key, Val>::find(Key _Key)
	{
		Pair<Key, Val> temp;
		temp.key = _Key;

		return _List.find(temp);
	}
}

#endif _ListMap_H