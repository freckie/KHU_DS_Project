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

	template <typename _Ty>
	class ArrayList;


	/**
	*	using.
	*/
	template <typename _Ty>
	using Array = ArrayList<_Ty>;
	template <typename _Ty>
	using AIterator = ArrayListIterator<_Ty>;


	/**
	*	ArrayList
	*/
	template <typename _Ty>
	class ArrayList
	{

		friend class ArrayListIterator<_Ty>;

	public:
		/**
		*	�⺻ ������.
		*/
		ArrayList();

		/**
		*	���� ������.
		*/
		ArrayList(ArrayList<_Ty>& _Rhs);

		/**
		*	����� ������ ������.
		*/
		ArrayList(int size);

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
		*	@brief	���� Array�� �ʱ�ȭ�ϰ�, ���ο� ������� ���Ҵ��Ѵ�.
		*	@pre	����.
		*	@post	����.
		*	@param	_Sz	���Ӱ� �Ҵ��� ������.
		*/
		void realloc(size_t _Sz);

		/**
		*	@brief	���� array�� �ʱ�ȭ�ϰ�, �Ķ������ ���� �����Ѵ�.
		*	@pre	����.
		*	@post	����.
		*	@param	_Rhs	������ �Ķ���� Array.
		*/
		void remake(ArrayList<_Ty>& _Rhs);

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
		ArrayList<_Ty>& operator=(ArrayList<_Ty>& _Rhs);

		/**
		*	@brief	Array ���� ������.
		*	@pre	�Ķ���Ͱ� �ʱ�ȭ �Ǿ�� �Ѵ�.
		*	@post	����.
		*	@param	_Rhs	�Ķ���� initializer_list.
		*	@return	this.
		*/
		ArrayList<_Ty>& operator=(std::initializer_list<_Ty> _Init);

	private:
		_Ty * _Elems;
		size_t _Size;
	};

	// �⺻ ������
	template<typename _Ty>
	ArrayList<_Ty>::ArrayList()
	{
		_Size = 5;
		_Elems = new _Ty[_Size];
	}

	template<typename _Ty>
	ArrayList<_Ty>::ArrayList(ArrayList<_Ty>& _Rhs)
	{
		_Size = _Rhs._Size;
		_Elems = new _Ty[_Size];

		for (size_t i = 0; i < _Size; i++)
			_Elems[i] = _Rhs._Elems[i];
	}

	template<typename _Ty>
	ArrayList<_Ty>::ArrayList(int size)
	{
		_Size = size;
		_Elems = new _Ty[_Size];
	}

	// initializer_list ����� ������
	template<typename _Ty>
	ArrayList<_Ty>::ArrayList(std::initializer_list<_Ty> _Init)
	{
		_Size = _Init.size();
		_Elems = new _Ty[_Size];

		int idx = 0;
		for (auto it = _Init.begin(); it != _Init.end(); ++it)
		{
			_Elems[idx] = *it;
			idx++;
		}
	}

	template<typename _Ty>
	ArrayList<_Ty>::~ArrayList()
	{
		delete[] _Elems;
	}

	template<typename _Ty>
	bool ArrayList<_Ty>::is_empty() const
	{
		return (_Sz > 0);
	}

	template<typename _Ty>
	size_t ArrayList<_Ty>::size() const
	{
		return _Size;
	}

	template<typename _Ty>
	_Ty * ArrayList<_Ty>::data()
	{
		return _Elems;
	}

	template<typename _Ty>
	void ArrayList<_Ty>::realloc(size_t _Sz)
	{
		// ���� Array ����.
		delete[] _Elems;

		// ���� �Ҵ�.
		_Size = _Sz;
		_Elems = new _Ty[_Sz];
	}

	template<typename _Ty>
	void ArrayList<_Ty>::remake(ArrayList<_Ty>& _Rhs)
	{
		realloc(_Rhs._Size);

		// ����
		for (int i = 0; i < _Size; i++)
			_Elems[i] = _Rhs._Elems[i];
	}

	template<typename _Ty>
	_Ty & ArrayList<_Ty>::at(size_t _Pos)
	{
		// pos�� �߸��Ǿ��ٸ� ����� ����.
		if (_Pos >= _Size)
			_DEBUG_ERROR("Invalid Array Position");

		return _Elems[_Pos];
	}

	template<typename _Ty>
	ArrayListIterator<_Ty> ArrayList<_Ty>::begin()
	{
		return ArrayListIterator<_Ty>(&_Elems[0]);
	}

	template<typename _Ty>
	ArrayListIterator<_Ty> ArrayList<_Ty>::end()
	{
		return ArrayListIterator<_Ty>(&_Elems[_Size]);
	}

	template<typename _Ty>
	ArrayList<_Ty>& ArrayList<_Ty>::operator=(ArrayList<_Ty>& _Rhs)
	{
		// ����� �߸��Ǿ��ٸ� ������ ����.
		if (_Size != _Rhs._Size)
			static_assert("[ERROR] ArrayList::operator= Invalid Size!");

		for (int i = 0; i < _Size; i++)
			_Elems[i] = std::move(_Rhs._Elems[i]);

		return this;
	}

	template<typename _Ty>
	ArrayList<_Ty>& ArrayList<_Ty>::operator=(std::initializer_list<_Ty> _Init)
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