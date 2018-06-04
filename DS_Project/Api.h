#pragma once

#ifndef _API_H
#define _API_H

#include<string>
#include<iostream>
#include<Windows.h>

namespace kmh
{
	/**
	*	색깔 enum.
	*/
	enum class ColorType
	{
		Default = 0x0007,
		Black = 0x0000,
		Blue = 0x0001,
		Green = 0x0002,
		Aqua = 0x0003,
		Red = 0x0004,
		Purple = 0x0005,
		Yellow = 0x0006,
		White = 0x0007,
		Gray = 0x0008,
		LBlue = 0x0009,
		LGreen = 0x000A,
		LAqua = 0x000B,
		LRed = 0x000C,
		LPurple = 0x000D,
		LYellow = 0x000E,
		BWhite = 0x000F
	};

	/**
	*	@brief	window console 창의 크기 및 이름을 설정한다.
	*	@pre	없음.
	*	@post	window console 창이 세팅된다.
	*	@param	col		console 창의 열 수 (int)
	*	@param	line	console 창의 행 수 (int)
	*	@param	title	console 창의 제목 (char*)
	*/
	void set_window_size(int col, int line, const char* title);

	/**
	*	@brief	window console 창의 스크롤바를 세팅한다.
	*	@pre	없음.
	*	@post	window console 창의 스크롤바가 세팅된다.
	*	@param	col		console 창의 열 수 (int)
	*	@param	line	console 창의 행 수 (int)
	*	@param	visible	스크롤바 상태.
	*/
	void set_scroll_visible(int col, int line, bool visible);

	/**
	*	@brief	콘솔 출력의 색깔을 변경한다.
	*	@pre	없음.
	*	@post	콘솔 출력의 색깔이 변경된다.
	*	@param	color	ColorType의 컬러.
	*/
	void set_color(ColorType color);

	/**
	*	@brief	cout 출력에서 콘솔의 색깔을 변경한다.
	*	@pre	없음.
	*	@post	콘솔 출력의 색깔이 변경된다.
	*	@param	ost	cout (std::ostream)
	*	@param	color	색깔 (ColorType)
	*/
	std::ostream& operator<<(std::ostream& ost, const ColorType& color);
}

#endif _API_H