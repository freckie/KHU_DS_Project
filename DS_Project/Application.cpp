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

		// �޴� ���� �� Ŀ�ǵ� ����.
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
				cout << ColorType::LRed << "\n\t[ERROR] �߸��� �Է�!" << ColorType::Default << endl;
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
			case 5: // �м���ȸ ���� �� ��� ���
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
				cout << ColorType::LRed << "\n\t[ERROR] �߸��� �Է�!" << ColorType::Default << endl;
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
				cout << ColorType::LRed << "\n\t[ERROR] �߸��� �Է�!" << ColorType::Default << endl;
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
				cout << ColorType::LRed << "\n\t[ERROR] �߸��� �Է�!" << ColorType::Default << endl;
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

	// �޴� ������ main
	if (m_Menu == MenuLevel::Main)
	{
		cout << endl << endl;
		cout << ColorType::LPurple << "\t< ���� �޴� >" << ColorType::Default << endl << endl;
		cout << "\t1. ������ �޴�" << endl;
		cout << "\t2. ����� �޴�" << endl;
		cout << "\t3. �ҷ�����" << endl;
		cout << "\t4. �����ϱ�" << endl;
	}
	// �޴� ������ Conference
	else if (m_Menu == MenuLevel::Conference)
	{
		cout << endl << endl;
		cout << ColorType::LPurple << "\t< ������ �޴� - �м���ȸ >" << ColorType::Default << endl << endl;
		cout << "\t1. �м���ȸ �߰�" << endl;
		cout << "\t2. �м���ȸ ����" << endl;
		cout << "\t3. �м���ȸ ���� ����" << endl;
		cout << "\t4. �м���ȸ ���� ��� ���" << endl;
		cout << "\t5. ������ ���� ��� ���" << endl;
		cout << "\t6. �� ���� �޴� ����" << endl;
		cout << "\t9. �ڷΰ���" << endl;
	}
	// �޴� ������ Paper
	else if (m_Menu == MenuLevel::Paper)
	{
		cout << endl << endl;
		cout << ColorType::LPurple << "\t< ������ �޴� - �� >" << ColorType::Default << endl << endl;
		cout << ColorType::LGreen << "\t\t���õ� �м� ��ȸ : " << m_NowConf->get_title() 
			<< " ( " << m_NowConf->get_papers()->length() << " )" << ColorType::Default << endl << endl;
		cout << "\t1. �� �߰�" << endl;
		cout << "\t2. �� ����" << endl;
		cout << "\t3. �� ���� ����" << endl;
		cout << "\t4. ���Ե� �� ���� ��� ���" << endl;
		cout << "\t9. �ڷΰ���" << endl;
	}
	// �޴� ������ User
	else if (m_Menu == MenuLevel::User)
	{
		cout << endl << endl;
		cout << ColorType::LPurple << "\t< ����� �޴� >" << ColorType::Default << endl << endl;
		cout << "\t1. ��� �м���ȸ ���" << endl;
		cout << "\t2. ��� �� ���" << endl;
		cout << "\t3. ��� ���� ���" << endl;
		cout << "\t4. �м���ȸ �̸����� �˻�" << endl;
		cout << "\t5. �м���ȸ ���� ������ �˻�" << endl;
		cout << "\t6. �� Ű����� �˻�" << endl;
		cout << "\t7. ���� ��ŷ" << endl;
		cout << "\t9. �ڷΰ���" << endl;
	}

	cout << "\t0. ���α׷� ����" << endl;

	cout << endl << "\t���� >> ";
	cin >> comm;
	cout << endl;

	return comm;
}

void Application::add_conference()
{
	system("cls");

	cout << endl << endl;
	cout << ColorType::LPurple << "\t< �м���ȸ �޴� :: �м���ȸ ���� �߰� >" << ColorType::Default << endl << endl;

	// ���� �Է¹޾� �ӽ� �����ϱ�.
	ConferenceType temp;
	temp.set_title_kb();
	temp.set_date_kb();

	// ���� �����ϸ�
	if (!m_Conf.add(temp))
	{
		cout << ColorType::LRed << "\n\t[ERROR] �̹� �ִ� �������Դϴ�." << ColorType::Default << endl;
		_getch();
		return;
	}

	// �޼���
	cout << ColorType::LAqua << "\n\t�߰��Ǿ����ϴ�!" << ColorType::Default << endl;
	_getch();
}

