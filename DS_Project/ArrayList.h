#pragma once

#ifndef _ARRAY_LIST_H
#define _ARRAY_LIST_H

#include "ArrayListIterator.h"

#include<initializer_list>

namespace kmh
{
	/**
	*	���漱��.
	*/
	template <typename _Ty>
	class ArrayListIterator;

	template <typename _Ty, size_t _Sz>
	class ArrayList;


	/**
	*	using.
	*/
	template <typename _Ty, size_t _Sz>
	using Array = ArrayList<_Ty, _Sz>;
	template <typename _Ty>
	using AIterator = ArrayListIterator<_Ty>;


	/**
	*	ArrayList
	*/
	template <typename _Ty, size_t _Sz>
	class ArrayList
	{

		friend class ArrayListIterator<_Ty>;

	public:
		/**
		*	�⺻ ������.
		*/
		ArrayList();

		/**
		*	initializer_list ����� ������.
		*/
		ArrayList(std::initializer_list<_Ty> _Init);

		/**
		*	�Ҹ���.
		*/
		~ArrayList();

		/**
		*	@brief	Array�� ������� Ȯ���Ѵ�.
		*	@pre	����.
		*	@post	����.
		*	@return	������� true, �ƴ϶�� false.
		*/
		bool is_empty() const;

		/**
		*	@brief	Array�� ����� ��ȯ�Ѵ�.
		*	@pre	����.
		*	@post	����.
		*	@return	���� ������.
		*/
		size_t size() const;

		/**
		*	@brief	���� Array�� ���� �迭�� �����´�.
		*	@pre	array�� �ʱ�ȭ�Ǿ�� �Ѵ�.
		*	@post	����.
		*	@return	���� �迭�� �ּҰ�.
		*/
		_Ty* data();

		/**
		*	@brief	Array�� �ش� index���� �����´�.
		*	@pre	array�� �ʱ�ȭ�Ǿ�� �Ѵ�.
		*	@post	����.
		*	@param	_Pos	index.
		*	@return	�ش� index�� ������.
		*/
		_Ty& at(size_t _Pos);

		/**
		*	@brief	Array�� �� ���� �����͸� Iterator�� ��� ��ȯ�Ѵ�.
		*	@pre	array�� �ʱ�ȭ�Ǿ�� �Ѵ�.
		*	@post	����.
		*	@return	�� ���� Iterator.
		*/
		ArrayListIterator<_Ty> begin();

		/**
		*	@brief	Array�� �� ���� �����͸� Iterator�� ��� ��ȯ�Ѵ�.
		*	@pre	array�� �ʱ�ȭ�Ǿ�� �Ѵ�.
		*	@post	����.
		*	@return	�� ���� Iterator.
		*/
		ArrayListIterator<_Ty> end();

		/**
		*	@brief	Array ���� ������.
		*	@pre	�Ķ���Ͱ� �ʱ�ȭ �Ǿ�� �Ѵ�.
		*	@post	����.
		*	@param	_Rhs	�Ķ���� Array.
		*	@return	this.
		*/
		ArrayList<_Ty, _Sz>& operator=(ArrayList<_Ty, _Sz>& _Rhs);

		/**
		*	@brief	Array ���� ������.
		*	@pre	�Ķ���Ͱ� �ʱ�ȭ �Ǿ�� �Ѵ�.
		*	@post	����.
		*	@param	_Rhs	�Ķ���� initializer_list.
		*	@return	this.
		*/
		ArrayList<_Ty, _Sz>& operator=(std::initializer_list<_Ty> _Init);

	private:
		_Ty * _Elems;
		size_t _Size;
	};

	// �⺻ ������
	template<typename _Ty, size_t _Sz>
	ArrayList<_Ty, _Sz>::ArrayList()
	{
		// ����� �߸��Ǿ����� ������ ����.
		static_assert(!(_Sz <= 0), "Wrong ArrayList Size.");
		_Elems = new _Ty[_Sz];
		_Size = _Sz;
	}

	// initializer_list ����� ������
	template<typename _Ty, size_t _Sz>
	ArrayList<_Ty, _Sz>::ArrayList(std::initializer_list<_Ty> _Init)
	{
		_Elems = new _Ty[_Sz];

		int idx = 0;
		for (auto it = _Init.begin(); it != _Init.end(); ++it)
		{
			_Elems[idx] = *it;
			idx++;
		}
		_Size = _Sz;
	}

	template<typename _Ty, size_t _Sz>
	ArrayList<_Ty, _Sz>::~ArrayList()
	{
		delete[] _Elems;
	}

	template<typename _Ty, size_t _Sz>
	bool ArrayList<_Ty, _Sz>::is_empty() const
	{
		return (_Sz > 0);
	}

	template<typename _Ty, size_t _Sz>
	size_t ArrayList<_Ty, _Sz>::size() const
	{
		return _Size;
	}

	template<typename _Ty, size_t _Sz>
	_Ty * ArrayList<_Ty, _Sz>::data()
	{
		return _Elems;
	}

	template<typename _Ty, size_t _Sz>
	_Ty & ArrayList<_Ty, _Sz>::at(size_t _Pos)
	{
		// pos�� �߸��Ǿ��ٸ� ����� ����.
		if (_Pos >= _Size)
			_DEBUG_ERROR("Invalid Array Position");

		return _Elems[_Pos];
	}

	template<typename _Ty, size_t _Sz>
	ArrayListIterator<_Ty> ArrayList<_Ty, _Sz>::begin()
	{
		return ArrayListIterator<_Ty>(&_Elems[0]);
	}

	template<typename _Ty, size_t _Sz>
	ArrayListIterator<_Ty> ArrayList<_Ty, _Sz>::end()
	{
		return ArrayListIterator<_Ty>(&_Elems[_Sz]);
	}

	template<typename _Ty, size_t _Sz>
	ArrayList<_Ty, _Sz>& ArrayList<_Ty, _Sz>::operator=(ArrayList<_Ty, _Sz>& _Rhs)
	{
		// ����� �߸��Ǿ��ٸ� ������ ����.
		if (_Size != _Rhs._Size)
			static_assert("[ERROR] ArrayList::operator= Invalid Size!");

		for (int i = 0; i < _Size; i++)
			_Elems[i] = std::move(_Rhs._Elems[i]);

		return this;
	}

	template<typename _Ty, size_t _Sz>
	ArrayList<_Ty, _Sz>& ArrayList<_Ty, _Sz>::operator=(std::initializer_list<_Ty> _Init)
	{
		// ����� �߸��Ǿ��ٸ� ������ ����.
		if (_Size != _Rhs.size())
			static_assert("[ERROR] ArrayList::operator= Invalid Size!");

		int idx = 0;
		for (auto it = _Init.begin(); it != _Init.end(); ++it)
		{
			_Elems[idx] = *it;
			idx++;
		}

		return this;
	}
}

#endif _ARRAY_LIST_H