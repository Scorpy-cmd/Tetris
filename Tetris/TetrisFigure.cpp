#include "TetrisFigure.h"
#include <cstring>
#include <fstream>
#include "TetrisScreen.h"

TetrisFigure::TetrisFigure() {
	memset(this, 0, sizeof(*this)); // Заполняем значение обьекта нулями 
}

void TetrisFigure::Shape(const char* _vid) { // Загружаем форму фигуры
	memcpy(vid, _vid, sizeof(vid)); // Копируем в блок памяти vid из newVid ( переданно)
}

void TetrisFigure::Position(int _x, int _y) { // set Position
	x = _x;
	y = _y;
	CalcCoord();
}

	// Помещаем фигуру в экранный буфер
void TetrisFigure::Put(TetrisScreenMap& scr) {
	for (int i = 0; i < coordCnt; i++) {
		scr[coord[i].Y][coord[i].X * 2] = scr[coord[i].Y][coord[i].X * 2 + 1] = char_figure;
	}
}

void TetrisFigure::PutField(TetrisSavedFieldMap& fld) {
	// Заполняем игровое поле по координатам фигуры
	for (int i = 0; i < coordCnt; i++) {
		fld[coord[i].Y][coord[i].X] = char_figureDown;
	}
}

	// Перемещение фигуры
bool TetrisFigure::Move(int dx, int dy) {
	int oldX = x, oldY = y;
	Position(x + dx, y + dy);

	//После перемещение объекта проверяем его координаты
	int check = CheckPosition();

	if (check >= 1) { // Если вышли за пределы, то возвращаем обратно
		Position(oldX, oldY);
		if (check == 2) { // Если уперлись вниз, значит ничего
			return false;
		}
	}
	return true;
}

int TetrisFigure::CheckPosition() {
	CalcCoord(); // Считаем

	// Если вышли за правую или левую границу возврат
	for (int i = 0; i < coordCnt; i++) {
		if (coord[i].X < 0 || coord[i].X >= width_field) return 1;
	}

	// Если вышли за низ, то оставляем
	for (int i = 0; i < coordCnt; i++) {
		if (coord[i].Y >= height_field || field->field[coord[i].Y][coord[i].X] == char_figureDown) return 2;
	}

	return 0;
}

	// Установили значение указателя
void TetrisFigure::setPointerField(TetrisField* _field) {
	field = _field;
}

	//Крутилка для объекта
void TetrisFigure::setTurn(char _turn) {
	int oldTurn = turn;
	//  Если "_turn" больше 3, то "turn" получает значение 0. Если "_turn" меньше 0, 
	//то "turn" получает значение 3. В противном случае,
	//"turn" присваивается значение "_turn" 
	// Поворот обьекта
	turn = (_turn > 3 ? 0 : (_turn < 0 ? 3 : _turn));

	int check = CheckPosition(); // Проверка на столкновение со стенками
	if (check == 0) return; // OK
	// Если столкнулись с границей, то  пробуем 3 раза подвинуть объект от границ
	if (check == 1) {
		int xx = x;
		int k = (x > (width_field / 2) ? -1 : +1);
		for (int i = 1; i < 3; i++) {
			x += k;
			if (CheckPosition() == 0) return;
		}
		x = xx; // Если все еще сталкиваемся, то возвращаем объект на место
	}
	turn = oldTurn; // Возвращаем предыдущее положение в пространстве
	CalcCoord(); // Пересчитываем координаты
}

	// Считаем координаты
void TetrisFigure::CalcCoord() {
	int xx=0, yy=0;
	coordCnt = 0;
	for (int i = 0; i < max_shape_width; i++) {
		for (int j = 0; j < max_shape_height; j++) {
			if (vid[j][i] == '*') {
				switch (turn) {
				case 0: xx = x + i, yy = y + j; break;
				// Поворот на 90 градусов
				case 1: xx = x + (max_shape_height - j - 1), yy = y + i; break;
				// Поворот на 180 градусов
				case 2: xx = x + (max_shape_width - i - 1), yy = y + (max_shape_height - j - 1); break;
				// Поворот на 270 градусов
				case 3: xx = x + j, yy = y + (max_shape_width - i - 1); break;
				}
				// Создаем анонимный объект, который присваиваем coord.
				//static_cast- Приводим к типу short,
				coord[coordCnt] = { static_cast<short>(xx), static_cast<short>(yy) };

				coordCnt++;
			}
		}
	}
}
