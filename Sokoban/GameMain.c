#include <stdbool.h>
#include <stdlib.h>
#include<stdio.h>
#include<Windows.h>

void DrawMain(int*);
void Player(int* x, int* y, int Map[][5]);
void Move(int*, int*, int, int, int[][5]);
bool Search(int[][5]);

int main(void)
{
	int Map[5][5] = {
	{1,1,1,1,1},
	{1,3,3,4,1},
	{1,2,2,0,1},
	{1,0,0,0,1},
	{1,1,1,1,1}
	};

	int x = 3, y = 1;

	while (!(GetAsyncKeyState(VK_ESCAPE)) && Search(Map)) {
		Player(&x, &y, Map);
		DrawMain(Map[0]);
		Sleep(50);
	}

	printf("���߂łƂ��B�Q�[���N���A�ł�\n");

	return 0;
}



void DrawMain(int* Map) {
	int i, j;
	system("cls");
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++)
		{
			switch (*(Map + i * 5 + j))
			{
			case 0:
				printf("�@");
				break;

			case 1:
				printf("��");
				break;

			case 2:
				printf("�Z");
				break;

			case 3:
				printf("�E");
				break;

			case 4:
				printf("�o");
				break;

			case 5:
				printf("��");
				break;

			case 7:
				printf("�o");
				break;

			default:
				break;
			}

		}
		printf("\n");

	}
	return;

}

void Player(int* x, int* y, int Map[][5]) {
	if (GetAsyncKeyState(VK_LEFT))
		Move(x, y, -1, 0, Map);
	else if (GetAsyncKeyState(VK_RIGHT))
		Move(x, y, 1, 0, Map);
	else if (GetAsyncKeyState(VK_UP))
		Move(x, y, 0, -1, Map);
	else if (GetAsyncKeyState(VK_DOWN))
		Move(x, y, 0, 1, Map);
}

void Move(int* x, int* y, int mx, int my, int Map[][5]) {
	switch (Map[*y + my][*x + mx]) {
	case 0:
		Map[*y + my][*x + mx] += 4;
		Map[*y][*x] -= 4;
		*x += mx;
		*y += my;
		break;

	case 2:
		if (Map[*y + my * 2][*x + mx * 2] == 0 || Map[*y + my * 2][*x + mx * 2] == 3) {
			Map[*y + my * 2][*x + mx * 2] += 2;
			Map[*y + my][*x + mx] -= 2;
			Map[*y + my][*x + mx] += 4;
			Map[*y][*x] -= 4;

			*x += mx;
			*y += my;
		}

			break;

		
	case 3:
		Map[*y + my][*x + mx] += 4;
		Map[*y][*x] -= 4;
		*x += mx;
		*y += my;
		break;

	case 5:
		if (Map[*y + my * 2][*x + mx * 2] == 0 || Map[*y + my * 2][*x + mx * 2] == 3) {
			Map[*y + my * 2][*x + mx * 2] += 2;
			Map[*y + my][*x + mx] -= 2;
			Map[*y + my][*x + mx] += 4;
			Map[*y][*x] -= 4;

			*x += mx;
			*y += my;
		}

		break;


	default:
		break;
	}

}

bool Search(int Map[][5]) {
	int i, j;
	int sw = 0;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			if (Map[i][j] == 2)
				sw = 1;
		}
	}

	if (!sw)
		return false;
	else
		return true;
}