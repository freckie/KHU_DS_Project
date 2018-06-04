#include"Api.h"

using namespace kmh;

// window console 사이즈 설정
void kmh::set_window_size(int col, int line, const char* title)
{
	//콘솔 창 크기 설정
	std::string tempstr = "mode con:cols=";
	tempstr += std::to_string(col);
	tempstr += " lines=";
	tempstr += std::to_string(line);
	const char* tempchar = tempstr.c_str();
	system(tempchar);

	//콘솔 창 제목 설정
	tempstr = "title ";
	tempstr += title;
	const char* tempchar2 = tempstr.c_str();
	system(tempchar2);
}

void kmh::set_scroll_visible(int col, int line, bool visible)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size;
	// 스크롤바 보이지 않게 세팅했을 경우
	if (!visible)
	{
		new_size =
		{
			info.srWindow.Right - info.srWindow.Left + 1,
			info.srWindow.Bottom - info.srWindow.Top + 1
		};
	}
	else
	{
		new_size =
		{
			static_cast<SHORT>(col),
			static_cast<SHORT>(line + 100)
		};
	}
	SetConsoleScreenBufferSize(handle, new_size);
}

// color 설정.
void kmh::set_color(ColorType color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<int>(color));
}

// cout 컬러 변경.
std::ostream& kmh::operator<<(std::ostream& ost, const ColorType& color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<int>(color));
	return ost;
}
