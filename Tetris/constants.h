#pragma once
#include <string>

const int width_field = 20; // Ширина игрового поля
const int height_field = 30; // Высота игрового поля
const int window_width_field = width_field * 2; // Размер в символах(1 клетка = 2 символа)
const int window_height_field = height_field;

// Новый тип данных (Двумерный массив char)
// Хранит символы для вывода на экран
// Игровое поле
typedef char TetrisScreenMap[window_height_field][window_width_field];

// Храним игровое поле с фигурами
typedef char TetrisSavedFieldMap[window_height_field][window_width_field];

// Максимальные размеры фигуры
const int max_shape_width = 4;
const int max_shape_height = 4;

// Символ для обозначения фигуры
const char char_figure = (char)219;
//Пустая клетка
const char char_field = (char)176;
// Приземлившийся объект
const char char_figureDown = (char)178;

// Тип данных для хранения размеров фигуры
typedef char TetrisShapeSize[max_shape_height][max_shape_width];

// Храним список фигур
inline char* listOfShape[]{ 
	(char*)".....**..**.....", // Квадрат
	(char*)"....****........", // Линия
	(char*)"....***..*......", // T
	(char*)".....***.*......", // L
	(char*)".....**.**......" // S
};

const int listOfShapeCount = sizeof(listOfShape) / sizeof(listOfShape[0]);


inline const std::string score_label = "Score:";
