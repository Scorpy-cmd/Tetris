#pragma once
#include "constants.h"

class UI {
private:
	long long int score;
	std::string temp;
	int x;
	int y;
public:
	char state;

	UI();

	void PutStartScreen(TetrisScreenMap& scr);

	void PutScore(TetrisScreenMap& scr);
	void increaseScore(int _score) { score += _score; }

	void PutEndScreen(TetrisScreenMap& scr);

	void PutBottomPanel(TetrisScreenMap& scr);

	void reset() { score = 0; temp = ""; }
};
