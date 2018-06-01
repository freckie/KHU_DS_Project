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
*	�м���ȸ class (author)
*/
class AuthorType
{

public:
	/**
	*	�⺻ ������.
	*/
	AuthorType();

	/**
	*	const char* ���� ������.
	*/
	AuthorType(const char* _name);


	/**
	*	const char* ���� ������.
	*/
	AuthorType(string _name);

	/**
	*	�Ҹ���.
	*/
	~AuthorType() {}

	/**
	*	@brief	���� �̸��� �����´�.
	*	@pre	���� �̸��� �����Ǿ�� �Ѵ�.
	*	@post	����.
	*	@return	���� �̸�.
	*/
	string get_name() { return m_Name; }

	/**
	*	@brief	���� �̸��� �����Ѵ�.
	*	@pre	����.
	*	@post	���� �̸��� �����ȴ�.
	*	@param	_name	���� �̸�.
	*/
	void set_name(string _name) { m_Name = _name; }

	/**
	*	@brief	���� �̸��� Ű���� �Է��� ���� �����Ѵ�.
	*	@pre	����.
	*	@post	���� �̸��� �����ȴ�.
	*/
	void set_name_kb();

	/**
	*	@brief	���� �̸��� ȭ�鿡 ����Ѵ�.
	*	@pre	���� �̸��� �����Ǿ�� �Ѵ�.
	*	@post	���� �̸��� ȭ�鿡 ��µȴ�.
	*/
	void display_name();

	/**
	*	@brief	item id�� ���� �� �������� ���Ѵ�.
	*	@pre	�� ������ Ÿ���� �ʱ�ȭ�Ǿ�� �Ѵ�.
	*	@param	lhs	�񱳸� ���� ������ 1.
	*			rhs	�񱳸� ���� ������ 2.
	*	@return	lhs�� ũ�ٸ� true.
	*/
	friend bool operator >(const AuthorType& lhs, const AuthorType& rhs);

	/**
	*	@brief	item id�� ���� �� �������� ���Ѵ�.
	*	@pre	�� ������ Ÿ���� �ʱ�ȭ�Ǿ�� �Ѵ�.
	*	@param	lhs	�񱳸� ���� ������ 1.
	*			rhs	�񱳸� ���� ������ 2.
	*	@return	lhs�� �۴ٸ� true.
	*/
	friend bool operator <(const AuthorType& lhs, const AuthorType& rhs);

	/**
	*	@brief	item id�� ���� �� �������� ���Ѵ�.
	*	@pre	�� ������ Ÿ���� �ʱ�ȭ�Ǿ�� �Ѵ�.
	*	@param	lhs	�񱳸� ���� ������ 1.
	*			rhs	�񱳸� ���� ������ 2.
	*	@return	���� ���ٸ� true.
	*/
	friend bool operator ==(const AuthorType& lhs, const AuthorType& rhs);

	/**
	*	@brief	item id�� ���� �� �������� ���Ѵ�.
	*	@pre	�� ������ Ÿ���� �ʱ�ȭ�Ǿ�� �Ѵ�.
	*	@param	lhs	�񱳸� ���� ������ 1.
	*			rhs	�񱳸� ���� ������ 2.
	*	@return	���� ���ٸ� true.
	*/
	friend bool operator !=(const AuthorType& lhs, const AuthorType& rhs);

protected:
	string m_Name;

};

#endif _AUTHOR_TYPE_H