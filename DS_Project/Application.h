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
*	메뉴 레벨 열거형
*/
enum class MenuLevel { Main, Conference, Paper, User };


/**
*	프로그램 관리를 위한 프로그램 드라이버.
*/
class Application
{

public:

	/**
	*	기본 생성자.
	*/
	Application();

	/**
	*	@brief	프로그램 실행을 담당한다.
	*	@pre	프로그램이 시작한다.
	*	@post	프로그램이 끝난다.
	*/
	void run();

	/**
	*	@brief	Command를 스크린에 출력하고 키보드로부터 Command를 입력받는다.
	*	@pre	없음.
	*	@post	없음.
	*	@return	유저의 Command.
	*/
	int get_command();

	/**
	*	@brief	학술대회를 리스트에 추가한다.
	*	@pre	없음.
	*	@post	학술대회가 리스트에 추가된다.
	*/
	void add_conference();

	/**
	*	@brief	학술대회를 리스트에서 삭제한다.
	*	@pre	없음.
	*	@post	학술대회가 리스트에서 삭제된다.
	*/
	void delete_conference();

	/**
	*	@brief	학술대회를 리스트에서 변경한다.
	*	@pre	없음.
	*	@post	학술대회가 리스트에서 변경된다.
	*/
	void replace_conference();

	/**
	*	@brief	학술대회를 선택한다.
	*	@pre	없음.
	*	@post	학술대회가 선택된다.
	*/
	bool select_conference();

	/**
	*	@brief	학술대회에 포함된 논문을 모두 출력한다.
	*	@pre	없음.
	*	@post	학술대회에 포함된 논문을 모두 출력한다.
	*/
	void display_conf_paper();

	/**
	*	@brief	학술대회에 포함된 논문 저자를 모두 출력한다.
	*	@pre	없음.
	*	@post	학술대회에 포함된 논문 저자를 모두 출력한다.
	*/
	void display_conf_author();
	
	/**
	*	@brief	논문을 리스트에 추가한다.
	*	@pre	없음.
	*	@post	논문이 리스트에 추가된다.
	*/
	void add_paper();

	/**
	*	@brief	논문을 리스트에서 삭제한다.
	*	@pre	없음.
	*	@post	논문이 리스트에서 삭제된다.
	*/
	void delete_paper();

	/**
	*	@brief	논문을 리스트에서 변경한다.
	*	@pre	없음.
	*	@post	논문이 리스트에서 변경된다.
	*/
	void replace_paper();

	/**
	*	@brief	논문을 화면에 출력한다.
	*	@pre	없음.
	*	@post	논문이 화면에 출력한다.
	*/
	void display_paper();

	/**
	*	@brief	학술대회를 모두 화면에 출력한다.
	*	@pre	없음.
	*	@post	학술대회가 모두 화면에 출력된다.
	*/
	void display_all_conference();

	/**
	*	@brief	논문을 모두 화면에 출력한다.
	*	@pre	없음.
	*	@post	논문이 모두 화면에 출력된다.
	*/
	void display_all_paper();

	/**
	*	@brief	논문 저자들을 모두 화면에 출력한다.
	*	@pre	없음.
	*	@post	논문 저자들이 모두 화면에 출력된다.
	*/
	void display_all_author();

	/**
	*	@brief	학술대회를 검색한다.
	*	@pre	없음.
	*	@post	검색된 학술대회가 출력된다.
	*/
	void user_search_conference();

	/**
	*	@brief	논문을 검색한다.
	*	@pre	없음.
	*	@post	검색된 논문이 출력된다.
	*/
	void user_search_paper();

	/**
	*	@brief	저자 랭킹을 출력한다.
	*	@pre	없음.
	*	@post	저자 랭킹이 출력된다.
	*/
	void user_author_ranking();

	/**
	*	@brief	파일로부터 데이터를 읽어온다.
	*	@pre	없음.
	*	@post	파일에서 데이터를 읽는다.
	*/
	void load_file();

	/**
	*	@brief	파일에 데이터를 저장한다.
	*	@pre	없음.
	*	@post	파일에 데이터가 저장된다.
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