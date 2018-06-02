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
*	���� ����.
*/
class PaperType;

/**
*	�м���ȸ class (conference)
*/
class ConferenceType
{

public:
	/**
	*	�⺻ ������.
	*/
	ConferenceType();

	/**
	*	�Ҹ���.
	*/
	~ConferenceType();

	/**
	*	@brief	�� ������ �����´�.
	*	@pre	�� ������ �����Ǿ�� �Ѵ�.
	*	@post	����.
	*	@return	�� ����.
	*/
	string get_title() { return m_Title; }

	/**
	*	@brief	�� ��¥�� �����´�.
	*	@pre	�� ��¥�� �����Ǿ�� �Ѵ�.
	*	@post	����.
	*	@return	�� ��¥.
	*/
	string get_date() { return m_Date; }

	/**
	*	@brief	�� ��¥(����)�� �����´�.
	*	@pre	�� ��¥�� �����Ǿ�� �Ѵ�.
	*	@post	����.
	*	@return	�� ��¥(����).
	*/
	int get_ydate() { return m_YDate; }

	/**
	*	@brief	�� ��¥(��)�� �����´�.
	*	@pre	�� ��¥�� �����Ǿ�� �Ѵ�.
	*	@post	����.
	*	@return	�� ��¥(��).
	*/
	int get_mdate() { return m_MDate; }

	/**
	*	@brief	�� ��¥(��)�� �����´�.
	*	@pre	�� ��¥�� �����Ǿ�� �Ѵ�.
	*	@post	����.
	*	@return	�� ��¥(��).
	*/
	int get_ddate() { return m_DDate; }

	/**
	*	@brief	�� ����Ʈ �����͸� �����´�.
	*	@pre	����.
	*	@post	����.
	*	@return	�� ����Ʈ ������.
	*/
	kmh::List<PaperType*>* get_papers() { return m_Papers; }
	
	/**
	*	@brief	�� ������ �����Ѵ�.
	*	@pre	����.
	*	@post	����.
	*	@param	title	�� ����.
	*/
	void set_title(string title) { m_Title = title; }

	/**
	*	@brief	�� ���� ��¥�� �����Ѵ�.
	*	@pre	����.
	*	@post	����.
	*	@param	date	�� ���� ��¥.
	*/
	void set_date(string date);

	/**
	*	@brief	���� �߰��Ѵ�.
	*	@pre	����.
	*	@post	����.
	*	@param	paper	�� ������.
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
	string m_Title;	///< �м���ȸ ����.
	string m_Date;	///< ���� ��¥.
	int m_YDate;	///< ���� ��¥ (����).
	int m_MDate;	///< ���� ��¥ (��).
	int m_DDate;	///< ���� ��¥ (��).
	kmh::List<PaperType*>* m_Papers;	///< �� ������ ���� ����Ʈ.

};

#endif _CONFERENCE_TYPE_H