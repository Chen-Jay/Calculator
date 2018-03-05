/*此类来源于软件5班祝鹏富同学*/

#include "Console.h"
Console console;


Console::Console(void)
{
	in = GetStdHandle(STD_INPUT_HANDLE);
	out = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(out, &info);
	return;
}
Console::~Console(void)
{
	CloseHandle(in);
	CloseHandle(out);
	return;
}
void Console::setWindowSize(int len, int wid)
{
	COORD position = { len, wid };
	SMALL_RECT sr = { 0, 0, len - 1, wid - 1 };
	SetConsoleWindowInfo(out, true, &sr);
	SetConsoleScreenBufferSize(out, position);
	return;
}
void Console::setWindowTitle(const TCHAR *title)
{
	SetConsoleTitle(title);
	return;
}
void Console::moveCursorTo(int x, int y)
{
	COORD position = { x, y };
	SetConsoleCursorPosition(out, position);
	return;
}
void Console::showCursor(DWORD size)
{
	CONSOLE_CURSOR_INFO cinfo;
	cinfo.dwSize = size;
	cinfo.bVisible = true;
	SetConsoleCursorInfo(out, &cinfo);
	return;
}
void Console::hideCursor(void)
{
	CONSOLE_CURSOR_INFO cinfo;
	cinfo.dwSize = 20;
	cinfo.bVisible = false;
	SetConsoleCursorInfo(out, &cinfo);
	return;
}
void Console::setTextColor(ColorType type, bool intensity)
{
	tColor = 0;
	switch (type)
	{
	case ColorType::RED:
		if (intensity)
			tColor = FOREGROUND_RED
			       | FOREGROUND_INTENSITY;
		else
			tColor = FOREGROUND_RED;
		break;
	case ColorType::BLUE:
		if (intensity)
			tColor = FOREGROUND_BLUE
			       | FOREGROUND_INTENSITY;
		else
			tColor = FOREGROUND_BLUE;
		break;
	case ColorType::GREEN:
		if (intensity)
			tColor = FOREGROUND_GREEN
			       | FOREGROUND_INTENSITY;
		else
			tColor = FOREGROUND_GREEN;
		break;
	case ColorType::PURPLE:
		if (intensity)
			tColor = FOREGROUND_RED
			       | FOREGROUND_BLUE
			       | FOREGROUND_INTENSITY;
		else
			tColor = FOREGROUND_RED
			       | FOREGROUND_BLUE;
		break;
	case ColorType::INDIGO:
		if (intensity)
			tColor = FOREGROUND_BLUE
			       | FOREGROUND_GREEN
			       | FOREGROUND_INTENSITY;
		else
			bColor = FOREGROUND_BLUE
			       | FOREGROUND_GREEN;
		break;
	case ColorType::YELLOW:
		if (intensity)
			tColor = FOREGROUND_RED
			       | FOREGROUND_GREEN
			       | FOREGROUND_INTENSITY;
		else
			tColor = FOREGROUND_RED
			       | FOREGROUND_GREEN;
		break;
	case ColorType::WHITE:
		if (intensity)
			tColor = FOREGROUND_RED
			       | FOREGROUND_BLUE
			       | FOREGROUND_GREEN
			       | FOREGROUND_INTENSITY;
		else
			tColor = FOREGROUND_RED
			       | FOREGROUND_BLUE
			       | FOREGROUND_GREEN;
		break;
	default:
		break;
	}
	SetConsoleTextAttribute(out, tColor | bColor);
	return;
}
void Console::setBackgroundColor(ColorType type, bool intensity)
{
	bColor = 0;
	switch (type)
	{
	case ColorType::RED:
		if (intensity)
			bColor = BACKGROUND_RED
			       | BACKGROUND_INTENSITY;
		else
			bColor = BACKGROUND_RED;
		break;
	case ColorType::BLUE:
		if (intensity)
			bColor = BACKGROUND_BLUE
			       | BACKGROUND_INTENSITY;
		else
			bColor = BACKGROUND_BLUE;
		break;
	case ColorType::GREEN:
		if (intensity)
			bColor = BACKGROUND_GREEN
			       | BACKGROUND_INTENSITY;
		else
			bColor = BACKGROUND_GREEN;
		break;
	case ColorType::PURPLE:
		if (intensity)
			bColor = BACKGROUND_RED
			       | BACKGROUND_BLUE
			       | BACKGROUND_INTENSITY;
		else
			bColor = BACKGROUND_RED
			       | BACKGROUND_BLUE;
		break;
	case ColorType::INDIGO:
		if (intensity)
			bColor = BACKGROUND_BLUE
			       | BACKGROUND_GREEN
			       | BACKGROUND_INTENSITY;
		else
			bColor = BACKGROUND_BLUE
			       | BACKGROUND_GREEN;
		break;
	case ColorType::YELLOW:
		if (intensity)
			bColor = BACKGROUND_RED
			       | BACKGROUND_GREEN
			       | BACKGROUND_INTENSITY;
		else
			bColor = BACKGROUND_RED
			       | BACKGROUND_GREEN;
		break;
	case ColorType::WHITE:
		if (intensity)
			bColor = BACKGROUND_RED
			       | BACKGROUND_BLUE
			       | BACKGROUND_GREEN
			       | BACKGROUND_INTENSITY;
		else
			bColor = BACKGROUND_RED
			       | BACKGROUND_BLUE
			       | BACKGROUND_GREEN;
		break;
	default:
		break;
	}
	SetConsoleTextAttribute(out, tColor | bColor);
	return;
}
bool Console::mouseOperation(int &x, int &y)
{
	DWORD res;
	COORD position;
	INPUT_RECORD record;

	while (true)
	{
		ReadConsoleInput(in, &record, 1, &res);
		if (record.EventType == MOUSE_EVENT)
		{
			position = record.Event.MouseEvent.dwMousePosition;
			GetConsoleScreenBufferInfo(out, &info);
			SetConsoleCursorPosition(out, info.dwCursorPosition);

			switch (record.Event.MouseEvent.dwButtonState)
			{
			case FROM_LEFT_1ST_BUTTON_PRESSED:
				x = position.X;
				y = position.Y;
				return true;
			case RIGHTMOST_BUTTON_PRESSED:
				x = position.X;
				y = position.Y;
				return false;
			default:
				continue;
			}
		}
	}
	return false;
}