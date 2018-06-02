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