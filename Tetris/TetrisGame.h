#pragma once
#include "TetrisScreen.h"
#include "TetrisField.h"
#include "TetrisFigure.h"

using namespace std;
class TetrisGame {
private:
	TetrisScreen screen;
	TetrisField field;
	TetrisFigure figure;
	
public:
	TetrisGame();
	void Show();
	void PlayerControl();
	void moveAutoShape();
};
