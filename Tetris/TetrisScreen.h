#pragma once
#include <iostream>
#include <Windows.h>
#include "constants.h"

class TetrisScreen {
private:
	// Set символ конца строки в -1 элемент
	void SetEnd();
public:
	TetrisScreenMap temp;
	TetrisScreen();
	// Заполнили точками
	void Clear();
	// Вывод на экран
	void Show();

	void setCursorPosition(int x, int y);
};

