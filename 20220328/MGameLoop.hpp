#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <Windows.h>
#include "MConsolUtill.hpp"

using namespace std;

namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private:
		bool _isGameRunning;
		MConsoleRender cRenderer;

	public:
		MGameLoop()
		{
			_isGameRunning = false;
		}
		~MGameLoop(){}

		void run()
		{
			_isGameRunning = true;

			Initialize();

			while (_isGameRunning)
			{
				Input();
				Update();
				Render();
			}

			Release();
		}

		void stop()
		{
			_isGameRunning = false;
		}

	private:

		int playerCoordX, playerCoordY;
		bool isKeyPressed;

		void Initialize()
		{
			playerCoordX = 0;
			playerCoordY = 0;
			isKeyPressed = false;
		}

		void Input()
		{
			if (GetAsyncKeyState(VK_RIGHT) == -0x8000 || GetAsyncKeyState(VK_RIGHT) == -0x8001)
			{
				playerCoordX++;
				isKeyPressed = true;
			}
			if(GetAsyncKeyState(VK_DOWN) == -0x8000 || GetAsyncKeyState(VK_DOWN) == -0x8001)
			{
				playerCoordY++;
				isKeyPressed = true;
			}
		}
		void Update()
		{

		}
		void Render()
		{
			chrono::system_clock::time_point startRenderTimePoint = chrono::system_clock::now();
			
			cRenderer.clear();

			cRenderer.moveCursor(10, 20);

			chrono::duration<double> renderDuration = chrono::system_clock::now() - startRenderTimePoint;
			
			//cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;

			string fps = "FPS: " + to_string((int)(1/renderDuration.count()));
			cRenderer.drawString(fps);

			int remainingFrameTime = 100 - (int)(renderDuration.count()*1000.0);
			if (remainingFrameTime > 0)
				this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));
		}

		void Release()
		{

		}

	private: //게임 사용 함수
		
	};
}