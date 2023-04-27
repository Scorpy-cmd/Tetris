#include "TetrisGame.h"

TetrisGame::TetrisGame() {
	figure.setPointerField(&field);
	figure.Shape(listOfShape[rand() % listOfShapeCount]);
	figure.Position(width_field / 2 - max_shape_width / 2, 0);
}

void TetrisGame::Show() {
	screen.Clear();
	field.Put(screen.temp);
	figure.Put(screen.temp);
	screen.Show();
}

void TetrisGame::PlayerControl() { // Управление
	static int turn = 0;
	if (GetKeyState('W') < 0) turn += 1;
	if (turn == 1) figure.setTurn(figure.getTurn() + 1), turn++;
	if (GetKeyState('W') >= 0) turn = 0;

	if (GetKeyState('S') < 0) figure.Move(0, 1); // Вниз
	if (GetKeyState('A') < 0) figure.Move(-1, 0); // Влево
	if (GetKeyState('D') < 0) figure.Move(1, 0); // Вправо
}

void TetrisGame::moveAutoShape() {
	static int tick = 0;
	tick++;
	if (tick >= 5) {
		if (!figure.Move(0, 1)) { // Если достигли дна, значит новая фигура
			figure.PutField(field.field);
			figure.Shape(listOfShape[rand() % listOfShapeCount]);
			figure.Position(width_field / 2 - max_shape_width / 2, 0);

			// Если новая фигура с чем то сталкивает, значит новая игра
			if (figure.CheckPosition() > 0) {
				field.Clear();
			}
		}
		field.Burning();
		tick = 0;
	}
}