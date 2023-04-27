#pragma once
#include "constants.h"
#include <windows.h>

class TetrisField {
public:
	TetrisSavedFieldMap field; // Игровое поле
	TetrisField();
	void Clear();
	void Put(TetrisScreenMap& scr);
	void Burning();
};