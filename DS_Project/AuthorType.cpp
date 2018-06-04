#include "AuthorType.h"

AuthorType::AuthorType()
{
	m_Name = "noname";
}

AuthorType::AuthorType(const char * _name)
{
	m_Name = string(_name);
}

AuthorType::AuthorType(string _name)
{
	m_Name = move(_name);
}

void AuthorType::set_name_kb()
{
	cout << "\t저자 이름 : ";
	cin >> m_Name;
}

void AuthorType::display_name()
{
	cout << "\t저자 이름 : " << m_Name << endl;
}

bool operator>(const AuthorType & lhs, const AuthorType & rhs)
{
	return (lhs.m_Name > rhs.m_Name);
}

bool operator<(const AuthorType & lhs, const AuthorType & rhs)
{
	return (lhs.m_Name < rhs.m_Name);
}

bool operator==(const AuthorType & lhs, const AuthorType & rhs)
{
	return (lhs.m_Name == rhs.m_Name);
}

bool operator!=(const AuthorType & lhs, const AuthorType & rhs)
{
	return (lhs.m_Name != rhs.m_Name);
}
