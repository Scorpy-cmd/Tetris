#pragma once
#include <iostream>
#include <Windows.h>
//#include <cstring>
#include "constants.h"

class TetrisScreen {
private:
	// Set ������ ����� ������ � -1 �������
	void SetEnd();
public:
	TetrisScreenMap temp;
	TetrisScreen();
	// ��������� �������
	void Clear();
	// ����� �� �����
	void Show();

	void setCursorPosition(int x, int y);
};

