#pragma once

#ifndef _PAPER_TYPE_H
#define _PAPER_TYPE_H

#include<initializer_list>
#include<iostream>
#include<string>

#include"LinkedListIterator.h"
#include"ArrayListIterator.h"
#include"LinkedList.h"
#include"ArrayList.h"
#include"AuthorType.h"

using namespace std;

/**
*	�� class (paper)
*/
class PaperType
{

public:
	/**
	*	�⺻ ������.
	*/
	PaperType();

	/**
	*	���� ������.
	*/
	PaperType(PaperType& paper);

	/**
	*	�Ҹ���.
	*/
	~PaperType();

	/**
	*	@brief	�� ������ �����´�.
	*	@pre	�� ������ �����Ǿ�� �Ѵ�.
	*	@post	����.
	*	@return	�� ����.
	*/
	string get_title() { return m_Title; }

	/**
	*	@brief	�� ���� ����Ʈ�� �����´�.
	*	@pre	�� ���� ����Ʈ�� �����Ǿ�� �Ѵ�.
	*	@post	����.
	*	@return	�� ���� ����Ʈ.
	*/
	kmh::ArrayList<AuthorType>* get_author() { return m_Author; }

	/**
	*	@brief	�� ���� �������� �����´�.
	*	@pre	�� ���� �������� �����Ǿ�� �Ѵ�.
	*	@post	����.
	*	@return	�� ���� ������.
	*/
	int get_start_page() { return m_SPage; }

	/**
	*	@brief	�� �� �������� �����´�.
	*	@pre	�� �� �������� �����Ǿ�� �Ѵ�.
	*	@post	����.
	*	@return	�� �� ������.
	*/
	int get_end_page() { return m_EPage; }

	/**
	*	@brief	�� ������ ���� �����´�.
	*	@pre	�� ������ ���� �����Ǿ�� �Ѵ�.
	*	@post	����.
	*	@return	�� ������ ��.
	*/
	int get_pages() { return m_Page; }

	/**
	*	@brief	�� ������ �����Ѵ�.
	*	@pre	����.
	*	@post	�� ������ �����ȴ�.
	*	@param	title	�� ����.
	*/
	void set_title(string title);

	/**
	*	@brief	���ڸ� �����Ѵ�.
	*	@pre	����.
	*	@post	���ڸ� �����ȴ�.
	*	@param	author	���� �̸��� ��� ArrayList.
	*/
	void set_author(kmh::ArrayList<AuthorType>& author);

	/**
	*	@brief	���ڸ� �����Ѵ�.
	*	@pre	����.
	*	@post	���ڸ� �����ȴ�.
	*	@param	init	���� �̸��� ��� initializer_list.
	*/
	void set_author(initializer_list<string> init);

	/**
	*	@brief	�� �������� �����Ѵ�.
	*	@pre	����.
	*	@post	�� �������� �����ȴ�.
	*	@param	page	�� ������ ������ ��� ���ڿ�.
	*/
	void set_page(string page);

	/**
	*	@brief	�� ���� �����Ѵ�.
	*	@pre	����.
	*	@post	�� ���� �����ȴ�.
	*/
	void set_title_kb();

	/**
	*	@brief	�� ���ڸ� �����Ѵ�.
	*	@pre	����.
	*	@post	�� ���ڰ� �����ȴ�.
	*/
	void set_author_kb();

	/**
	*	@brief	�� �������� �����Ѵ�.
	*	@pre	����.
	*	@post	�� �������� �����ȴ�.
	*/
	void set_page_kb();

	/**
	*	@brief	�� ������ ����Ѵ�.
	*	@pre	����.
	*	@post	�� ������ ��µȴ�.
	*/
	void display_title();

	/**
	*	@brief	�� ���ڸ� ����Ѵ�.
	*	@pre	����.
	*	@post	�� ���ڰ� ��µȴ�.
	*/
	void display_author();

	/**
	*	@brief	�� �������� ����Ѵ�.
	*	@pre	����.
	*	@post	�� �������� ��µȴ�.
	*/
	void display_page();

	/**
	*	@brief	�� �����͸� ��� ����Ѵ�.
	*	@pre	����.
	*	@post	�� �����͸� ��� ��µȴ�.
	*/
	void display_record();

	/**
	*	@brief	item id�� ���� �� �������� ���Ѵ�.
	*	@pre	�� ������ Ÿ���� �ʱ�ȭ�Ǿ�� �Ѵ�.
	*	@param	lhs	�񱳸� ���� ������ 1.
	*			rhs	�񱳸� ���� ������ 2.
	*	@return	lhs�� ũ�ٸ� true.
	*/
	friend bool operator >(const PaperType& lhs, const PaperType& rhs);

	/**
	*	@brief	item id�� ���� �� �������� ���Ѵ�.
	*	@pre	�� ������ Ÿ���� �ʱ�ȭ�Ǿ�� �Ѵ�.
	*	@param	lhs	�񱳸� ���� ������ 1.
	*			rhs	�񱳸� ���� ������ 2.
	*	@return	lhs�� ũ�ٸ� true.
	*/
	friend bool operator <(const PaperType& lhs, const PaperType& rhs);

	/**
	*	@brief	item id�� ���� �� �������� ���Ѵ�.
	*	@pre	�� ������ Ÿ���� �ʱ�ȭ�Ǿ�� �Ѵ�.
	*	@param	lhs	�񱳸� ���� ������ 1.
	*			rhs	�񱳸� ���� ������ 2.
	*	@return	lhs�� ũ�ٸ� true.
	*/
	friend bool operator ==(const PaperType& lhs, const PaperType& rhs);


	/**
	*	@brief	item id�� ���� �� �������� ���Ѵ�.
	*	@pre	�� ������ Ÿ���� �ʱ�ȭ�Ǿ�� �Ѵ�.
	*	@param	lhs	�񱳸� ���� ������ 1.
	*			rhs	�񱳸� ���� ������ 2.
	*	@return	lhs�� ũ�ٸ� true.
	*/
	friend bool operator !=(const PaperType& lhs, const PaperType& rhs);

protected:
	string m_Title;		///< �� ����.
	kmh::ArrayList<AuthorType>* m_Author;	///< �� ���� ����Ʈ.
	int m_SPage;	///< ���� ������.
	int m_EPage;	///< �� ������.
	int m_Page;		///< ������ ��.

};

#endif _PAPER_TYPE_H