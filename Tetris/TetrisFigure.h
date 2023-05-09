#pragma once
#include "TetrisField.h"
#include "constants.h"
#include <fstream>

class TetrisFigure {
private:
	int x, y;
	TetrisShapeSize vid;
	// ���������� �������� ������
	char turn;
	// ������ ��������� ������ ������ �� ������� ����
	COORD coord[max_shape_width * max_shape_height];
	// ���������� ��� �������� ����������� ������, ���������� �������
	unsigned char coordCnt;
	TetrisField* field = 0; // ��������� �� ������� ����
	void CalcCoord();

public:
	TetrisFigure();
	void Shape(const char* _vid);

	void Position(int _x, int _y);

	// �������� ������ � �������� �����
	void Put(TetrisScreenMap& scr);

	void PutField(TetrisSavedFieldMap& fld);

	// ����������� ������
	bool Move(int dx, int dy);

	int CheckPosition();

	// ���������� �������� ���������
	void setPointerField(TetrisField* _field);
	char getTurn() {
		return turn;
	}
	//�������� ��� �������
	void setTurn(char _turn);
};