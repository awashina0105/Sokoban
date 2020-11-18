#include <stdbool.h>
#include<stdio.h>

void DrawMain(int Map[][5]);

int main(void) 
{
	int Map[5][5] = {
	{1,1,1,1,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,0,0,0,1},
	{1,1,1,1,1}
	};

	
	DrawMain(Map);


	return 0;
}

void DrawMain(int Map[][5]) {
	int i, j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++)
		{
			//printf("%d", Map[i][j]);
		}
		printf("\n");

	}
	return;

}