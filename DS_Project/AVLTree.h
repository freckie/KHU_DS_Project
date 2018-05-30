#pragma once

#ifndef _AVL_TREE_H
#define _AVL_TREE_H

#include<iostream>

#include"AVLTreeIterator.h"

namespace kmh
{
	/**
	*	전방선언.
	*/
	template <typename _Ty>
	class AVLTreeIterator;

	template <typename _Ty>
	class AVLTree;


	/**
	*	using.
	*/
	template <typename _Ty>
	using Tree = AVLTree<_Ty>;
	template <typename _Ty>
	using TIterator = AVLTreeIterator<_Ty>;


	/**
	*	Tree에 사용되는 TreeNode 구조체
	*/
	template <typename _Ty>
	struct TreeNode
	{
		_Ty data;
		TreeNode* parent;
		TreeNode* left;
		TreeNode* right;

		TreeNode(_Ty _data)
			: data(_data), parent(nullptr), left(nullptr), right(nullptr) {}
	};


	/**
	*	AVL Tree
	*/
	template <typename _Ty>
	class AVLTree
	{

		friend class AVLTreeIterator<_Ty>;

	public:
		/**
		*	기본 생성자.
		*/
		AVLTree();

		/**
		*	소멸자.
		*/
		~AVLTree();

		AVLTreeIterator<_Ty> insert(_Ty _Item);
		AVLTreeIterator<_Ty> insert(_Ty _Item, bool& _Exist);
		bool remove(_Ty& item);
		void make_empty();
		AVLTreeIterator<_Ty> get(_Ty _Item);

	private:
		TreeNode<_Ty>* _Root;
		TreeNode<_Ty>* _First;
		TreeNode<_Ty>* _Last;
		size_t _Size;

		// Private 함수들

		TreeNode<_Ty>* _get_next_node(TreeNode<_Ty>* _Node);
		void _swap_node_location(TreeNode<_Ty>* _Node1, TreeNode<_Ty>* _Node2);
		TreeNode<_Ty>* _find(TreeNode<_Ty>* _Node, _Ty& _Item);
		AVLTreeIterator<_Ty> _insert_at(TreeNode<_Ty>* _Node, _Ty& _Item);
		void _erase_node(TreeNode<_Ty>* _Node);
		void _rebalance(TreeNode<_Ty>* _Node);
		int _calc_balance_factor(TreeNode<_Ty>* _Node);
		TreeNode<_Ty>* _rotate_left(TreeNode<_Ty>* _Node);
		TreeNode<_Ty>* _rotate_right(TreeNode<_Ty>* _Node);
		TreeNode<_Ty>* _rotate_ll(TreeNode<_Ty>* _Node);
		TreeNode<_Ty>* _rotate_rr(TreeNode<_Ty>* _Node);
		TreeNode<_Ty>* _rotate_lr(TreeNode<_Ty>* _Node);
		TreeNode<_Ty>* _rotate_rl(TreeNode<_Ty>* _Node);
		void _invalidate_height(TreeNode<_Ty>* _Node);
		void _delete_all(TreeNode<_Ty>* _Node);
	};
}

#endif _AVL_TREE_H