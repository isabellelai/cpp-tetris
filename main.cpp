#include "raylib.h"
#include "game.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

int main() 
{
	InitWindow(500, 620, "Bootleg Tetris");
	SetTargetFPS(60);

	Font font = LoadFontEx("Font/PressStart2P.ttf", 64, 0, 0);

	Game game = Game();

	while(WindowShouldClose() == false)
	{
		game.HandleInput();
		if (EventTriggered(0.3))
		{
			game.MoveBlockDown();
		}
		BeginDrawing();
		ClearBackground(darkBlue);
		DrawTextEx(font, "Score", { 360, 15 }, 34, 2, WHITE);
		DrawTextEx(font, "Next", { 370, 175 }, 34, 2, WHITE);
		if (game.gameOver)
		{
			DrawTextEx(font, "GAME OVER", { 320, 450 }, 28, 2, WHITE);
		}
		DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, lightBlue);

		char scoreText[10];
		sprintf_s(scoreText, "%d", game.score);
		Vector2 textSize = MeasureTextEx(font, scoreText, 34, 2);

		DrawTextEx(font, scoreText, { 320 + (170 - textSize.x)/2, 70 }, 34, 2, WHITE);
		DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, lightBlue);
		game.Draw();
		EndDrawing();
	}

	CloseWindow();
}