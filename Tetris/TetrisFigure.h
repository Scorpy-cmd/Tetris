#pragma once
#include "TetrisField.h"
#include "constants.h"
#include <fstream>

class TetrisFigure {
private:
	int x, y;
	TetrisShapeSize vid;
	// Переменная поворота клетки
	char turn;
	// Массив координат клеток фигуры на игровом полу
	COORD coord[max_shape_width * max_shape_height];
	// Переменная для хранения куоличества клеток, занимаемых фигурой
	unsigned char coordCnt;
	TetrisField* field = 0; // Указатель на игровое поле
	void CalcCoord();

public:
	TetrisFigure();
	void Shape(const char* _vid);

	void Position(int _x, int _y);

	// Помещаем фигуру в экранный буфер
	void Put(TetrisScreenMap& scr);

	void PutField(TetrisSavedFieldMap& fld);

	// Перемещение фигуры
	bool Move(int dx, int dy);

	int CheckPosition();

	// Установили значение указателя
	void setPointerField(TetrisField* _field);
	char getTurn() {
		return turn;
	}
	//Крутилка для объекта
	void setTurn(char _turn);
};