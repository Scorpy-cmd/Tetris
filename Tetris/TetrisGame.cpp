#include "TetrisGame.h"

TetrisGame::TetrisGame() {
	figure.setPointerField(&field);
	figure.Shape(listOfShape[rand() % listOfShapeCount]);
	figure.Position(width_field / 2 - max_shape_width / 2, 0);
}

void TetrisGame::Show() {
	screen.Clear();
	switch (ui.state) {
	// состояние "стартовый экран"
	case 0:
		ui.PutStartScreen(screen.temp);
		break;
	// состояние "конечный экран"
	case 1:
		ui.PutEndScreen(screen.temp);
		break;
	// состояние "игра"
	case 2:
		field.Put(screen.temp);
		figure.Put(screen.temp);
		ui.PutScore(screen.temp);
		break;
	}
	screen.Show();
}

void TetrisGame::PlayerControl() { // Управление

	static unsigned char turn = 0;
	if (GetKeyState('W') < 0) {
		if (turn == 0) figure.setTurn(figure.getTurn() + 1), turn++;
	}
	if (GetKeyState('W') >= 0) turn = 0;

	if (GetKeyState('S') < 0) figure.Move(0, 1); // Вниз
	if (GetKeyState('A') < 0) figure.Move(-1, 0); // Влево
	if (GetKeyState('D') < 0) figure.Move(1, 0); // Вправо
	
	// по нажатии кнопки R игра переходит в состояние "игры"
	if (ui.state < 2) {
		if (GetKeyState('R') < 0) ui.state = 2, ui.reset();
	}
}

void TetrisGame::moveAutoShape() {
	if (ui.state < 2) return;
	static unsigned char tick = 0;
	tick++;

	if (tick >= 5) {
		if (!figure.Move(0, 1)) {
			// Если достигли дна, создаём новую фигуру
			figure.PutField(field.field);
			figure.Shape(listOfShape[rand() % listOfShapeCount]);
			figure.Position(width_field / 2 - max_shape_width / 2, 0);

			// Если новая фигура с чем то сталкиваеся, значит конец игры
			if (figure.CheckPosition() > 0) {
				field.Clear();
				// переводим игру в состояние "конечный экран"
				ui.state = 1;
			}
		}
		if (field.Burning()) {
			// если убрали линию, увеличиваем счётчик на 1
			ui.increaseScore(1);
		}
		tick = 0;
	}
}