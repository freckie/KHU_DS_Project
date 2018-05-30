#pragma once

#ifndef _ARRAY_LIST_H
#define _ARRAY_LIST_H

#include "ArrayListIterator.h"

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
	*	ArrayList
	*/
	template <typename _Ty, size_t _Sz>
	class ArrayList
	{

		friend class ArrayListIterator<_Ty>;

	public:
		/**
		*	기본 생성자.
		*/
		ArrayList();

		/**
		*	initializer_list 사용한 생성자.
		*/
		ArrayList(std::initializer_list<_Ty> _Init);

		/**
		*	소멸자.
		*/
		~ArrayList();

		/**
		*	@brief	Array가 비었는지 확인한다.
		*	@pre	없음.
		*	@post	없음.
		*	@return	비었으면 true, 아니라면 false.
		*/
		bool is_empty() const;

		/**
		*	@brief	Array의 사이즈를 반환한다.
		*	@pre	없음.
		*	@post	없음.
		*	@return	현재 사이즈.
		*/
		size_t size() const;

		/**
		*	@brief	현재 Array의 내부 배열을 가져온다.
		*	@pre	array가 초기화되어야 한다.
		*	@post	없음.
		*	@return	내부 배열의 주소값.
		*/
		_Ty* data();

		/**
		*	@brief	Array의 해당 index값을 가져온다.
		*	@pre	array가 초기화되어야 한다.
		*	@post	없음.
		*	@param	_Pos	index.
		*	@return	해당 index의 데이터.
		*/
		_Ty& at(size_t _Pos);

		/**
		*	@brief	Array의 맨 앞의 데이터를 Iterator에 담아 반환한다.
		*	@pre	array가 초기화되어야 한다.
		*	@post	없음.
		*	@return	맨 앞의 Iterator.
		*/
		ArrayListIterator<_Ty> begin();

		/**
		*	@brief	Array의 맨 뒤의 데이터를 Iterator에 담아 반환한다.
		*	@pre	array가 초기화되어야 한다.
		*	@post	없음.
		*	@return	맨 뒤의 Iterator.
		*/
		ArrayListIterator<_Ty> end();

		/**
		*	@brief	Array 대입 연산자.
		*	@pre	파라미터가 초기화 되어야 한다.
		*	@post	없음.
		*	@param	_Rhs	파라미터 Array.
		*	@return	this.
		*/
		ArrayList<_Ty, _Sz>& operator=(ArrayList<_Ty, _Sz>& _Rhs);

		/**
		*	@brief	Array 대입 연산자.
		*	@pre	파라미터가 초기화 되어야 한다.
		*	@post	없음.
		*	@param	_Rhs	파라미터 initializer_list.
		*	@return	this.
		*/
		ArrayList<_Ty, _Sz>& operator=(std::initializer_list<_Ty> _Init);

	private:
		_Ty * _Elems;
		size_t _Size;
	};

	// 기본 생성자
	template<typename _Ty, size_t _Sz>
	ArrayList<_Ty, _Sz>::ArrayList()
	{
		// 사이즈가 잘못되었으면 컴파일 에러.
		static_assert(!(_Sz <= 0), "Wrong ArrayList Size.");
		_Elems = new _Ty[_Sz];
		_Size = _Sz;
	}

	// initializer_list 사용한 생성자
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
		// pos가 잘못되었다면 디버그 에러.
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
		// 사이즈가 잘못되었다면 컴파일 에러.
		if (_Size != _Rhs._Size)
			static_assert("[ERROR] ArrayList::operator= Invalid Size!");

		for (int i = 0; i < _Size; i++)
			_Elems[i] = std::move(_Rhs._Elems[i]);

		return this;
	}

	template<typename _Ty, size_t _Sz>
	ArrayList<_Ty, _Sz>& ArrayList<_Ty, _Sz>::operator=(std::initializer_list<_Ty> _Init)
	{
		// 사이즈가 잘못되었다면 컴파일 에러.
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