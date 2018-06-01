#pragma once

#ifndef _AUTHOR_TYPE_H
#define _AUTHOR_TYPE_H

#include<iostream>
#include<string>

using namespace std;


/**
*	using.
*/


/**
*	학술대회 class (author)
*/
class AuthorType
{

public:
	/**
	*	기본 생성자.
	*/
	AuthorType();

	/**
	*	const char* 버전 생성자.
	*/
	AuthorType(const char* _name);


	/**
	*	const char* 버전 생성자.
	*/
	AuthorType(string _name);

	/**
	*	소멸자.
	*/
	~AuthorType() {}

	/**
	*	@brief	저자 이름을 가져온다.
	*	@pre	저자 이름이 설정되어야 한다.
	*	@post	없음.
	*	@return	저자 이름.
	*/
	string get_name() { return m_Name; }

	/**
	*	@brief	저자 이름을 설정한다.
	*	@pre	없음.
	*	@post	저자 이름이 설정된다.
	*	@param	_name	저자 이름.
	*/
	void set_name(string _name) { m_Name = _name; }

	/**
	*	@brief	저자 이름을 키보드 입력을 통해 설정한다.
	*	@pre	없음.
	*	@post	저자 이름이 설정된다.
	*/
	void set_name_kb();

	/**
	*	@brief	저자 이름을 화면에 출력한다.
	*	@pre	저자 이름이 설정되어야 한다.
	*	@post	저자 이름이 화면에 출력된다.
	*/
	void display_name();

	/**
	*	@brief	item id를 통해 두 아이템을 비교한다.
	*	@pre	두 아이템 타입이 초기화되어야 한다.
	*	@param	lhs	비교를 위한 아이템 1.
	*			rhs	비교를 위한 아이템 2.
	*	@return	lhs가 크다면 true.
	*/
	friend bool operator >(const AuthorType& lhs, const AuthorType& rhs);

	/**
	*	@brief	item id를 통해 두 아이템을 비교한다.
	*	@pre	두 아이템 타입이 초기화되어야 한다.
	*	@param	lhs	비교를 위한 아이템 1.
	*			rhs	비교를 위한 아이템 2.
	*	@return	lhs가 작다면 true.
	*/
	friend bool operator <(const AuthorType& lhs, const AuthorType& rhs);

	/**
	*	@brief	item id를 통해 두 아이템을 비교한다.
	*	@pre	두 아이템 타입이 초기화되어야 한다.
	*	@param	lhs	비교를 위한 아이템 1.
	*			rhs	비교를 위한 아이템 2.
	*	@return	둘이 같다면 true.
	*/
	friend bool operator ==(const AuthorType& lhs, const AuthorType& rhs);

	/**
	*	@brief	item id를 통해 두 아이템을 비교한다.
	*	@pre	두 아이템 타입이 초기화되어야 한다.
	*	@param	lhs	비교를 위한 아이템 1.
	*			rhs	비교를 위한 아이템 2.
	*	@return	둘이 같다면 true.
	*/
	friend bool operator !=(const AuthorType& lhs, const AuthorType& rhs);

protected:
	string m_Name;

};

#endif _AUTHOR_TYPE_H