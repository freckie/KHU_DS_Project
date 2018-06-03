#include "PaperType.h"

PaperType::PaperType()
{
	m_Title = "";
	m_SPage = -1;
	m_EPage = -1;
	m_Page = -1;
	m_Author = new kmh::ArrayList<AuthorType>(1);
}

PaperType::~PaperType()
{
	delete m_Author;
}

void PaperType::set_title(string title)
{
	m_Title = title;
}

void PaperType::set_author(kmh::ArrayList<AuthorType>& author)
{
	m_Author = new kmh::ArrayList<AuthorType>(author);
}

void PaperType::set_author(initializer_list<string> init)
{
	m_Author = new kmh::ArrayList<AuthorType>(init.size());
	
	// ��ü ���� �� ����
	AuthorType* ptr = m_Author->data();
	int idx = 0;
	for(auto iter = init.begin(); iter!=init.end(); ++iter)
	{
		ptr[idx] = AuthorType(*iter);
		idx++;
	}
}

void PaperType::set_page(string page)
{
	size_t pos = page.find("-");
	string first = page.substr(0, pos - 0);
	string last = page.substr(pos + 1);

	m_SPage = atoi(first.c_str());
	m_EPage = atoi(last.c_str());
	m_Page = m_EPage - m_SPage + 1;
}

void PaperType::set_title_kb()
{
	cout << "\t�� ���� : ";
	cin >> m_Title;
}

void PaperType::set_author_kb()
{
	int temp;
	cout << "\t���� �� : ";
	cin >> temp;
	cout << endl;

	m_Author->realloc(temp);

	string temp_str;
	AuthorType* temp_ptr = m_Author->data();
	cout << "\t���� �̸�(����� ����) : ";
	for (int i = 0; i < temp; i++)
	{
		cin >> temp_str;
		temp_ptr[i].set_name(temp_str);
	}
}

void PaperType::set_page_kb()
{
	string temp;
	cout << "\t�� ������ : ";
	cin >> temp;

	set_page(temp);
}

void PaperType::display_title()
{
	cout << "\t- �� �̸� : " << m_Title << endl;
}

void PaperType::display_author()
{
	cout << "\t- �� ���� : ";
	for (kmh::AIterator<AuthorType> iter = m_Author->begin(); iter != m_Author->end(); ++iter)
		cout << (*iter).get_name() << " ";

	cout << endl;
}

void PaperType::display_page()
{
	cout << "\t- �� ������ : " << m_SPage
		<< "p ~ " << m_EPage << "p (�� "
		<< m_Page << "p)" << endl;
}

void PaperType::display_record()
{
	cout << "\t< �� ���� >" << endl << endl;
	display_title();
	display_page();
	display_author();
}

bool operator>(const PaperType & lhs, const PaperType & rhs)
{
	return (lhs.m_Title > rhs.m_Title);
}

bool operator<(const PaperType & lhs, const PaperType & rhs)
{
	return (lhs.m_Title < rhs.m_Title);
}

bool operator==(const PaperType & lhs, const PaperType & rhs)
{
	return (lhs.m_Title == rhs.m_Title);
}

bool operator!=(const PaperType & lhs, const PaperType & rhs)
{
	return (lhs.m_Title != rhs.m_Title);
}
