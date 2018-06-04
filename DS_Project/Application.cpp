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
				if(select_conference())
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
				m_NowConf = nullptr;
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
				user_search_conference_year();
				break;
			case 6:
				user_search_paper();
				break;
			case 7:
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
		cout << ColorType::LPurple << "\t< 관리자 메뉴 - 논문 >" << ColorType::Default << endl << endl;
		cout << ColorType::LGreen << "\t\t선택된 학술 대회 : " << m_NowConf->get_title() 
			<< " ( " << m_NowConf->get_papers()->length() << " )" << ColorType::Default << endl << endl;
		cout << "\t1. 논문 추가" << endl;
		cout << "\t2. 논문 삭제" << endl;
		cout << "\t3. 논문 정보 수정" << endl;
		cout << "\t4. 포함된 논문 정보 모두 출력" << endl;
		cout << "\t9. 뒤로가기" << endl;
	}
	// 메뉴 레벨이 User
	else if (m_Menu == MenuLevel::User)
	{
		cout << endl << endl;
		cout << ColorType::LPurple << "\t< 사용자 메뉴 >" << ColorType::Default << endl << endl;
		cout << "\t1. 모든 학술대회 출력" << endl;
		cout << "\t2. 모든 논문 출력" << endl;
		cout << "\t3. 모든 저자 출력" << endl;
		cout << "\t4. 학술대회 이름으로 검색" << endl;
		cout << "\t5. 학술대회 개최 연도로 검색" << endl;
		cout << "\t6. 논문 키워드로 검색" << endl;
		cout << "\t7. 저자 랭킹" << endl;
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

	// 리스트가 비었을 경우.
	if (m_Conf.is_empty())
	{
		cout << endl << ColorType::LRed << "\t검색 결과가 없습니다." << ColorType::Default << endl;
		_getch();
		return;
	}

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

bool Application::select_conference()
{
	system("cls");
	cout << endl << endl;
	cout << ColorType::LPurple << "\t< 학술대회 메뉴 :: 학술대회 선택 >" << ColorType::Default << endl << endl;

	// 리스트가 비었을 경우.
	if (m_Conf.is_empty())
	{
		cout << endl << ColorType::LRed << "\t검색 결과가 없습니다." << ColorType::Default << endl;
		_getch();
		return false;
	}

	// 먼저 모두 출력
	kmh::LIterator<ConferenceType> iter;
	for (iter = m_Conf.begin(); iter != m_Conf.end(); ++iter)
	{
		(*iter).display_record();
		cout << endl;
	}

	// 정보 입력받아 임시 저장하기.
	ConferenceType temp;
	cout << endl << "\t선택할 학술대회 제목을 지정하십시오. " << endl;
	temp.set_title_kb();

	// conference 존재하는지 확인
	kmh::LIterator<ConferenceType> siter = m_Conf.find(temp);
	if (siter.is_null())
	{
		cout << endl << ColorType::LRed << "\t[ERROR] 잘못된 학술대회 제목 입력!" << ColorType::Default << endl;
		return false;
	}
	else
	{
		m_NowConf = &(*siter);
		cout << ColorType::LAqua << "\n\t해당 학술대회가 선택되었습니다." << ColorType::Default << endl;
	}
	_getch();

	return true;
}

void Application::display_conf_paper()
{
	//if (!select_conference())
		//return;

	system("cls");
	cout << endl << endl;
	cout << ColorType::LPurple << "\t< 논문 메뉴 :: 포함된 논문 모두 출력 >" << ColorType::Default << endl << endl;
	cout << ColorType::LGreen << "\t\t선택된 학술 대회 : " << m_NowConf->get_title()
		<< " ( " << m_NowConf->get_papers()->length() << " )" << ColorType::Default << endl << endl;

	// 만약 비었을 경우
	if(m_NowConf->get_papers()->is_empty())
	{
		cout << endl << ColorType::LRed << "\t검색 결과가 없습니다." << ColorType::Default << endl;
		_getch();
		return;
	}

	m_NowConf->display_papers();

	cout << endl << ColorType::LGreen << "\t모든 정보를 출력하였습니다.\n";
	_getch();
}

void Application::display_conf_author()
{
	if (!select_conference())
		return;

	system("cls");
	cout << endl << endl;
	cout << ColorType::LPurple << "\t< 학술대회 메뉴 :: 참가한 저자 모두 출력 >" << ColorType::Default << endl << endl;
	cout << ColorType::LGreen << "\t\t선택된 학술 대회 : " << m_NowConf->get_title()
		<< " ( " << m_NowConf->get_papers()->length() << " )" << ColorType::Default << endl << endl;

	// 만약 논문이 없다면
	if (m_NowConf->get_papers()->length() == 0)
	{
		cout << endl << ColorType::LRed
			<< "\t[ERROR] 포함된 논문이 없습니다." << ColorType::Default << endl;
		_getch();
		return;
	}

	// 저자 리스트에 추가하기.
	kmh::List<string> author_list;

	kmh::LIterator<ConferenceType> iter;
	for (iter = m_Conf.begin(); iter != m_Conf.end(); ++iter)
	{
		kmh::LIterator<kmh::BTreeNode<PaperType>*> iter2;
		kmh::List<kmh::BTreeNode<PaperType>*>* ptr = (*iter).get_papers();
		for (iter2 = ptr->begin(); iter2 != ptr->end(); ++iter2)
		{
			kmh::AIterator<AuthorType> iter3;
			kmh::ArrayList<AuthorType>* ptr2 = (*iter2)->data.get_author();
			for (iter3 = ptr2->begin(); iter3 != ptr2->end(); ++iter3)
			{
				author_list.add((*iter3).get_name());
			}
		}
	}

	cout << "\t학술대회에 참가한 저자는 다음과 같습니다.\n";
	// 저자 리스트 출력
	kmh::LIterator<string> iter4;
	int idx = 1;
	for (iter4 = author_list.begin(); iter4 != author_list.end(); ++iter4)
	{
		cout << idx << ". " << *iter4 << endl;
		idx++;
	}

	cout << ColorType::LAqua << "\n\t해당 학술대회의 모든 저자가 출력되었습니다." << ColorType::Default << endl;
	_getch();
}

void Application::add_paper()
{
	system("cls");
	cout << endl << endl;
	cout << ColorType::LPurple << "\t< 논문 메뉴 :: 논문 추가 >" << ColorType::Default << endl << endl;
	cout << ColorType::LGreen << "\t\t선택된 학술 대회 : " << m_NowConf->get_title()
		<< " ( " << m_NowConf->get_papers()->length() << " )" << ColorType::Default << endl << endl;

	// 정보 입력받아 임시 저장하기
	PaperType* temp = new PaperType;
	temp->set_title_kb();
	temp->set_page_kb();
	temp->set_author_kb();

	cout << ColorType::LAqua 
		<< "\n\t추가할 논문 데이터 설정이 완료되었습니다." << ColorType::Default << endl;

	// 논문 추가하기. (Tree에 추가 후, 포인터를 ConferenceType에 추가.)
	kmh::BTreeNode<PaperType>* temp_node;
	temp_node = m_Paper.add_and_get(*temp);

	if (temp_node == nullptr)
	{
		cout << endl << ColorType::LRed 
			<< "\t[ERROR] 논문 추가에 실패하였습니다." << ColorType::Default << endl;
		_getch();
		return;
	}

	// 논문 추가할 때, 저자도 추가.
	m_NowConf->add_paper(temp_node);
	kmh::ArrayList<AuthorType>* temp_author = temp_node->data.get_author();
	for (auto iter = temp_author->begin(); iter != temp_author->end(); ++iter)
	{
		// 만약 저자 리스트가 비어있다면
		if (m_Author.is_empty())
		{
			m_Author.emplace(*iter, 1);
		}
		else
		{
			// 만약 추가되지 않은 저자라면, 추가.
			if (m_Author.find(*iter).is_null())
				m_Author.emplace(*iter, 1);
			// 추가되어있는 저자라면, 값++
			else
				(*(m_Author.find(*iter))).val++;
		}
	}

	cout << ColorType::LAqua
		<< "\n\t논문이 추가되었습니다!" << ColorType::Default << endl;
	_getch();
}

void Application::delete_paper()
{
	system("cls");
	cout << endl << endl;
	cout << ColorType::LPurple << "\t< 논문 메뉴 :: 논문 삭제 >" << ColorType::Default << endl << endl;
	cout << ColorType::LGreen << "\t\t선택된 학술 대회 : " << m_NowConf->get_title()
		<< " ( " << m_NowConf->get_papers()->length() << " )" << ColorType::Default << endl << endl;

	// 정보 입력받아 임시 저장하기
	PaperType temp;
	temp.set_title_kb();

	// 논문 삭제하기.
	kmh::BTreeNode<PaperType>* temp_node = m_Paper.get_node(temp);

	if (temp_node == nullptr)
	{
		cout << endl << ColorType::LRed
			<< "\t[ERROR] 논문 삭제에 실패하였습니다." << ColorType::Default << endl;
		_getch();
		return;
	}

	// 저자 카운트 삭제.
	kmh::ArrayList<AuthorType>* temp_author = temp_node->data.get_author();
	for (auto iter = temp_author->begin(); iter != temp_author->end(); ++iter)
	{
		auto found = m_Author.find(*iter);
		if ((*found).val == 1)
			m_Author.remove(*iter);
		else
			(*found).val--;
	}

	if(m_NowConf->get_papers()->remove(temp_node))
		cout << ColorType::LAqua
			<< "\n\t논문이 삭제되었습니다!" << ColorType::Default << endl;
	else
		cout << endl << ColorType::LRed
			<< "\t[ERROR] 논문 삭제에 실패하였습니다." << ColorType::Default << endl;

	_getch();
}

void Application::replace_paper()
{
	system("cls");
	cout << endl << endl;
	cout << ColorType::LPurple << "\t< 논문 메뉴 :: 논문 변경 >" << ColorType::Default << endl << endl;
	cout << ColorType::LGreen << "\t\t선택된 학술 대회 : " << m_NowConf->get_title()
		<< " ( " << m_NowConf->get_papers()->length() << " )" << ColorType::Default << endl << endl;

	// 정보 입력받아 임시 저장하기
	PaperType* temp = new PaperType;
	temp->set_title_kb();
	temp->set_page_kb();
	temp->set_author_kb();

	// 논문 삭제하기.
	kmh::BTreeNode<PaperType>* temp_node = m_Paper.get_node(*temp);

	if (temp_node == nullptr)
	{
		cout << endl << ColorType::LRed
			<< "\t[ERROR] 논문 변경에 실패하였습니다." << ColorType::Default << endl;
		_getch();
		return;
	}

	if (m_NowConf->get_papers()->replace(temp_node))
		cout << ColorType::LAqua
		<< "\n\t논문이 변경되었습니다!" << ColorType::Default << endl;
	else
		cout << endl << ColorType::LRed
		<< "\t[ERROR] 논문 변경에 실패하였습니다." << ColorType::Default << endl;

	_getch();
}

void Application::display_all_conference()
{
	system("cls");
	cout << endl << endl;
	cout << ColorType::LPurple << "\t< 학술대회 메뉴 :: 모든 학술대회 목록 >" << ColorType::Default << endl << endl;

	// 리스트가 비었을 경우.
	if (m_Conf.is_empty())
	{
		cout << endl << ColorType::LRed << "\t검색 결과가 없습니다." << ColorType::Default << endl;
		_getch();
		return;
	}

	// 모두 출력
	kmh::LIterator<ConferenceType> iter;
	for (iter = m_Conf.begin(); iter != m_Conf.end(); ++iter)
	{
		(*iter).display_record();
		cout << endl;
	}

	cout << ColorType::LAqua << "\n\t결과를 모두 출력하였습니다." << ColorType::Default << endl;
	_getch();
}

void Application::display_all_paper()
{
	system("cls");
	cout << endl << endl;
	cout << ColorType::LPurple << "\t< 사용자 메뉴 :: 모든 논문 출력 >" << ColorType::Default << endl << endl;

	// 리스트가 비었을 경우.
	if (m_Paper.is_empty())
	{
		cout << endl << ColorType::LRed << "\t검색 결과가 없습니다." << ColorType::Default << endl;
		_getch();
		return;
	}

	// 모두 출력
	kmh::BIterator<PaperType> iter;
	for (iter = m_Paper.begin(); iter != m_Paper.end(); ++iter)
	{
		(*iter).display_record();
		cout << endl;
	}

	cout << ColorType::LAqua << "\n\t결과를 모두 출력하였습니다." << ColorType::Default << endl;
	_getch();
}

void Application::display_all_author()
{
	system("cls");
	cout << endl << endl;
	cout << ColorType::LPurple << "\t< 사용자 메뉴 :: 모든 저자 출력 >" << ColorType::Default << endl << endl;

	// 리스트가 비었을 경우.
	if (m_Author.is_empty())
	{
		cout << endl << ColorType::LRed << "\t검색 결과가 없습니다." << ColorType::Default << endl;
		_getch();
		return;
	}

	int idx = 1;
	kmh::LIterator<kmh::Pair<AuthorType, int>> iter;
	for (iter = m_Author.begin(); iter != m_Author.end(); ++iter)
	{
		cout << "\t" << idx << ". " << (*iter).key.get_name()
			<< " ( " << (*iter).val << " ) " << endl;
		idx++;
	}

	cout << ColorType::LAqua << "\n\t결과를 모두 출력하였습니다." << ColorType::Default << endl;
	_getch();
}

void Application::user_search_conference()
{
	system("cls");
	cout << endl << endl;
	cout << ColorType::LPurple << "\t< 사용자 메뉴 :: 학술대회 이름으로 검색 >" << ColorType::Default << endl << endl;

	// 데이터 임시 저장.
	ConferenceType temp;
	temp.set_title_kb();

	// 데이터 검색 후 출력.
	kmh::LIterator<ConferenceType> result = m_Conf.find(temp);
	if (result.is_null())
	{
		cout << endl << ColorType::LRed << "\t검색 결과가 없습니다. 정확한 학술대회 이름을 입력해주세요." << ColorType::Default << endl;
		_getch();
		return;
	}

	(*result).display_record();

	cout << ColorType::LAqua << "\n\t검색 완료되었습니다." << ColorType::Default << endl;
	_getch();
}

void Application::user_search_conference_year()
{
	system("cls");
	cout << endl << endl;
	cout << ColorType::LPurple << "\t< 사용자 메뉴 :: 학술대회 연도로 검색 >" << ColorType::Default << endl << endl;

	int year;
	cout << "\t연도 : ";
	cin >> year;
	cout << endl;

	bool found = false;

	// 데이터 검색 후 출력.
	kmh::LIterator<ConferenceType> iter;
	for (iter = m_Conf.begin(); iter != m_Conf.end(); ++iter)
	{
		if ((*iter).get_ydate() == year)
		{
			(*iter).display_record();
			found = true;
		}
	}

	// 검색 결과가 없을 경우
	if(!found)
	{
		cout << endl << ColorType::LRed << "\t검색 결과가 없습니다. 정확한 학술대회 이름을 입력해주세요." << ColorType::Default << endl;
		_getch();
		return;
	}
	// 검색 결과가 있을 경우
	else
	{
		cout << ColorType::LAqua << "\n\t검색 완료되었습니다." << ColorType::Default << endl;
		_getch();
	}
}

void Application::user_search_paper()
{
	system("cls");
	cout << endl << endl;
	cout << ColorType::LPurple << "\t< 사용자 메뉴 :: 논문 키워드로 검색 >" << ColorType::Default << endl << endl;

	string keyword;
	cout << "\t검색어 : ";
	cin >> keyword;
	cout << endl;

	// 검색
	bool found = false;
	cout << endl << "\t--- 검색 결과 ---" << endl;
	kmh::BIterator<PaperType> iter;
	for (iter = m_Paper.begin(); iter != m_Paper.end(); ++iter)
	{
		if ((*iter).get_title().find(keyword) != string::npos)
		{
			found = true;
			(*iter).display_record();
		}
	}

	// 검색 결과가 없을 경우
	if (!found)
	{
		cout << endl << ColorType::LRed << "\t검색 결과가 없습니다." << ColorType::Default << endl;
		_getch();
		return;
	}
	// 검색 결과가 있을 경우
	else
	{
		cout << ColorType::LAqua << "\n\t검색 완료되었습니다." << ColorType::Default << endl;
		_getch();
	}
}

void Application::user_author_ranking()
{
	system("cls");
	cout << endl << endl;
	cout << ColorType::LPurple << "\t< 사용자 메뉴 :: 저자 랭킹 >" << ColorType::Default << endl << endl;

}

void Application::load_file()
{
}

void Application::save_file()
{
}
