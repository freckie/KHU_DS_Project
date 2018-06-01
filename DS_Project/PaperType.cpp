#include "PaperType.h"

PaperType::PaperType()
{
	m_Title = "";
	m_SPage = -1;
	m_EPage = -1;
	m_Page = -1;
}

void PaperType::set_author(kmh::ArrayList<AuthorType>& author)
{
	m_Author.remake(author);
}

void PaperType::set_author(initializer_list<string> init)
{
	// 사이즈 재할당
	m_Author.realloc(init.size());

	// 객체 생성 후 복사
	AuthorType* ptr = m_Author.data();
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
	cout << "\t논문 제목 : ";
	cin >> m_Title;
}

void PaperType::set_author_kb()
{
	int temp;
	cout << "\t저자 수 : ";
	cin >> temp;

	m_Author.realloc(temp);
}

void PaperType::set_page_kb()
{
	string temp;
	cout << "\t논문 페이지 : ";
	cin >> temp;

	set_page(temp);
}

void PaperType::display_title()
{
	cout << "\t논문 이름 : " << m_Title << endl;
}

void PaperType::display_author()
{
	cout << "\t논문 저자 : ";
	for (kmh::AIterator<AuthorType> iter = m_Author.begin(); iter != m_Author.end(); ++iter)
		cout << (*iter).get_name() << " ";

	cout << endl;
}

void PaperType::display_page()
{
	cout << "\t논문 페이지 : " << m_SPage
		<< "p ~ " << m_EPage << "p (총 "
		<< m_Page << "p)" << endl;
}

void PaperType::display_record()
{
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
