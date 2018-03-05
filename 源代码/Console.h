/*此类来源于软件5班祝鹏富同学*/

#ifndef CONSOLE_H
#define CONSOLE_H

#include <Windows.h>
#include <iostream>
using std::cout;


enum class ColorType
{
	BLACK   = 0,
	RED     = 1,
	BLUE    = 2,
	GREEN   = 3,
	PURPLE  = 4,
	INDIGO  = 5,
	YELLOW  = 6,
	WHITE   = 7
};

class Console
{
public:
	Console(void);
	~Console(void);
	void  setWindowSize(int, int);
	void  setWindowTitle(const TCHAR *);
	void  moveCursorTo(int, int);
	void  showCursor(DWORD = 20);
	void  hideCursor(void);
	void  setTextColor(ColorType, bool = false);
	void  setBackgroundColor(ColorType, bool = false);
	bool  mouseOperation(int &, int &);
private:
	HANDLE                      in;
	HANDLE                      out;
	WORD                        tColor;
	WORD                        bColor;
	CONSOLE_SCREEN_BUFFER_INFO  info;
};
extern Console console;

#endif