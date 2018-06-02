#pragma once

#ifndef _CONFERENCE_TYPE_H
#define _CONFERENCE_TYPE_H

#include<iostream>
#include<string>

#include"LinkedListIterator.h"
#include"LinkedList.h"
#include"PaperType.h"

using namespace std;

/**
*	전방 선언.
*/
class PaperType;

/**
*	학술대회 class (conference)
*/
class ConferenceType
{

public:
	/**
	*	기본 생성자.
	*/
	ConferenceType();

	/**
	*	소멸자.
	*/
	~ConferenceType();

	/**
	*	@brief	논문 제목을 가져온다.
	*	@pre	논문 제목이 설정되어야 한다.
	*	@post	없음.
	*	@return	논문 제목.
	*/
	string get_title() { return m_Title; }

	/**
	*	@brief	논문 날짜를 가져온다.
	*	@pre	논문 날짜가 설정되어야 한다.
	*	@post	없음.
	*	@return	논문 날짜.
	*/
	string get_date() { return m_Date; }

	/**
	*	@brief	논문 날짜(연도)를 가져온다.
	*	@pre	논문 날짜가 설정되어야 한다.
	*	@post	없음.
	*	@return	논문 날짜(연도).
	*/
	int get_ydate() { return m_YDate; }

	/**
	*	@brief	논문 날짜(월)를 가져온다.
	*	@pre	논문 날짜가 설정되어야 한다.
	*	@post	없음.
	*	@return	논문 날짜(월).
	*/
	int get_mdate() { return m_MDate; }

	/**
	*	@brief	논문 날짜(일)를 가져온다.
	*	@pre	논문 날짜가 설정되어야 한다.
	*	@post	없음.
	*	@return	논문 날짜(일).
	*/
	int get_ddate() { return m_DDate; }

	/**
	*	@brief	논문 리스트 포인터를 가져온다.
	*	@pre	없음.
	*	@post	없음.
	*	@return	논문 리스트 포인터.
	*/
	kmh::List<PaperType*>* get_papers() { return m_Papers; }
	
	/**
	*	@brief	논문 제목을 설정한다.
	*	@pre	없음.
	*	@post	없음.
	*	@param	title	논문 제목.
	*/
	void set_title(string title) { m_Title = title; }

	/**
	*	@brief	논문 개최 날짜를 설정한다.
	*	@pre	없음.
	*	@post	없음.
	*	@param	date	논문 개최 날짜.
	*/
	void set_date(string date);

	/**
	*	@brief	논문을 추가한다.
	*	@pre	없음.
	*	@post	없음.
	*	@param	paper	논문 포인터.
	*/
	void add_paper(PaperType* paper);

	void display_title();
	void display_date();
	void display_papers();
	void display_record();

	kmh::LIterator<PaperType*> find_paper(string paper_title);
	kmh::LIterator<PaperType*> find_paper(PaperType& paper);
	void search_paper(string keyword);
	
	friend bool operator > (const ConferenceType& lhs, const ConferenceType& rhs);
	friend bool operator < (const ConferenceType& lhs, const ConferenceType& rhs);
	friend bool operator == (const ConferenceType& lhs, const ConferenceType& rhs);
	friend bool operator != (const ConferenceType& lhs, const ConferenceType& rhs);

private:
	string m_Title;	///< 학술대회 제목.
	string m_Date;	///< 개최 날짜.
	int m_YDate;	///< 개최 날짜 (연도).
	int m_MDate;	///< 개최 날짜 (월).
	int m_DDate;	///< 개최 날짜 (일).
	kmh::List<PaperType*>* m_Papers;	///< 논문 포인터 저장 리스트.

};

#endif _CONFERENCE_TYPE_H