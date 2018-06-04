#pragma once

#ifndef _LIST_ListMap_H
#define _LIST_ListMap_H

#include"LinkedListIterator.h"
#include"LinkedList.h"

namespace kmh
{
	/**
	*	ListMap에 사용하는 Struct
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
	*	Doubly-Linked List를 이용한 ListMap
	*/
	template <typename Key, typename Val>
	class ListMap
	{

	public:
		/**
		*	기본 생성자.
		*/
		ListMap() {}

		/**
		*	소멸자.
		*/
		~ListMap() {}

		/**
		*	@brief	Tree가 비었는지 확인한다.
		*	@pre	없음.
		*	@post	없음.
		*	@return	비었으면 true, 아니라면 false.
		*/
		bool is_empty();

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
		*	@param	_Pair	추가할 데이터.
		*	@return	성공 여부.
		*/
		bool add(Pair<Key, Val>& _Pair);

		/**
		*	@brief	Tree에 데이터를 추가한다.
		*	@pre	없음.
		*	@post	없음.
		*	@param	_Pair	추가할 데이터.
		*	@return	성공 여부.
		*/
		bool add(Pair<Key, Val>&& _Pair);

		/**
		*	@brief	Tree에 Pair 객체를 만들어추가한다.
		*	@pre	없음.
		*	@post	없음.
		*	@param	_Key	추가할 키.
		*	@param	_Val	추가할 데이터.
		*	@return	성공 여부.
		*/
		bool emplace(Key _Key, Val _Val);

		/**
		*	@brief	Tree에서 데이터를 삭제한다.
		*	@pre	없음.
		*	@post	없음.
		*	@param	Key	삭제할 Key
		*	@return	성공 여부.
		*/
		bool remove(Key _Key);

		/**
		*	@brief	Tree의 제일 작은 값의 iterator를 반환한다.
		*	@pre	없음.
		*	@post	없음.
		*	@return	제일 작은 값의 iterator.
		*/
		LinkedListIterator<Pair<Key, Val>> begin();

		/**
		*	@brief	Tree의 제일 큰 값 다음의 iterator를 반환한다.
		*	@pre	없음.
		*	@post	없음.
		*	@return	nullptr 담긴 iterator.
		*/
		LinkedListIterator<Pair<Key, Val>> end();

		/**
		*	@brief	Tree에서 item검색하여 iterator로 반환.
		*	@pre	없음.
		*	@post	없음.
		*	@param	_Key	iterator 얻고 싶은 key
		*	@return	일치하는 값을 가진 iterator.
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