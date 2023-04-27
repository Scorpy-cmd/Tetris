#pragma once

const int width_field = 20; // ������ �������� ����
const int height_field = 30; // ������ �������� ����
const int window_width_field = width_field * 2; // ������ � ��������(1 ������ = 2 �������)
const int window_height_field = height_field;

// ����� ��� ������ (��������� ������ char)
// ������ ������� ��� ������ �� �����
// ������� ����
typedef char TetrisScreenMap[window_height_field][window_width_field];

// ������ ������� ���� � ��������
typedef char TetrisSavedFieldMap[window_height_field][window_width_field];

// ���� ������� ������
const int max_shape_width = 4;
const int max_shape_height = 4;

// ������ ��� ����������� ������
const char char_figure = (char)219;
//������ ������
const char char_field = (char)176;
// �������������� ������
const char char_figureDown = (char)178;

// ��� ������ ��� �������� �������� ������
typedef char TetrisShapeSize[max_shape_height][max_shape_width];

// __declspec(selectany) - ����� ������ ������� LNK2005
__declspec(selectany) char* listOfShape[]{ // ������ ������ �����
	(char*)".....**..**.....", // �������
	(char*)"....****........", // �����
	(char*)"....***..*......", // T
	(char*)".....***.*......", // L
	(char*)".....**.**......" // S
};

const int listOfShapeCount = sizeof(listOfShape) / sizeof(listOfShape[0]);


