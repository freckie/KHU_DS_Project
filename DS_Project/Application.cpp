#include "Application.h"

Application::Application()
{
	kmh::set_window_size(60, 25, "Conference Management System - 2017103964");
	m_Command = 0;
	m_Menu = MenuLevel::Main;
	m_NowConf = nullptr;
}

void Application::run()
{
	while (true)
	{
		m_Command = get_command();

		// 메뉴 구분 후 커맨드 구분.
		switch (m_Menu)
		{
			system("cls");

			// Main
		case MenuLevel::Main:
			switch (m_Command)
			{
			case 1:
				m_Menu = MenuLevel::Conference;
				break;
			case 2:
				m_Menu = MenuLevel::User;
				break;
			case 3:
				load_file();
				break;
			case 4:
				save_file();
				break;
			case 0:
				exit(1);
			default:
				cout << ColorType::LRed << "\n\t[ERROR] 잘못된 입력!" << ColorType::Default << endl;
				_getch();
				break;
			}
			break;

			// Conference
		case MenuLevel::Conference:
			switch (m_Command)
			{
			case 1:
				add_conference();
				break;
			case 2:
				delete_conference();
				break;
			case 3:
				replace_conference();
				break;
			case 4:
				display_all_conference();
				break;
			case 5: // 학술대회 선택 후 모두 출력
				display_conf_author();
				break;
			case 6:
				select_conference();
				m_Menu = MenuLevel::Paper;
				break;
			case 9:
				m_Menu = MenuLevel::Main;
				break;
			case 0:
				exit(1);
			default:
				cout << ColorType::LRed << "\n\t[ERROR] 잘못된 입력!" << ColorType::Default << endl;
				_getch();
				break;
			}
			break;

			// Paper
		case MenuLevel::Paper:
			switch (m_Command)
			{
			case 1:
				add_paper();
				break;
			case 2:
				delete_paper();
				break;
			case 3:
				replace_paper();
				break;
			case 4:
				display_conf_paper();
				break;
			case 9:
				m_Menu = MenuLevel::Conference;
				break;
			case 0:
				exit(1);
			default:
				cout << ColorType::LRed << "\n\t[ERROR] 잘못된 입력!" << ColorType::Default << endl;
				_getch();
				break;
			}
			break;

			// User
		case MenuLevel::User:
			switch (m_Command)
			{
			case 1:
				display_all_conference();
				break;
			case 2:
				display_all_paper();
				break;
			case 3:
				display_all_author();
				break;
			case 4:
				user_search_conference();
				break;
			case 5:
				user_search_paper();
				break;
			case 6:
				user_author_ranking();
				break;
			case 9:
				m_Menu = MenuLevel::Main;
				break;
			case 0:
				exit(1);
			default:
				cout << ColorType::LRed << "\n\t[ERROR] 잘못된 입력!" << ColorType::Default << endl;
				_getch();
				break;
			}
			break;
		}
	}
}

int Application::get_command()
{
	int comm;
	system("cls");

	// 메뉴 레벨이 main
	if (m_Menu == MenuLevel::Main)
	{
		cout << endl << endl;
		cout << ColorType::LPurple << "\t< 메인 메뉴 >" << ColorType::Default << endl << endl;
		cout << "\t1. 관리자 메뉴" << endl;
		cout << "\t2. 사용자 메뉴" << endl;
		cout << "\t3. 불러오기" << endl;
		cout << "\t4. 저장하기" << endl;
	}
	// 메뉴 레벨이 Conference
	else if (m_Menu == MenuLevel::Conference)
	{
		cout << endl << endl;
		cout << ColorType::LPurple << "\t< 관리자 메뉴 - 학술대회 >" << ColorType::Default << endl << endl;
		cout << "\t1. 학술대회 추가" << endl;
		cout << "\t2. 학술대회 삭제" << endl;
		cout << "\t3. 학술대회 정보 수정" << endl;
		cout << "\t4. 학술대회 정보 모두 출력" << endl;
		cout << "\t5. 참여한 저자 모두 출력" << endl;
		cout << "\t6. 논문 관리 메뉴 들어가기" << endl;
		cout << "\t9. 뒤로가기" << endl;
	}
	// 메뉴 레벨이 Paper
	else if (m_Menu == MenuLevel::Paper)
	{
		cout << endl << endl;
		cout << ColorType::LPurple << "\t< 관리자 메뉴 - 논문 >" << ColorType::Default << endl;
		cout << ColorType::LGreen << "\t\t선택된 학술 대회 : " << m_NowConf->get_title() 
			<< " (" << m_NowConf->get_papers()->length() << " )" << ColorType::Default << endl << endl;
		cout << "\t1. 논문 추가" << endl;
		cout << "\t2. 논문 삭제" << endl;
		cout << "\t3. 논문 정보 수정" << endl;
		cout << "\t4. 논문 정보 모두 출력" << endl;
		cout << "\t9. 뒤로가기" << endl;
	}
	// 메뉴 레벨이 User
	else if (m_Menu == MenuLevel::User)
	{
		cout << endl << endl;
		cout << ColorType::LPurple << "\t< 사용자 메뉴 >" << ColorType::Default << endl << endl;
		cout << "\t1. 모든 학술대회 출력" << endl;
		cout << "\t2. 모든 논문 출력" << endl;
		cout << "\t3. 모든 논문 저자 출력" << endl;
		cout << "\t4. 학술대회 검색" << endl;
		cout << "\t5. 논문 키워드로 검색" << endl;
		cout << "\t6. 저자 랭킹" << endl;
		cout << "\t9. 뒤로가기" << endl;
	}

	cout << "\t0. 프로그램 종료" << endl;

	cout << endl << "\t선택 >> ";
	cin >> comm;
	cout << endl;

	return comm;
}

