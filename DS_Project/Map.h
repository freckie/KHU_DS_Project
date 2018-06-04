#pragma once

#ifndef _MAP_H
#define _MAP_H

#include"BinaryTreeIterator.h"
#include"BinaryTree.h"

namespace kmh
{
	/**
	*	Map에 사용하는 Struct
	*/
	template <typename Key, typename Val>
	struct Pair
	{
		Key key;
		Val val;

		Pair(Key key, Val val) : key(key), val(val) {}

		friend bool operator<(Pair& lhs, Pair& rhs);
		friend bool operator>(Pair& lhs, Pair& rhs);
		friend bool operator==(Pair& lhs, Pair& rhs);
		friend bool operator!=(Pair& lhs, Pair& rhs);
	};

	template <typename Key, typename Val>
	Pair<Key, Val>& make_map_pair(Key key, Val val);

	/**
	*	Binary Search Tree를 이용한 Map
	*/
	template <typename Key, typename Val>
	class Map
	{

	public:
		/**
		*	기본 생성자.
		*/
		Map() {}

		/**
		*	소멸자.
		*/
		~Map() {}

		/**
		*	@brief	Tree가 비었는지 확인한다.
		*	@pre	없음.
		*	@post	없음.
		*	@return	비었으면 true, 아니라면 false.
		*/
		bool is_empty() const;

		/**
		*	@brief	Tree에 추가할 수 있는지 확인한다.
		*	@pre	없음.
		*	@post	없음.
		*	@return	추가할 수 없다면 true, 아니라면 false.
		*/
		bool is_full() const;

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
		bool add(Pair& _Pair);

		/**
		*	@brief	Tree에 데이터를 추가하고, 데이터의 포인터를 반환한다.
		*	@pre	없음.
		*	@post	없음.
		*	@param	_Item	추가할 데이터.
		*	@return	추가한 데이터의 노드 포인터. 추가 실패라면 nullptr.
		*/
		BTreeNode<Pair<Key, Val>>* add_and_get(Pair<Key, Val>& _Item);

		/**
		*	@brief	Tree에 Pair 객체를 만들어추가한다.
		*	@pre	없음.
		*	@post	없음.
		*	@param	_Key	추가할 키.
		*	@param	_Val	추가할 데이터.
		*	@return	성공 여부.
		*/
		bool emplace(Key& _Key, Val& _Val);

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
		BinaryTreeIterator<Pair<Key, Val>> begin();

		/**
		*	@brief	Tree의 제일 큰 값 다음의 iterator를 반환한다.
		*	@pre	없음.
		*	@post	없음.
		*	@return	nullptr 담긴 iterator.
		*/
		BinaryTreeIterator<Pair<Key, Val>> end();

		/**
		*	@brief	Tree에서 item검색하여 iterator로 반환.
		*	@pre	없음.
		*	@post	없음.
		*	@param	_Key	iterator 얻고 싶은 key
		*	@return	일치하는 값을 가진 iterator.
		*/
		BinaryTreeIterator<Pair<Key, Val>> find(Key _Key);

	private:
		kmh::BinaryTree<Pair<Key, Val>> _Tree;

	};

	template<typename Key, typename Val>
	bool Map<Key, Val>::is_empty() const
	{
		return _Tree.is_empty();
	}

	template<typename Key, typename Val>
	bool Map<Key, Val>::is_full() const
	{
		return _Tree.is_full();
	}

	template<typename Key, typename Val>
	void Map<Key, Val>::make_empty()
	{
		_Tree.make_empty();
	}

	template<typename Key, typename Val>
	int Map<Key, Val>::length() const
	{
		return _Tree.length();
	}

	template<typename Key, typename Val>
	bool Map<Key, Val>::add(Pair<Key, Val>& _Pair)
	{
		return _Tree.add(_Pair);
	}

	template<typename Key, typename Val>
	BTreeNode<Pair<Key, Val>>* Map<Key, Val>::add_and_get(Pair<Key, Val>& _Item)
	{
		return _Tree.add_and_get(_Item);
	}

	template<typename Key, typename Val>
	bool Map<Key, Val>::emplace(Key& _Key, Val& _Val)
	{
		return _Tree.add(make_map_pair(_Key, _Val));
	}

	template<typename Key, typename Val>
	bool Map<Key, Val>::remove(Key _Key)
	{
		Pair<Key, Val> temp;
		temp.key = _Key;

		return _Tree.remove(temp);
	}

	template<typename Key, typename Val>
	BinaryTreeIterator<Pair<Key, Val>> Map<Key, Val>::begin()
	{
		return _Tree.begin();
	}

	template<typename Key, typename Val>
	BinaryTreeIterator<Pair<Key, Val>> Map<Key, Val>::end()
	{
		return _Tree.end();
	}

	template<typename Key, typename Val>
	BinaryTreeIterator<Pair<Key, Val>> Map<Key, Val>::find(Key _Key)
	{
		Pair<Key, Val> temp;
		temp.key = _Key;

		return _Tree.find(temp);
	}
}

#endif _MAP_H