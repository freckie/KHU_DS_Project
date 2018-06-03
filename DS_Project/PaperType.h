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
*	논문 class (paper)
*/
class PaperType
{

public:
	/**
	*	기본 생성자.
	*/
	PaperType();

	/**
	*	복사 생성자.
	*/
	PaperType(PaperType& paper);

	/**
	*	소멸자.
	*/
	~PaperType();

	/**
	*	@brief	논문 제목을 가져온다.
	*	@pre	논문 제목이 설정되어야 한다.
	*	@post	없음.
	*	@return	논문 제목.
	*/
	string get_title() { return m_Title; }

	/**
	*	@brief	논문 저자 리스트를 가져온다.
	*	@pre	논문 저자 리스트가 설정되어야 한다.
	*	@post	없음.
	*	@return	논문 저자 리스트.
	*/
	kmh::ArrayList<AuthorType>* get_author() { return m_Author; }

	/**
	*	@brief	논문 시작 페이지를 가져온다.
	*	@pre	논문 시작 페이지가 설정되어야 한다.
	*	@post	없음.
	*	@return	논문 시작 페이지.
	*/
	int get_start_page() { return m_SPage; }

	/**
	*	@brief	논문 끝 페이지를 가져온다.
	*	@pre	논문 끝 페이지가 설정되어야 한다.
	*	@post	없음.
	*	@return	논문 끝 페이지.
	*/
	int get_end_page() { return m_EPage; }

	/**
	*	@brief	논문 페이지 수를 가져온다.
	*	@pre	논문 페이지 수가 설정되어야 한다.
	*	@post	없음.
	*	@return	논문 페이지 수.
	*/
	int get_pages() { return m_Page; }

	/**
	*	@brief	논문 제목을 설정한다.
	*	@pre	없음.
	*	@post	논문 제목이 설정된다.
	*	@param	title	논문 제목.
	*/
	void set_title(string title);

	/**
	*	@brief	저자를 설정한다.
	*	@pre	없음.
	*	@post	저자를 설정된다.
	*	@param	author	저자 이름이 담긴 ArrayList.
	*/
	void set_author(kmh::ArrayList<AuthorType>& author);

	/**
	*	@brief	저자를 설정한다.
	*	@pre	없음.
	*	@post	저자를 설정된다.
	*	@param	init	저자 이름이 담긴 initializer_list.
	*/
	void set_author(initializer_list<string> init);

	/**
	*	@brief	논문 페이지를 설정한다.
	*	@pre	없음.
	*	@post	논문 페이지가 설정된다.
	*	@param	page	논문 페이지 정보가 담긴 문자열.
	*/
	void set_page(string page);

	/**
	*	@brief	논문 제목를 설정한다.
	*	@pre	없음.
	*	@post	논문 제목가 설정된다.
	*/
	void set_title_kb();

	/**
	*	@brief	논문 저자를 설정한다.
	*	@pre	없음.
	*	@post	논문 저자가 설정된다.
	*/
	void set_author_kb();

	/**
	*	@brief	논문 페이지를 설정한다.
	*	@pre	없음.
	*	@post	논문 페이지가 설정된다.
	*/
	void set_page_kb();

	/**
	*	@brief	논문 제목을 출력한다.
	*	@pre	없음.
	*	@post	논문 제목이 출력된다.
	*/
	void display_title();

	/**
	*	@brief	논문 저자를 출력한다.
	*	@pre	없음.
	*	@post	논문 저자가 출력된다.
	*/
	void display_author();

	/**
	*	@brief	논문 페이지를 출력한다.
	*	@pre	없음.
	*	@post	논문 페이지가 출력된다.
	*/
	void display_page();

	/**
	*	@brief	논문 데이터를 모두 출력한다.
	*	@pre	없음.
	*	@post	논문 데이터를 모두 출력된다.
	*/
	void display_record();

	/**
	*	@brief	item id를 통해 두 아이템을 비교한다.
	*	@pre	두 아이템 타입이 초기화되어야 한다.
	*	@param	lhs	비교를 위한 아이템 1.
	*			rhs	비교를 위한 아이템 2.
	*	@return	lhs가 크다면 true.
	*/
	friend bool operator >(const PaperType& lhs, const PaperType& rhs);

	/**
	*	@brief	item id를 통해 두 아이템을 비교한다.
	*	@pre	두 아이템 타입이 초기화되어야 한다.
	*	@param	lhs	비교를 위한 아이템 1.
	*			rhs	비교를 위한 아이템 2.
	*	@return	lhs가 크다면 true.
	*/
	friend bool operator <(const PaperType& lhs, const PaperType& rhs);

	/**
	*	@brief	item id를 통해 두 아이템을 비교한다.
	*	@pre	두 아이템 타입이 초기화되어야 한다.
	*	@param	lhs	비교를 위한 아이템 1.
	*			rhs	비교를 위한 아이템 2.
	*	@return	lhs가 크다면 true.
	*/
	friend bool operator ==(const PaperType& lhs, const PaperType& rhs);


	/**
	*	@brief	item id를 통해 두 아이템을 비교한다.
	*	@pre	두 아이템 타입이 초기화되어야 한다.
	*	@param	lhs	비교를 위한 아이템 1.
	*			rhs	비교를 위한 아이템 2.
	*	@return	lhs가 크다면 true.
	*/
	friend bool operator !=(const PaperType& lhs, const PaperType& rhs);

protected:
	string m_Title;		///< 논문 제목.
	kmh::ArrayList<AuthorType>* m_Author;	///< 논문 저자 리스트.
	int m_SPage;	///< 시작 페이지.
	int m_EPage;	///< 끝 페이지.
	int m_Page;		///< 페이지 수.

};

#endif _PAPER_TYPE_H