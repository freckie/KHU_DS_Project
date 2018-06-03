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
	*	@brief	�м���ȸ ������ �����´�.
	*	@pre	�м���ȸ ������ �����Ǿ�� �Ѵ�.
	*	@post	����.
	*	@return	�м���ȸ ����.
	*/
	string get_title() { return m_Title; }

	/**
	*	@brief	�м���ȸ ��¥�� �����´�.
	*	@pre	�м���ȸ ��¥�� �����Ǿ�� �Ѵ�.
	*	@post	����.
	*	@return	�м���ȸ ��¥.
	*/
	string get_date() { return m_Date; }

	/**
	*	@brief	�м���ȸ ��¥(����)�� �����´�.
	*	@pre	�м���ȸ ��¥�� �����Ǿ�� �Ѵ�.
	*	@post	����.
	*	@return	�м���ȸ ��¥(����).
	*/
	int get_ydate() { return m_YDate; }

	/**
	*	@brief	�м���ȸ ��¥(��)�� �����´�.
	*	@pre	�м���ȸ ��¥�� �����Ǿ�� �Ѵ�.
	*	@post	����.
	*	@return	�м���ȸ ��¥(��).
	*/
	int get_mdate() { return m_MDate; }

	/**
	*	@brief	�м���ȸ ��¥(��)�� �����´�.
	*	@pre	�м���ȸ ��¥�� �����Ǿ�� �Ѵ�.
	*	@post	����.
	*	@return	�м���ȸ ��¥(��).
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
	*	@brief	�м���ȸ ������ �����Ѵ�.
	*	@pre	����.
	*	@post	����.
	*	@param	title	�м���ȸ ����.
	*/
	void set_title(string title) { m_Title = title; }

	/**
	*	@brief	�м���ȸ ���� ��¥�� �����Ѵ�.
	*	@pre	����.
	*	@post	����.
	*	@param	date	�м���ȸ ���� ��¥.
	*/
	void set_date(string date);

	/**
	*	@brief	�м���ȸ �̸��� Ű����κ��� �����Ѵ�.
	*	@pre	����.
	*	@post	����.
	*/
	void set_title_kb();

	/**
	*	@brief	�м���ȸ ���� ��¥�� Ű����κ��� �����Ѵ�.
	*	@pre	����.
	*	@post	����.
	*/
	void set_date_kb();

	/**
	*	@brief	���� �߰��Ѵ�.
	*	@pre	����.
	*	@post	����.
	*	@param	paper	�� ������.
	*/
	void add_paper(PaperType* paper);

	/**
	*	@brief	�м���ȸ ������ ȭ�鿡 ����Ѵ�.
	*	@pre	�м���ȸ ������ �����Ǿ�� �Ѵ�.
	*	@post	�м���ȸ ������ ȭ�鿡 ��µȴ�.
	*/
	void display_title();

	/**
	*	@brief	�м���ȸ ���� ��¥�� ȭ�鿡 ����Ѵ�.
	*	@pre	�м���ȸ ���� ��¥�� �����Ǿ�� �Ѵ�.
	*	@post	�м���ȸ ���� ��¥�� ȭ�鿡 ��µȴ�.
	*/
	void display_date();

	/**
	*	@brief	�м���ȸ�� ���Ե� ���� ȭ�鿡 ����Ѵ�.
	*	@pre	�м���ȸ�� ���Ե� ���� �����Ǿ�� �Ѵ�.
	*	@post	�м���ȸ�� ���Ե� ���� ȭ�鿡 ��µȴ�.
	*/
	void display_papers();

	/**
	*	@brief	�м���ȸ ��� �����͸� ȭ�鿡 ����Ѵ�.
	*	@pre	�м���ȸ ��� �����Ͱ� �����Ǿ�� �Ѵ�.
	*	@post	�м���ȸ ��� �����Ͱ� ȭ�鿡 ��µȴ�.
	*/
	void display_record();

	/**
	*	@brief	���ڿ��� ��ġ�ϴ� ���� ã�� ��ȯ�Ѵ�.
	*	@pre	����.
	*	@post	����.
	*	@param	paper_title	�˻��� �� �̸� string.
	*	@return	�ش� ���� ���� iterator.
	*/
	kmh::LIterator<PaperType*> find_paper(string paper_title);

	/**
	*	@brief	���ڿ��� ��ġ�ϴ� ���� ã�� ��ȯ�Ѵ�.
	*	@pre	����.
	*	@post	����.
	*	@param	paper	ã�� papertype.
	*	@return	�ش� ���� ���� iterator.
	*/
	kmh::LIterator<PaperType*> find_paper(PaperType& paper);

	/**
	*	@brief	���ڿ��� ���� ���Ե� ���� ã�� ��ȯ�Ѵ�.
	*	@pre	����.
	*	@post	����.
	*	@param	keyword	ã�� Ű����.
	*/
	void search_paper(string keyword);
	
	/**
	*	@brief	item id�� ���� �� �������� ���Ѵ�.
	*	@pre	�� ������ Ÿ���� �ʱ�ȭ�Ǿ�� �Ѵ�.
	*	@param	lhs	�񱳸� ���� ������ 1.
	*			rhs	�񱳸� ���� ������ 2.
	*	@return	lhs�� ũ�ٸ� true.
	*/
	friend bool operator > (const ConferenceType& lhs, const ConferenceType& rhs);

	/**
	*	@brief	item id�� ���� �� �������� ���Ѵ�.
	*	@pre	�� ������ Ÿ���� �ʱ�ȭ�Ǿ�� �Ѵ�.
	*	@param	lhs	�񱳸� ���� ������ 1.
	*			rhs	�񱳸� ���� ������ 2.
	*	@return	lhs�� ũ�ٸ� true.
	*/
	friend bool operator < (const ConferenceType& lhs, const ConferenceType& rhs);

	/**
	*	@brief	item id�� ���� �� �������� ���Ѵ�.
	*	@pre	�� ������ Ÿ���� �ʱ�ȭ�Ǿ�� �Ѵ�.
	*	@param	lhs	�񱳸� ���� ������ 1.
	*			rhs	�񱳸� ���� ������ 2.
	*	@return	lhs�� ũ�ٸ� true.
	*/
	friend bool operator == (const ConferenceType& lhs, const ConferenceType& rhs);

	/**
	*	@brief	item id�� ���� �� �������� ���Ѵ�.
	*	@pre	�� ������ Ÿ���� �ʱ�ȭ�Ǿ�� �Ѵ�.
	*	@param	lhs	�񱳸� ���� ������ 1.
	*			rhs	�񱳸� ���� ������ 2.
	*	@return	lhs�� ũ�ٸ� true.
	*/
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