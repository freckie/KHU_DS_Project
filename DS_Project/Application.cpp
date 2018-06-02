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
		cout << ColorType::LPurple << "\t< ������ �޴� - �� >" << ColorType::Default << endl;
		cout << ColorType::LGreen << "\t\t���õ� �м� ��ȸ : " << m_NowConf->get_title() 
			<< " (" << m_NowConf->get_papers()->length() << " )" << ColorType::Default << endl << endl;
		cout << "\t1. �� �߰�" << endl;
		cout << "\t2. �� ����" << endl;
		cout << "\t3. �� ���� ����" << endl;
		cout << "\t4. �� ���� ��� ���" << endl;
		cout << "\t9. �ڷΰ���" << endl;
	}
	// �޴� ������ User
	else if (m_Menu == MenuLevel::User)
	{
		cout << endl << endl;
		cout << ColorType::LPurple << "\t< ����� �޴� >" << ColorType::Default << endl << endl;
		cout << "\t1. ��� �м���ȸ ���" << endl;
		cout << "\t2. ��� �� ���" << endl;
		cout << "\t3. ��� �� ���� ���" << endl;
		cout << "\t4. �м���ȸ �˻�" << endl;
		cout << "\t5. �� Ű����� �˻�" << endl;
		cout << "\t6. ���� ��ŷ" << endl;
		cout << "\t9. �ڷΰ���" << endl;
	}

	cout << "\t0. ���α׷� ����" << endl;

	cout << endl << "\t���� >> ";
	cin >> comm;
	cout << endl;

	return comm;
}
