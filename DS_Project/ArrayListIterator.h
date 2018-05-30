#pragma once

#ifndef _ARRAY_LIST_ITERATOR_H
#define _ARRAY_LIST_ITERATOR_H

#include"ArrayList.h"

#include<initializer_list>

namespace kmh
{
	/**
	*	전방선언.
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
		*	기본 생성자.
		*/
		ArrayListIterator() : _Val(nullptr) {}

		/**
		*	생성자.
		*/
		ArrayListIterator(_Ty* val) : _Val(val) {}

		/**
		*	생성자.
		*/
		ArrayListIterator(_Ty val) : _Val(&val) {}

		/**
		*	소멸자.
		*/
		~ArrayListIterator() {}

		/**
		*	@brief	val을 참조한다.
		*	@pre	val이 존재해야 한다.
		*	@return	val.
		*/
		_Ty& operator*();

		/**
		*	@brief	val을 참조한다.
		*	@pre	val이 존재해야 한다.
		*	@return	val의 주소.
		*/
		_Ty& operator->() const;

		/**
		*	@brief	iterator를 이동한다
		*	@pre	없음.
		*	@param	_Idx	iterator을 이동할 거리.
		*	@return	이동한 iterator.
		*/
		ArrayListIterator<_Ty> operator+(int _Idx);

		/**
		*	@brief	iterator를 이동한다
		*	@pre	없음.
		*	@param	_Idx	iterator을 이동할 거리.
		*	@return	이동한 iterator.
		*/
		ArrayListIterator<_Ty> operator-(int _Idx);

		/**
		*	@brief	현재 Iterator에서 다음 Iterator를 가져온다. (전위 연산)
		*	@pre	없음.
		*	@return	다음 iterator.
		*/
		ArrayListIterator<_Ty> operator++();

		/**
		*	@brief	현재 Iterator에서 다음 Iterator를 가져온다. (후위 연산)
		*	@pre	없음.
		*	@return	다음 iterator.
		*/
		ArrayListIterator<_Ty> operator++(int);

		/**
		*	@brief	현재 Iterator에서 이전 Iterator를 가져온다. (전위 연산)
		*	@pre	없음.
		*	@return	이전 iterator.
		*/
		ArrayListIterator<_Ty> operator--();

		/**
		*	@brief	현재 Iterator에서 이전 Iterator를 가져온다. (후위 연산)
		*	@pre	없음.
		*	@return	이전 iterator.
		*/
		ArrayListIterator<_Ty> operator--(int);

		/**
		*	@brief	Iterator가 서로 같은지 확인한다.
		*	@pre	없음.
		*	@param	_Rhs	확인할 대상.
		*	@return	같다면 true, 아니라면 false.
		*/
		bool operator==(const ArrayListIterator<_Ty>& _Rhs);

		/**
		*	@brief	Iterator가 서로 같은지 확인한다.
		*	@pre	없음.
		*	@param	_Rhs	확인할 대상.
		*	@return	같다면 true, 아니라면 false.
		*/
		bool operator!=(const ArrayListIterator<_Ty>& _Rhs);

	private:
		_Ty * _Val;

	};

	// 함수 구현들.
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