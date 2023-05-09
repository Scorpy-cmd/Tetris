#pragma once
#include "TetrisScreen.h"
#include "TetrisField.h"
#include "TetrisFigure.h"
#include "EndScreen.h"

using namespace std;
class TetrisGame {
private:
	TetrisScreen screen;
	TetrisField field;
	TetrisFigure figure;
	EndScreen end_screen;
	
public:
	TetrisGame();
	void Show();
	void PlayerControl();
	void moveAutoShape();
};
