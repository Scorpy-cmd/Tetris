#include "EndScreen.h"

EndScreen::EndScreen() :score(0), temp("") {}

void EndScreen::PutScore(TetrisScreenMap& scr) {
	for (int i = 0; i < score_label.size(); i++) {
		scr[0][i] = score_label[i];
	}
	temp = std::to_string(score);
	for (int i = 0; i < temp.size(); i++) {
		scr[1][i] = temp[i];
	}
}