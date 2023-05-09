#include "TetrisGame.h"


int main() {
	char command[1000];

	// mode - изменяем параметры системы, con - меняем свойство консольного окна, указываем ширину/высоту в символах
	sprintf_s(command, "mode con cols=%d lines=%d", window_width_field, window_height_field);
	system(command);

	srand(time(NULL));

	TetrisGame game;
	while (1) {
		game.PlayerControl();
		game.moveAutoShape();
		game.Show();
		// Если нажата клавиша 'ESCAPE', метод GetKeyState вернёт отрицательное число, и мы выйдем из цикла
		if (GetKeyState(VK_ESCAPE) < 0) break; 
		Sleep(50);
	}

	return 0;
}