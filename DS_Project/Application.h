#pragma once

#ifndef _APPLICATION_H
#define _APPLICATION_H

#include<Windows.h>
#include<iostream>
#include<conio.h>
#include<string>

#include"BinaryTreeIterator.h"
#include"LinkedListIterator.h"
#include"ArrayListIterator.h"
#include"BinaryTree.h"
#include"LinkedList.h"
#include"ArrayList.h"

#include"ConferenceType.h"
#include"PaperType.h"
#include"AuthorType.h"

#include"Api.h"

using namespace std;
using kmh::ColorType;

/**
*	�޴� ���� ������
*/
enum class MenuLevel { Main, Conference, Paper, User };


/**
*	���α׷� ������ ���� ���α׷� ����̹�.
*/
class Application
{

public:

	/**
	*	�⺻ ������.
	*/
	Application();

	/**
	*	@brief	���α׷� ������ ����Ѵ�.
	*	@pre	���α׷��� �����Ѵ�.
	*	@post	���α׷��� ������.
	*/
	void run();

	/**
	*	@brief	Command�� ��ũ���� ����ϰ� Ű����κ��� Command�� �Է¹޴´�.
	*	@pre	����.
	*	@post	����.
	*	@return	������ Command.
	*/
	int get_command();

	/**
	*	@brief	�м���ȸ�� ����Ʈ�� �߰��Ѵ�.
	*	@pre	����.
	*	@post	�м���ȸ�� ����Ʈ�� �߰��ȴ�.
	*/
	void add_conference();

	/**
	*	@brief	�м���ȸ�� ����Ʈ���� �����Ѵ�.
	*	@pre	����.
	*	@post	�м���ȸ�� ����Ʈ���� �����ȴ�.
	*/
	void delete_conference();

	/**
	*	@brief	�м���ȸ�� ����Ʈ���� �����Ѵ�.
	*	@pre	����.
	*	@post	�м���ȸ�� ����Ʈ���� ����ȴ�.
	*/
	void replace_conference();

	/**
	*	@brief	�м���ȸ�� �����Ѵ�.
	*	@pre	����.
	*	@post	�м���ȸ�� ���õȴ�.
	*/
	bool select_conference();

	/**
	*	@brief	�м���ȸ�� ���Ե� ���� ��� ����Ѵ�.
	*	@pre	����.
	*	@post	�м���ȸ�� ���Ե� ���� ��� ����Ѵ�.
	*/
	void display_conf_paper();

	/**
	*	@brief	�м���ȸ�� ���Ե� �� ���ڸ� ��� ����Ѵ�.
	*	@pre	����.
	*	@post	�м���ȸ�� ���Ե� �� ���ڸ� ��� ����Ѵ�.
	*/
	void display_conf_author();
	
	/**
	*	@brief	���� ����Ʈ�� �߰��Ѵ�.
	*	@pre	����.
	*	@post	���� ����Ʈ�� �߰��ȴ�.
	*/
	void add_paper();

	/**
	*	@brief	���� ����Ʈ���� �����Ѵ�.
	*	@pre	����.
	*	@post	���� ����Ʈ���� �����ȴ�.
	*/
	void delete_paper();

	/**
	*	@brief	���� ����Ʈ���� �����Ѵ�.
	*	@pre	����.
	*	@post	���� ����Ʈ���� ����ȴ�.
	*/
	void replace_paper();

	/**
	*	@brief	���� ȭ�鿡 ����Ѵ�.
	*	@pre	����.
	*	@post	���� ȭ�鿡 ����Ѵ�.
	*/
	void display_paper();

	/**
	*	@brief	�м���ȸ�� ��� ȭ�鿡 ����Ѵ�.
	*	@pre	����.
	*	@post	�м���ȸ�� ��� ȭ�鿡 ��µȴ�.
	*/
	void display_all_conference();

	/**
	*	@brief	���� ��� ȭ�鿡 ����Ѵ�.
	*	@pre	����.
	*	@post	���� ��� ȭ�鿡 ��µȴ�.
	*/
	void display_all_paper();

	/**
	*	@brief	�� ���ڵ��� ��� ȭ�鿡 ����Ѵ�.
	*	@pre	����.
	*	@post	�� ���ڵ��� ��� ȭ�鿡 ��µȴ�.
	*/
	void display_all_author();

	/**
	*	@brief	�м���ȸ�� �˻��Ѵ�.
	*	@pre	����.
	*	@post	�˻��� �м���ȸ�� ��µȴ�.
	*/
	void user_search_conference();

	/**
	*	@brief	���� �˻��Ѵ�.
	*	@pre	����.
	*	@post	�˻��� ���� ��µȴ�.
	*/
	void user_search_paper();

	/**
	*	@brief	���� ��ŷ�� ����Ѵ�.
	*	@pre	����.
	*	@post	���� ��ŷ�� ��µȴ�.
	*/
	void user_author_ranking();

	/**
	*	@brief	���Ϸκ��� �����͸� �о�´�.
	*	@pre	����.
	*	@post	���Ͽ��� �����͸� �д´�.
	*/
	void load_file();

	/**
	*	@brief	���Ͽ� �����͸� �����Ѵ�.
	*	@pre	����.
	*	@post	���Ͽ� �����Ͱ� ����ȴ�.
	*/
	void save_file();

private:
	int m_Command;
	MenuLevel m_Menu;
	kmh::LinkedList<ConferenceType> m_Conf;
	kmh::BinaryTree<PaperType> m_Paper;
	ConferenceType* m_NowConf;

};

#endif _APPLICATION_H