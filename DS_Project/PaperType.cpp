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
}

void PaperType::set_author_kb()
{
}

void PaperType::set_page_kb()
{
}

void PaperType::display_title()
{
}

void PaperType::display_author()
{
}

void PaperType::display_page()
{
}

bool operator>(const PaperType & lhs, const PaperType & rhs)
{
	return false;
}

bool operator<(const PaperType & lhs, const PaperType & rhs)
{
	return false;
}

bool operator==(const PaperType & lhs, const PaperType & rhs)
{
	return false;
}

bool operator!=(const PaperType & lhs, const PaperType & rhs)
{
	return false;
}
