#include "UI.h"

UI::UI() :state(0), score(0), temp(""), x(window_width_field / 2), y(window_height_field / 2) {}

void UI::PutStartScreen(TetrisScreenMap& scr) {

	for (int i = 0; i < welcome_label.size(); i++) {
		scr[3][x - welcome_label.size() / 2 + i] = welcome_label[i];
	}

	for (int i = 0; i < instructionsCount; i++) {
		for (int j = 0; j < instructions[i].size(); j++) {
			scr[y - instructionsCount / 2 + i][x - instructions[i].size() / 2 - 1 + j] = instructions[i][j];
		}
	}

	PutBottomPanel(scr);
}

void UI::PutScore(TetrisScreenMap& scr) {
	for (int i = 0; i < score_label.size(); i++) {
		scr[0][i] = score_label[i];
	}
	temp = std::to_string(score);
	for (int i = 0; i < temp.size(); i++) {
		scr[1][i] = temp[i];
	}
}

void UI::PutEndScreen(TetrisScreenMap& scr) {

	for (int i = 0; i < end_screen_label.size(); i++) {
		scr[y/2][x - end_screen_label.size() / 2 + i] = end_screen_label[i];
	}

	temp = end_screen_score_label + std::to_string(score);
	for (int i = 0; i < temp.size(); i++) {
		scr[y][x - temp.size() / 2 + i] = temp[i];
	}

	PutBottomPanel(scr);
}

void UI::PutBottomPanel(TetrisScreenMap& scr) {
	for (int i = 0; i < start_game_label.size(); i++) {
		scr[y * 2 - 4][x - start_game_label.size() / 2 + i] = start_game_label[i];
	}
	for (int i = 0; i < start_game_label1.size(); i++) {
		scr[y * 2 - 3][x - start_game_label1.size() / 2 + i] = start_game_label1[i];
	}
	for (int i = 0; i < exit_game_label.size(); i++) {
		scr[y * 2 - 2][x - exit_game_label.size() / 2 + i] = exit_game_label[i];
	}
}