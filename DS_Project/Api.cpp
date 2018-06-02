#include"Api.h"

using namespace kmh;

// window console ������ ����
void kmh::set_window_size(int col, int line, const char* title)
{
	//�ܼ� â ũ�� ����
	std::string tempstr = "mode con:cols=";
	tempstr += std::to_string(col);
	tempstr += " lines=";
	tempstr += std::to_string(line);
	const char* tempchar = tempstr.c_str();
	system(tempchar);

	//�ܼ� â ���� ����
	tempstr = "title ";
	tempstr += title;
	const char* tempchar2 = tempstr.c_str();
	system(tempchar2);
}

// color ����.
void kmh::set_color(ColorType color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<int>(color));
}

// cout �÷� ����.
std::ostream& kmh::operator<<(std::ostream& ost, const ColorType& color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<int>(color));
	return ost;
}