// Conference �޴����� �м���ȸ ����.
void Application::delete_conference()
{
	system("cls");
	cout << endl << endl;
	cout << ColorType::LPurple << "\t< �м���ȸ �޴� :: �м���ȸ ���� >" << ColorType::Default << endl << endl;

	// ����Ʈ�� ����� ���.
	if (m_Conf.is_empty())
	{
		cout << endl << ColorType::LRed << "\t�˻� ����� �����ϴ�." << ColorType::Default << endl;
		_getch();
		return;
	}

	// ���� ��� ���
	kmh::LIterator<ConferenceType> iter;
	for (iter = m_Conf.begin(); iter != m_Conf.end(); ++iter)
	{
		(*iter).display_record();
		cout << endl;
	}

	// ���� �Է¹޾� �ӽ� �����ϱ�.
	ConferenceType temp;
	cout << endl << "\t������ �м���ȸ ������ �����Ͻʽÿ�. " << endl;
	temp.set_title_kb();

	// conference �����ϴ��� Ȯ��
	kmh::LIterator<ConferenceType> siter = m_Conf.find(temp);
	if (siter.is_null())
	{
		cout << endl << ColorType::LRed << "\t[ERROR] �߸��� �м���ȸ ���� �Է�!" << ColorType::Default << endl;
		_getch();
		return;
	}

	if (m_Conf.remove(temp))
		cout << endl << ColorType::LAqua << "\t���� �Ϸ�!" << ColorType::Default << endl;
	else
		cout << endl << ColorType::LRed << "\t[ERROR]���� ����!" << ColorType::Default << endl;
	_getch();
}

// Conference �޴����� �м���ȸ ����.
void Application::replace_conference()
{
	system("cls");
	cout << endl << endl;
	cout << ColorType::LPurple << "\t< �м���ȸ �޴� :: �м���ȸ ���� ���� >" << ColorType::Default << endl << endl;

	// ���� �Է¹޾� �ӽ� �����ϱ�.
	ConferenceType temp;
	temp.set_title_kb();
	temp.set_date_kb();

	if (m_Conf.replace(temp) == false)
	{
		cout << ColorType::LRed << "\n\t[ERROR] ���濡 �����Ͽ����ϴ�." << ColorType::Default << endl;
		_getch();
		return;
	}

	// �޼���
	cout << ColorType::LAqua << "\n\t�����Ͱ� ����Ǿ����ϴ�!" << ColorType::Default << endl;
	_getch();
}

