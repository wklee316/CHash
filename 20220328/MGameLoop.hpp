#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <Windows.h>
#include "MConsolUtill.hpp"
#include "Player.hpp"

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
		int blockX, blockY;
		bool isKeyPressed;

		void Initialize()
		{
			playerCoordX = 40;
			playerCoordY = 10;
			blockX = 60;
			blockY = 10;
			isKeyPressed = false;
		}

		void Input()
		{
			if (GetAsyncKeyState(VK_SPACE) == -0x8000 || GetAsyncKeyState(VK_SPACE) == -0x8001)
			{
				if (playerCoordY == 10) {
					playerCoordY -= 5;
				}
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

			cRenderer.moveCursor(playerCoordX, playerCoordY);

			chrono::duration<double> renderDuration = chrono::system_clock::now() - startRenderTimePoint;
			
			//cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;

			playerGra();
			cRenderer.drawString("X");
			blockMove();
			cRenderer.moveCursor(blockX, blockY);
			cRenderer.drawString("▦");
			collisionC();

			int remainingFrameTime = 100 - (int)(renderDuration.count()*1000.0);
			if (remainingFrameTime > 0)
				this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));
		}

		void Release()
		{

		}

	private: //게임 사용 함수
		void playerGra() {
			if (playerCoordY < 10)
				playerCoordY++;
		}

		void blockMove() {
			if (blockX < 0)
				blockX = 60;
			blockX--;
		}

		void collisionC() {
			if (playerCoordX == blockX && playerCoordY == blockY)
			{
				cRenderer.moveCursor(0, 0);
				cRenderer.drawString("아야!");
				blockX = 60;
				this_thread::sleep_for(chrono::milliseconds(1000));
			}
		}
	};
}