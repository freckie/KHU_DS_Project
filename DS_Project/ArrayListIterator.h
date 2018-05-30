#pragma once

#ifndef _ARRAY_LIST_ITERATOR_H
#define _ARRAY_LIST_ITERATOR_H

#include"ArrayList.h"

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
	*	Iterator for ArrayList.
	*/
	template <typename _Ty>
	class ArrayListIterator
	{

	public:

		/**
		*	�⺻ ������.
		*/
		ArrayListIterator() : _Val(nullptr) {}

		/**
		*	������.
		*/
		ArrayListIterator(_Ty* val) : _Val(val) {}

		/**
		*	������.
		*/
		ArrayListIterator(_Ty val) : _Val(&val) {}

		/**
		*	�Ҹ���.
		*/
		~ArrayListIterator() {}

		/**
		*	@brief	val�� �����Ѵ�.
		*	@pre	val�� �����ؾ� �Ѵ�.
		*	@return	val.
		*/
		_Ty& operator*();

		/**
		*	@brief	val�� �����Ѵ�.
		*	@pre	val�� �����ؾ� �Ѵ�.
		*	@return	val�� �ּ�.
		*/
		_Ty& operator->() const;

		/**
		*	@brief	iterator�� �̵��Ѵ�
		*	@pre	����.
		*	@param	_Idx	iterator�� �̵��� �Ÿ�.
		*	@return	�̵��� iterator.
		*/
		ArrayListIterator<_Ty> operator+(int _Idx);

		/**
		*	@brief	iterator�� �̵��Ѵ�
		*	@pre	����.
		*	@param	_Idx	iterator�� �̵��� �Ÿ�.
		*	@return	�̵��� iterator.
		*/
		ArrayListIterator<_Ty> operator-(int _Idx);

		/**
		*	@brief	���� Iterator���� ���� Iterator�� �����´�. (���� ����)
		*	@pre	����.
		*	@return	���� iterator.
		*/
		ArrayListIterator<_Ty> operator++();

		/**
		*	@brief	���� Iterator���� ���� Iterator�� �����´�. (���� ����)
		*	@pre	����.
		*	@return	���� iterator.
		*/
		ArrayListIterator<_Ty> operator++(int);

		/**
		*	@brief	���� Iterator���� ���� Iterator�� �����´�. (���� ����)
		*	@pre	����.
		*	@return	���� iterator.
		*/
		ArrayListIterator<_Ty> operator--();

		/**
		*	@brief	���� Iterator���� ���� Iterator�� �����´�. (���� ����)
		*	@pre	����.
		*	@return	���� iterator.
		*/
		ArrayListIterator<_Ty> operator--(int);

		/**
		*	@brief	Iterator�� ���� ������ Ȯ���Ѵ�.
		*	@pre	����.
		*	@param	_Rhs	Ȯ���� ���.
		*	@return	���ٸ� true, �ƴ϶�� false.
		*/
		bool operator==(const ArrayListIterator<_Ty>& _Rhs);

		/**
		*	@brief	Iterator�� ���� ������ Ȯ���Ѵ�.
		*	@pre	����.
		*	@param	_Rhs	Ȯ���� ���.
		*	@return	���ٸ� true, �ƴ϶�� false.
		*/
		bool operator!=(const ArrayListIterator<_Ty>& _Rhs);

	private:
		_Ty * _Val;

	};

	// �Լ� ������.
	template<typename _Ty>
	_Ty & ArrayListIterator<_Ty>::operator*()
	{
		return *_Val;
	}

	template<typename _Ty>
	_Ty & ArrayListIterator<_Ty>::operator->() const
	{
		return _Val;
	}

	template<typename _Ty>
	ArrayListIterator<_Ty> ArrayListIterator<_Ty>::operator+(int _Idx)
	{
		_Val += _Idx;
		return *this;
	}

	template<typename _Ty>
	ArrayListIterator<_Ty> ArrayListIterator<_Ty>::operator-(int _Idx)
	{
		_Val -= _Idx;
		return *this;
	}

	template<typename _Ty>
	ArrayListIterator<_Ty> ArrayListIterator<_Ty>::operator++()
	{
		++_Val;
		return *this;
	}

	template<typename _Ty>
	ArrayListIterator<_Ty> ArrayListIterator<_Ty>::operator++(int)
	{
		ArrayListIterator<_Ty> temp(++_Val);
		return temp;
	}

	template<typename _Ty>
	ArrayListIterator<_Ty> ArrayListIterator<_Ty>::operator--()
	{
		--_Val;
		return *this;
	}

	template<typename _Ty>
	ArrayListIterator<_Ty> ArrayListIterator<_Ty>::operator--(int)
	{
		ArrayListIterator<_Ty> temp(--_Val);
		return temp;
	}

	template<typename _Ty>
	bool ArrayListIterator<_Ty>::operator==(const ArrayListIterator<_Ty>& _Rhs)
	{
		return (this->_Val == _Rhs._Val);
	}

	template<typename _Ty>
	bool ArrayListIterator<_Ty>::operator!=(const ArrayListIterator<_Ty>& _Rhs)
	{
		return (this->_Val != _Rhs._Val);
	}

}

#endif _ARRAY_LIST_ITERATOR_H