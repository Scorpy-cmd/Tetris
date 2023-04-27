#include "TetrisScreen.h"

TetrisScreen::TetrisScreen() {
	Clear();
}

void TetrisScreen::SetEnd() {
	temp[window_height_field - 1][window_width_field - 1] = '\0';
}

void TetrisScreen::Clear() {
	memset(temp, '.', sizeof(temp));
}

void TetrisScreen::setCursorPosition(int x, int y) {
	COORD coord; // ���������, ������� ������ ���������� � ������� � �������.
	coord.X = x;
	coord.Y = y;
	// ������������� ������ � �������� �����, get- ��������� ����������� ����� ������ 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void TetrisScreen::Show() {
	setCursorPosition(0, 0);
	SetEnd();
	std::cout << temp[0];
}

