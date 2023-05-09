#include "TetrisField.h"

TetrisField::TetrisField() {
	Clear();
}

void TetrisField::Clear() {
	memset(field, char_field, sizeof(field)); // ��������� ���� ������� ��������
}

void TetrisField::Put(TetrisScreenMap& scr) { // ������ ������� ����
	for (int i = 0; i < width_field; i++) {
		for (int j = 0; j < height_field; j++) {
			scr[j][i * 2] = scr[j][i * 2 + 1] = field[j][i];
		}
	}
}

bool TetrisField::Burning() {
	// �������� �� ���� ����� �����
	for (int j = height_field - 1; j >= 0; j--) {
		static bool fillLine;
		fillLine = true;
		// ���� ������������ ������
		for (int i = 0; i < width_field; i++) {
			if (field[j][i] != char_figureDown)
				fillLine = false;
		}
		// ���� ������� ����, �� ������� ���, ��� ���� �� ������� ����
		if (fillLine) {
			for (int y = j; y >= 1; y--) {
				memcpy(field[y], field[y - 1], sizeof(field[y]));
			}
			return true;
		}
	}
	return false;
}