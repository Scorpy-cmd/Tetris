#include "TetrisFigure.h"
#include <fstream>

TetrisFigure::TetrisFigure() {
	memset(this, 0, sizeof(*this)); // ��������� �������� ������� ������ 
}

void TetrisFigure::Shape(const char* _vid) { // ��������� ����� ������
	memcpy(vid, _vid, sizeof(vid)); // �������� � ���� ������ vid �� newVid (���������)
	turn = 0;
}

// ������������� ���������� ������ �� �����������
void TetrisFigure::Position(int _x, int _y) { 
	x = _x;
	y = _y;
	CalcCoord();
}

// �������� ������ � �������� �����
void TetrisFigure::Put(TetrisScreenMap& scr) {
	for (int i = 0; i < coordCnt; i++) {
		scr[coord[i].Y][coord[i].X * 2] = scr[coord[i].Y][coord[i].X * 2 + 1] = char_figure;
	}
}

void TetrisFigure::PutField(TetrisSavedFieldMap& fld) {
	// ��������� ������� ���� �� ����������� ������
	for (int i = 0; i < coordCnt; i++) {
		fld[coord[i].Y][coord[i].X] = char_figureDown;
	}
}

// ����������� ������
bool TetrisFigure::Move(int dx, int dy) {
	int oldX = x, oldY = y;
	Position(x + dx, y + dy);

	//����� ����������� ������� ��������� ��� ����������
	int check = CheckPosition();

	if (check >= 1) { // ���� ����� �� �������, �� ���������� �������
		Position(oldX, oldY);
		if (check == 2) { // ���� �������� ����, ���������� �������� ���������� �����������
			return false;
		}
	}
	// ���������� �������� �������� �����������
	return true;
}

int TetrisFigure::CheckPosition() {
	CalcCoord(); // ������������� ���������� ������

	for (int i = 0; i < coordCnt; i++) {
		// ���� ����� �� ������ ��� ����� �������, ���������� 1
		if (coord[i].X < 0 || coord[i].X >= width_field) return 1;
		// ���� ����� �� ���, ���������� 2
		if (coord[i].Y >= height_field || field->field[coord[i].Y][coord[i].X] == char_figureDown) return 2;
	}
	// ���� �� ������� �� �����, ���������� 0
	return 0;
}

// ��������� �������� ���������
void TetrisFigure::setPointerField(TetrisField* _field) {
	field = _field;
}

//�������� ��� �������
void TetrisFigure::setTurn(char _turn) {
	int oldTurn = turn;
	// ���� "_turn" ������ 3, �� "turn" �������� �������� 0.
	// � ��������� ������ "turn" ������������� �������� "_turn" 
	// ������� �������
	turn = (_turn > 3 ? 0 : _turn);

	// �������� �� ������������ �� ��������
	int check = CheckPosition(); 

	if (check == 0) return; // OK

	// ���� ����������� � ��������, ��  ������� 3 ���� ��������� ������ �� ������
	if (check == 1) {
		int xx = x;
		// ���� � ������ �������� ����, ������� ����� (-1) ����� ������ (+1)
		int k = (x > (width_field / 2) ? -1 : +1);

		for (int i = 1; i < 3; i++) {
			x += k;
			if (CheckPosition() == 0) return;
		}
		x = xx; // ���� ��� ��� ������������, �� ���������� ������ �� �����
	}
	turn = oldTurn; // ���������� ���������� ��������� � ������������
	CalcCoord(); // ������������� ����������
}

// ������� ����������
void TetrisFigure::CalcCoord() {
	int xx=0, yy=0;
	coordCnt = 0;
	for (int i = 0; i < max_shape_width; i++) {
		for (int j = 0; j < max_shape_height; j++) {
			if (vid[j][i] == '*') {
				switch (turn) {
					case 0: xx = x + i, yy = y + j; break;
					// ������� �� 90 �������� �� ������� �������
					case 1: xx = x + (max_shape_height - j - 1), yy = y + i; break;
					// ������� �� 180 �������� �� ������� �������
					case 2: xx = x + (max_shape_width - i - 1), yy = y + (max_shape_height - j - 1); break;
					// ������� �� 270 �������� �� ������� �������
					case 3: xx = x + j, yy = y + (max_shape_width - i - 1); break;
				}
				// ������� ��������� ������, ������� ����������� coord.
				// static_cast - �������� � ���� short
				coord[coordCnt] = { static_cast<short>(xx), static_cast<short>(yy) };

				coordCnt++;
			}
		}
	}
}
