#pragma once
#include <iostream>
#include <Windows.h>
#include "MGameLoop.hpp"

using namespace std;

namespace MuSeoun_Engine
{
	class MConsoleRender
	{
	public:
			MConsoleRender(){}
			~MConsoleRender(){}

			void moveCursor(short x, short y)
			{
				COORD playerPosition = { x, y };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), playerPosition);


			}

			void SetCursorState(bool isActive)
			{
				HANDLE hConsole;
				hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

				CONSOLE_CURSOR_INFO consoleCursorInfo;
				consoleCursorInfo.bVisible = isActive;
				consoleCursorInfo.dwSize = 1;

				SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorInfo);



			}
			void clear() {
				system("cls");
			}

			void drawString(string str) {

				cout << str;
				/*if (isKeyPressed)
				{
					COORD playerPosition;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), playerPosition);
					cout << str;
					isKeyPressed = false;
				}
				*/
			}
	};
}
