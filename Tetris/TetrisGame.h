#pragma once
#include "TetrisScreen.h"
#include "TetrisField.h"
#include "TetrisFigure.h"
#include "UI.h"

using namespace std;
class TetrisGame {
private:
	TetrisScreen screen;
	TetrisField field;
	TetrisFigure figure;
	UI ui;
	
public:
	TetrisGame();
	void Show();
	void PlayerControl();
	void moveAutoShape();
};