bool Application::select_conference()
{
	system("cls");
	cout << endl << endl;
	cout << ColorType::LPurple << "\t< �м���ȸ �޴� :: �м���ȸ ���� >" << ColorType::Default << endl << endl;

	// ����Ʈ�� ����� ���.
	if (m_Conf.is_empty())
	{
		cout << endl << ColorType::LRed << "\t�˻� ����� �����ϴ�." << ColorType::Default << endl;
		_getch();
		return false;
	}

	// ���� ��� ���
	kmh::LIterator<ConferenceType> iter;
	for (iter = m_Conf.begin(); iter != m_Conf.end(); ++iter)
	{
		(*iter).display_record();
		cout << endl;
	}

	// ���� �Է¹޾� �ӽ� �����ϱ�.
	ConferenceType temp;
	cout << endl << "\t������ �м���ȸ ������ �����Ͻʽÿ�. " << endl;
	temp.set_title_kb();

	// conference �����ϴ��� Ȯ��
	kmh::LIterator<ConferenceType> siter = m_Conf.find(temp);
	if (siter.is_null())
	{
		cout << endl << ColorType::LRed << "\t[ERROR] �߸��� �м���ȸ ���� �Է�!" << ColorType::Default << endl;
		return false;
	}
	else
	{
		m_NowConf = &(*siter);
		cout << ColorType::LAqua << "\n\t�ش� �м���ȸ�� ���õǾ����ϴ�." << ColorType::Default << endl;
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
	cout << ColorType::LPurple << "\t< �� �޴� :: ���Ե� �� ��� ��� >" << ColorType::Default << endl << endl;
	cout << ColorType::LGreen << "\t\t���õ� �м� ��ȸ : " << m_NowConf->get_title()
		<< " ( " << m_NowConf->get_papers()->length() << " )" << ColorType::Default << endl << endl;

	// ���� ����� ���
	if(m_NowConf->get_papers()->is_empty())
	{
		cout << endl << ColorType::LRed << "\t�˻� ����� �����ϴ�." << ColorType::Default << endl;
		_getch();
		return;
	}

	m_NowConf->display_papers();

	cout << endl << ColorType::LGreen << "\t��� ������ ����Ͽ����ϴ�.\n";
	_getch();
}

void Application::display_conf_author()
{
	if (!select_conference())
		return;

	system("cls");
	cout << endl << endl;
	cout << ColorType::LPurple << "\t< �м���ȸ �޴� :: ���� ��� >" << ColorType::Default << endl << endl;

	// ���� ����Ʈ�� �߰��ϱ�.
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

	// ���� ����Ʈ ���
	kmh::LIterator<string> iter4;
	for (iter4 = author_list.begin(); iter4 != author_list.end(); ++iter4)
		cout << *iter4 << endl;

	cout << ColorType::LAqua << "\n\t�ش� �м���ȸ�� ��� ���ڰ� ��µǾ����ϴ�." << ColorType::Default << endl;
	_getch();
}

void Application::add_paper()
{
	system("cls");
	cout << endl << endl;
	cout << ColorType::LPurple << "\t< �� �޴� :: �� �߰� >" << ColorType::Default << endl << endl;
	cout << ColorType::LGreen << "\t\t���õ� �м� ��ȸ : " << m_NowConf->get_title()
		<< " ( " << m_NowConf->get_papers()->length() << " )" << ColorType::Default << endl << endl;

	// ���� �Է¹޾� �ӽ� �����ϱ�
	PaperType* temp = new PaperType;
	temp->set_title_kb();
	temp->set_page_kb();
	temp->set_author_kb();

	cout << ColorType::LAqua 
		<< "\n\t�߰��� �� ������ ������ �Ϸ�Ǿ����ϴ�." << ColorType::Default << endl;

	// �� �߰��ϱ�. (Tree�� �߰� ��, �����͸� ConferenceType�� �߰�.)
	kmh::BTreeNode<PaperType>* temp_node;
	temp_node = m_Paper.add_and_get(*temp);

	if (temp_node == nullptr)
	{
		cout << endl << ColorType::LRed 
			<< "\t[ERROR] �� �߰��� �����Ͽ����ϴ�." << ColorType::Default << endl;
		_getch();
		return;
	}

	m_NowConf->add_paper(temp_node);

	cout << ColorType::LAqua
		<< "\n\t���� �߰��Ǿ����ϴ�!" << ColorType::Default << endl;
	_getch();
}

void Application::delete_paper()
{
	system("cls");
	cout << endl << endl;
	cout << ColorType::LPurple << "\t< �� �޴� :: �� ���� >" << ColorType::Default << endl << endl;
	cout << ColorType::LGreen << "\t\t���õ� �м� ��ȸ : " << m_NowConf->get_title()
		<< " ( " << m_NowConf->get_papers()->length() << " )" << ColorType::Default << endl << endl;

	// ���� �Է¹޾� �ӽ� �����ϱ�
	PaperType temp;
	temp.set_title_kb();

	// �� �����ϱ�.
	kmh::BTreeNode<PaperType>* temp_node = m_Paper.get_node(temp);

	if (temp_node == nullptr)
	{
		cout << endl << ColorType::LRed
			<< "\t[ERROR] �� �߰��� �����Ͽ����ϴ�." << ColorType::Default << endl;
		_getch();
		return;
	}

	m_NowConf->add_paper(temp_node);

	cout << ColorType::LAqua
		<< "\n\t���� �߰��Ǿ����ϴ�!" << ColorType::Default << endl;
	_getch();
}

void Application::replace_paper()
{
}

void Application::display_paper()
{
}

void Application::display_all_conference()
{
	system("cls");
	cout << endl << endl;
	cout << ColorType::LPurple << "\t< �м���ȸ �޴� :: ��� �м���ȸ ��� >" << ColorType::Default << endl << endl;

	// ����Ʈ�� ����� ���.
	if (m_Conf.is_empty())
	{
		cout << endl << ColorType::LRed << "\t�˻� ����� �����ϴ�." << ColorType::Default << endl;
		_getch();
		return;
	}

	// ��� ���
	kmh::LIterator<ConferenceType> iter;
	for (iter = m_Conf.begin(); iter != m_Conf.end(); ++iter)
	{
		(*iter).display_record();
		cout << endl;
	}

	cout << ColorType::LAqua << "\n\t����� ��� ����Ͽ����ϴ�." << ColorType::Default << endl;
	_getch();
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

void Application::user_search_conference_year()
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
