#include "ConferenceType.h"

ConferenceType::ConferenceType()
{
	m_Title = "";
	m_Date = "";
	m_YDate = -1;
	m_MDate = -1;
	m_DDate = -1;
	m_Papers = new kmh::List<PaperType*>();
}

ConferenceType::~ConferenceType()
{
	delete m_Papers;
}

void ConferenceType::set_date(string date)
{
	size_t pos = date.find(".");
	string first = date.substr(0, pos - 0);

	size_t pos2 = date.find(".", pos + 1);
	string middle = date.substr(pos + 1, pos2 - pos - 1);

	string last = date.substr(pos2 + 1);

	m_YDate = atoi(first.c_str());
	m_MDate = atoi(middle.c_str());
	m_DDate = atoi(last.c_str());
}

void ConferenceType::add_paper(PaperType * paper)
{
	m_Papers->add(paper);
}

void ConferenceType::display_title()
{
	cout << "\t학술대회 제목 : " << m_Title << endl;
}

void ConferenceType::display_date()
{
	cout << "\t학술대회 개최 : " << m_Date << endl;
}

void ConferenceType::display_papers()
{
	cout << "\t포함된 논문 : ";

	for (auto iter = m_Papers->begin(); iter != m_Papers->end(); ++iter)
		cout << (*iter)->get_title() << " ";

	cout << endl;
}

void ConferenceType::display_record()
{
	cout << "\t< 학술대회 정보 >\n\n";
	display_title();
	display_date();
	
	cout << "\t포함된 논문 ( " << m_Papers->length() << " )\n";
	for (auto iter = m_Papers->begin(); iter != m_Papers->end(); ++iter)
		cout << "\t\t" << (*iter)->get_title() << endl;
	
	cout << endl;
}

kmh::LIterator<PaperType*> ConferenceType::find_paper(string paper_title)
{
	for (auto iter = m_Papers->begin(); iter != m_Papers->end(); ++iter)
		if ((*iter)->get_title() == paper_title)
			return kmh::LIterator<PaperType*>(iter);

	// 일치하는 결과가 없을 경우 빈 iterator 리턴.
	return kmh::LIterator<PaperType*>(nullptr);
}

kmh::LIterator<PaperType*> ConferenceType::find_paper(PaperType & paper)
{
	for (auto iter = m_Papers->begin(); iter != m_Papers->end(); ++iter)
		if ((*iter)->get_title() == paper.get_title())
			return kmh::LIterator<PaperType*>(iter);

	// 일치하는 결과가 없을 경우 빈 iterator 리턴.
	return kmh::LIterator<PaperType*>(nullptr);
}

void ConferenceType::search_paper(string keyword)
{
	bool is_found = false;

	cout << "\t< 논문 검색 결과 > " << endl;
	for (auto iter = m_Papers->begin(); iter != m_Papers->end(); ++iter)
	{
		if ((*iter)->get_title().find(keyword) != string::npos)
		{
			cout << endl;
			(*iter)->display_record();
			is_found = true;
		}
	}

	// 만약 검색 결과 없다면
	if (!is_found)
		cout << "\t검색 결과 없음." << endl;
}

bool operator>(const ConferenceType & lhs, const ConferenceType & rhs)
{
	return (lhs.m_Title > rhs.m_Title);
}

bool operator<(const ConferenceType & lhs, const ConferenceType & rhs)
{
	return (lhs.m_Title < rhs.m_Title);
}

bool operator==(const ConferenceType & lhs, const ConferenceType & rhs)
{
	return (lhs.m_Title == rhs.m_Title);
}

bool operator!=(const ConferenceType & lhs, const ConferenceType & rhs)
{
	return (lhs.m_Title != rhs.m_Title);
}
