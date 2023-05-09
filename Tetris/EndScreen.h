#pragma once
#include "constants.h"

class EndScreen {
private:
	int score;
	std::string temp;
public:
	EndScreen();

	void PutScore(TetrisScreenMap& scr);
	void increaseScore(int _score) { score += _score; }
};
