#include "TetrisField.h"

TetrisField::TetrisField() {
	Clear();
}

void TetrisField::Clear() {
	memset(field, char_field, sizeof(field)); // Заполняем поле пустыми клетками
}

void TetrisField::Put(TetrisScreenMap& scr) { // Рисуем игровое поле
	for (int i = 0; i < width_field; i++) {
		for (int j = 0; j < height_field; j++) {
			scr[j][i * 2] = scr[j][i * 2 + 1] = field[j][i];
		}
	}
}

bool TetrisField::Burning() {
	// Проходим по полю снизу вверх
	for (int j = height_field - 1; j >= 0; j--) {
		static bool fillLine;
		fillLine = true;
		// Ищем заполненнную строку
		for (int i = 0; i < width_field; i++) {
			if (field[j][i] != char_figureDown)
				fillLine = false;
		}
		// Если строчка есть, то двигаем все, что выше на строчку вниз
		if (fillLine) {
			for (int y = j; y >= 1; y--) {
				memcpy(field[y], field[y - 1], sizeof(field[y]));
			}
			return true;
		}
	}
	return false;
}