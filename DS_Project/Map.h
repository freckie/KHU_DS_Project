#pragma once

#ifndef _MAP_H
#define _MAP_H

#include"BinaryTreeIterator.h"
#include"BinaryTree.h"

namespace kmh
{
	/**
	*	Map�� ����ϴ� Struct
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
	*	Binary Search Tree�� �̿��� Map
	*/
	template <typename Key, typename Val>
	class Map
	{

	public:
		/**
		*	�⺻ ������.
		*/
		Map() {}

		/**
		*	�Ҹ���.
		*/
		~Map() {}

		/**
		*	@brief	Tree�� ������� Ȯ���Ѵ�.
		*	@pre	����.
		*	@post	����.
		*	@return	������� true, �ƴ϶�� false.
		*/
		bool is_empty() const;

		/**
		*	@brief	Tree�� �߰��� �� �ִ��� Ȯ���Ѵ�.
		*	@pre	����.
		*	@post	����.
		*	@return	�߰��� �� ���ٸ� true, �ƴ϶�� false.
		*/
		bool is_full() const;

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
		bool add(Pair& _Pair);

		/**
		*	@brief	Tree�� �����͸� �߰��ϰ�, �������� �����͸� ��ȯ�Ѵ�.
		*	@pre	����.
		*	@post	����.
		*	@param	_Item	�߰��� ������.
		*	@return	�߰��� �������� ��� ������. �߰� ���ж�� nullptr.
		*/
		BTreeNode<Pair<Key, Val>>* add_and_get(Pair<Key, Val>& _Item);

		/**
		*	@brief	Tree�� Pair ��ü�� ������߰��Ѵ�.
		*	@pre	����.
		*	@post	����.
		*	@param	_Key	�߰��� Ű.
		*	@param	_Val	�߰��� ������.
		*	@return	���� ����.
		*/
		bool emplace(Key& _Key, Val& _Val);

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
		BinaryTreeIterator<Pair<Key, Val>> begin();

		/**
		*	@brief	Tree�� ���� ū �� ������ iterator�� ��ȯ�Ѵ�.
		*	@pre	����.
		*	@post	����.
		*	@return	nullptr ��� iterator.
		*/
		BinaryTreeIterator<Pair<Key, Val>> end();

		/**
		*	@brief	Tree���� item�˻��Ͽ� iterator�� ��ȯ.
		*	@pre	����.
		*	@post	����.
		*	@param	_Key	iterator ��� ���� key
		*	@return	��ġ�ϴ� ���� ���� iterator.
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