void Application::add_conference()
{
	system("cls");

	cout << endl << endl;
	cout << ColorType::LPurple << "\t< 학술대회 메뉴 :: 학술대회 정보 추가 >" << ColorType::Default << endl << endl;

	// 정보 입력받아 임시 저장하기.
	ConferenceType temp;
	temp.set_title_kb();
	temp.set_date_kb();

	// 저장 실패하면
	if (!m_Conf.add(temp))
	{
		cout << ColorType::LRed << "\n\t[ERROR] 이미 있는 데이터입니다." << ColorType::Default << endl;
		_getch();
		return;
	}

	// 메세지
	cout << ColorType::LAqua << "\n\t추가되었습니다!" << ColorType::Default << endl;
	_getch();
}

// Conference 메뉴에서 학술대회 삭제.
void Application::delete_conference()
{
	system("cls");
	cout << endl << endl;
	cout << ColorType::LPurple << "\t< 학술대회 메뉴 :: 학술대회 삭제 >" << ColorType::Default << endl << endl;

	// 먼저 모두 출력
	kmh::LIterator<ConferenceType> iter;
	for (iter = m_Conf.begin(); iter != m_Conf.end(); ++iter)
	{
		(*iter).display_record();
		cout << endl;
	}

	// 정보 입력받아 임시 저장하기.
	ConferenceType temp;
	cout << endl << "\t삭제할 학술대회 제목을 지정하십시오. " << endl;
	temp.set_title_kb();

	// conference 존재하는지 확인
	kmh::LIterator<ConferenceType> siter = m_Conf.find(temp);
	if (siter.is_null())
	{
		cout << endl << ColorType::LRed << "\t[ERROR] 잘못된 학술대회 ID 입력!" << ColorType::Default << endl;
		_getch();
		return;
	}

	if (m_Conf.remove(temp))
		cout << endl << ColorType::LAqua << "\t삭제 완료!" << ColorType::Default << endl;
	else
		cout << endl << ColorType::LRed << "\t[ERROR]삭제 실패!" << ColorType::Default << endl;
	_getch();
}

// Conference 메뉴에서 학술대회 변경.
void Application::replace_conference()
{
	system("cls");
	cout << endl << endl;
	cout << ColorType::LPurple << "\t< 학술대회 메뉴 :: 학술대회 정보 변경 >" << ColorType::Default << endl << endl;

	// 정보 입력받아 임시 저장하기.
	ConferenceType temp;
	temp.set_title_kb();
	temp.set_date_kb();

	if (m_Conf.replace(temp) == false)
	{
		cout << ColorType::LRed << "\n\t[ERROR] 변경에 실패하였습니다." << ColorType::Default << endl;
		_getch();
		return;
	}

	// 메세지
	cout << ColorType::LAqua << "\n\t데이터가 변경되었습니다!" << ColorType::Default << endl;
	_getch();
}

void Application::select_conference()
{
	system("cls");
	cout << endl << endl;
	cout << ColorType::LPurple << "\t< 학술대회 메뉴 :: 학술대회 선택 >" << ColorType::Default << endl << endl;

	// 먼저 모두 출력
	kmh::LIterator<ConferenceType> iter;
	for (iter = m_Conf.begin(); iter != m_Conf.end(); ++iter)
	{
		(*iter).display_record();
		cout << endl;
	}

	// 정보 입력받아 임시 저장하기.
	ConferenceType temp;
	cout << endl << "\t삭제할 학술대회 제목을 지정하십시오. " << endl;
	temp.set_title_kb();

	// conference 존재하는지 확인
	kmh::LIterator<ConferenceType> siter = m_Conf.find(temp);
	if (siter.is_null())
	{
		cout << endl << ColorType::LRed << "\t[ERROR] 잘못된 학술대회 제목 입력!" << ColorType::Default << endl;
	}
	else
	{
		m_NowConf = &(*siter);
		cout << ColorType::LAqua << "\n\t해당 학술대회가 선택되었습니다" << ColorType::Default << endl;
	}
	_getch();
}

void Application::display_conf_paper()
{
}

void Application::display_conf_author()
{
}

void Application::add_paper()
{
}

void Application::delete_paper()
{
}

void Application::replace_paper()
{
}

void Application::display_paper()
{
}

void Application::display_all_conference()
{
}

void Application::display_all_paper()
{
}

void Application::display_all_author()
{
}

void Application::user_search_conference()
{
}

void Application::user_search_paper()
{
}

void Application::user_author_ranking()
{
}

void Application::load_file()
{
}

void Application::save_file()
{
}
