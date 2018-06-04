#pragma once

#ifndef _API_H
#define _API_H

#include<string>
#include<iostream>
#include<Windows.h>

namespace kmh
{
	/**
	*	���� enum.
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
	*	@brief	window console â�� ũ�� �� �̸��� �����Ѵ�.
	*	@pre	����.
	*	@post	window console â�� ���õȴ�.
	*	@param	col		console â�� �� �� (int)
	*	@param	line	console â�� �� �� (int)
	*	@param	title	console â�� ���� (char*)
	*/
	void set_window_size(int col, int line, const char* title);

	/**
	*	@brief	window console â�� ��ũ�ѹٸ� �����Ѵ�.
	*	@pre	����.
	*	@post	window console â�� ��ũ�ѹٰ� ���õȴ�.
	*	@param	col		console â�� �� �� (int)
	*	@param	line	console â�� �� �� (int)
	*	@param	visible	��ũ�ѹ� ����.
	*/
	void set_scroll_visible(int col, int line, bool visible);

	/**
	*	@brief	�ܼ� ����� ������ �����Ѵ�.
	*	@pre	����.
	*	@post	�ܼ� ����� ������ ����ȴ�.
	*	@param	color	ColorType�� �÷�.
	*/
	void set_color(ColorType color);

	/**
	*	@brief	cout ��¿��� �ܼ��� ������ �����Ѵ�.
	*	@pre	����.
	*	@post	�ܼ� ����� ������ ����ȴ�.
	*	@param	ost	cout (std::ostream)
	*	@param	color	���� (ColorType)
	*/
	std::ostream& operator<<(std::ostream& ost, const ColorType& color);
}

#endif _API_H