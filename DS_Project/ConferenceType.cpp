#include "ConferenceType.h"

ConferenceType::ConferenceType()
{
	m_Title = "";
	m_Date = "";
	m_YDate = -1;
	m_MDate = -1;
	m_DDate = -1;
	m_Papers = new kmh::List<kmh::BTreeNode<PaperType>*>();
}

ConferenceType::~ConferenceType()
{
	if(m_Papers->length() > 0)
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

void ConferenceType::set_title_kb()
{
	cout << "\t�м���ȸ ���� : ";
	cin >> m_Title;
	cout << endl;
}

void ConferenceType::set_date_kb()
{
	cout << "\t�м���ȸ ���� : ";
	cin >> m_Date;
	cout << endl;

	set_date(m_Date);
}

void ConferenceType::add_paper(kmh::BTreeNode<PaperType> * paper)
{
	m_Papers->add(paper);
}

void ConferenceType::display_title()
{
	cout << "\t�м���ȸ ���� : " << m_Title << endl;
}

void ConferenceType::display_date()
{
	cout << "\t�м���ȸ ���� : " << m_Date << endl;
}

void ConferenceType::display_papers()
{
	cout << "\t���Ե� �� : ";

	for (auto iter = m_Papers->begin(); iter != m_Papers->end(); ++iter)
		cout << (*iter)->data.get_title() << " ";

	cout << endl;
}

void ConferenceType::display_record()
{
	cout << "\t< �м���ȸ ���� >\n\n";
	display_title();
	display_date();
	
	cout << "\t���Ե� �� ( " << m_Papers->length() << " )\n";
	// ���� �ִ� ��츸 ���.
	if(m_Papers->length() != 0)
		for (auto iter = m_Papers->begin(); iter != m_Papers->end(); ++iter)
			cout << "\t\t" << (*iter)->data.get_title() << endl;
	
	cout << endl;
}

kmh::LIterator<kmh::BTreeNode<PaperType>*> ConferenceType::find_paper(string paper_title)
{
	for (auto iter = m_Papers->begin(); iter != m_Papers->end(); ++iter)
		if ((*iter)->data.get_title() == paper_title)
			return kmh::LIterator<kmh::BTreeNode<PaperType>*>(iter);

	// ��ġ�ϴ� ����� ���� ��� �� iterator ����.
	return kmh::LIterator<kmh::BTreeNode<PaperType>*>(nullptr);
}

kmh::LIterator<kmh::BTreeNode<PaperType>*> ConferenceType::find_paper(PaperType & paper)
{
	for (auto iter = m_Papers->begin(); iter != m_Papers->end(); ++iter)
		if ((*iter)->data.get_title() == paper.get_title())
			return kmh::LIterator<kmh::BTreeNode<PaperType>*>(iter);

	// ��ġ�ϴ� ����� ���� ��� �� iterator ����.
	return kmh::LIterator<kmh::BTreeNode<PaperType>*>(nullptr);
}

void ConferenceType::search_paper(string keyword)
{
	bool is_found = false;

	cout << "\t< �� �˻� ��� > " << endl;
	for (auto iter = m_Papers->begin(); iter != m_Papers->end(); ++iter)
	{
		if ((*iter)->data.get_title().find(keyword) != string::npos)
		{
			cout << endl;
			(*iter)->data.display_record();
			is_found = true;
		}
	}

	// ���� �˻� ��� ���ٸ�
	if (!is_found)
		cout << "\t�˻� ��� ����." << endl;
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
