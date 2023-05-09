#include "TetrisGame.h"


int main() {
	char command[1000];

	// mode - �������� ��������� �������, con - ������ �������� ����������� ����, ��������� ������/������ � ��������
	sprintf_s(command, "mode con cols=%d lines=%d", window_width_field, window_height_field);
	system(command);

	srand(time(NULL));

	TetrisGame game;
	while (1) {
		game.PlayerControl();
		game.moveAutoShape();
		game.Show();
		// ���� ������ ������� 'ESCAPE', ����� GetKeyState ����� ������������� �����, � �� ������ �� �����
		if (GetKeyState(VK_ESCAPE) < 0) break; 
		Sleep(50);
	}

	return 0;
}