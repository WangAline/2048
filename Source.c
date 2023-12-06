#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>  
#include <math.h>

void ShowGame(int game[4][4])
{
	printf("\n");
	printf("            *************************\n");
	for (int i = 0; i < 4; i++)
	{
		printf("            |");
		for (int j = 0; j < 4; j++) 
		{
			if (game[i][j] == 0) 
			{
				printf("     |");
			}
			else if(game[i][j]<10 && game[i][j]>0)
			{
				printf("  %d  |",game[i][j]);
			}
			else if (game[i][j] < 100 && game[i][j]>9)
			{
				printf(" %d  |", game[i][j]);
			}
			else if(game[i][j]<1000 && game[i][j]>99)
			{
				printf(" %d |", game[i][j]);
			}
			else
			{
				printf("%d |", game[i][j]);
			}
		}

		printf("\n");
		printf("            *************************\n");
	}
	printf("\n");
}

int AddValue() 
{
	int value;
	if (rand() % 10 == 0)
	{
		value = 4;
	}
	else
	{
		value = 2;
	}
	return value;
}

int SpotValue() 
{
	return rand() % 4;
}

void SetupGame(int game[4][4])
{
	int row = SpotValue();
	int column = SpotValue();
	game[row][column] = AddValue();
	int i;
	int j;
	do
	{
		i = SpotValue();
		j = SpotValue();

	} while (i == row && j == column);
	game[i][j] = AddValue();
}

int Down(int game[4][4], int score)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j > 0; j--)
		{
			for (int k = j; k > 0; k--)
			{
				if (game[k][i] == 0)
				{
					game[k][i] = game[k - 1][i];
					game[k - 1][i] = 0;
				}
			}
		}

		for (int j = 3; j > 0; j--)
		{
			if (game[j][i] == game[j-1][i])
			{
				game[j][i] = game[j][i] + game[j-1][i];
				score += game[j][i];
				game[j-1][i] = 0;
			}
		}

		for (int j = 3; j > 0; j--)
		{
			for (int k = j; k > 0; k--)
			{
				if (game[k][i] == 0)
				{
					game[k][i] = game[k - 1][i];
					game[k - 1][i] = 0;
				}
			}
		}

	}
	return score;
}

int Up(int game[4][4],int score)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = j; k < 3; k++)
			{
				if (game[k][i] == 0)
				{
					game[k][i] = game[k+1][i];
					game[k+1][i] = 0;
				}
			}
		}

		for (int j = 0; j < 3; j++)
		{
			if (game[j][i] == game[j+1][i])
			{
				game[j][i] = game[j][i] + game[j+1][i];
				score += game[j][i];
				game[j+1][i] = 0;
			}
		}

		for (int j = 0; j < 3; j++)
		{
			for (int k = j; k < 3; k++)
			{
				if (game[k][i] == 0)
				{
					game[k][i] = game[k + 1][i];
					game[k + 1][i] = 0;
				}
			}
		}
	}
	return score;
}

int Left(int game [4][4], int score)
{
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = j; k < 3; k++) 
			{
				if (game[i][k] == 0) 
				{
					game[i][k] = game[i][k + 1];
					game[i][k + 1] = 0;
				}
			}
		}

		for (int j = 0; j < 3; j++) 
		{
			if (game[i][j] == game[i][j + 1]) 
			{
				game[i][j] = game[i][j] + game[i][j + 1];
				score += game[i][j];
				game[i][j + 1] = 0;
			}
		}
		
		for (int j = 0; j < 3; j++)
		{
			for (int k = j; k < 3; k++)
			{
				if (game[i][k] == 0)
				{
					game[i][k] = game[i][k + 1];
					game[i][k + 1] = 0;
				}
			}
		}
		
	}
	return score;
}

int Right(int game[4][4],int score)
{
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 3; j >0; j--)
		{
			for (int k = j; k > 0; k--) 
			{
				if (game[i][k] == 0) 
				{
					game[i][k] = game[i][k - 1];
					game[i][k - 1] = 0;
				}
			}
		}

		for (int j = 3; j >0; j--)
		{
			if (game[i][j] == game[i][j - 1]) 
			{
				game[i][j] = game[i][j] + game[i][j - 1];
				score += game[i][j];
				game[i][j - 1] = 0;
			}
		}
		
		for (int j = 3; j > 0; j--)
		{
			for (int k = j; k > 0; k--)
			{
				if (game[i][k] == 0)
				{
					game[i][k] = game[i][k - 1];
					game[i][k - 1] = 0;
				}
			}
		}
		
	}
	return score;
}

void OneValue(int game[4][4])
{
	int row;
	int column;
	do 
	{
		row = SpotValue();
		column = SpotValue();
	} while (game[row][column] != 0);

	game[row][column] = AddValue();
}

bool Win(int game[4][4])
{
	bool win = false;
	for (int i = 0; i < 4 && win == false; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (game[i][j] == 2048)
			{
				printf("YOU WON! You get 2048!!!\n");
				win = true;
			}
		}
	}
	return win;
}

bool Lose(int game[4][4])
{
	bool lose = true;

	for (int i = 0; i < 4 && lose==true; i++)
	{
		for (int j = 0; j < 4; j++) 
		{
			if (game[i][j] == 0)
			{
				lose = false;
			}
		}
	}

	if (lose == true) 
	{
		for (int i = 0; i < 4 && lose == true; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = j; k < 3; k++) 
				{
					if (game[i][k] == game[i][k + 1]) 
					{
						lose = false;
					}
					if (lose == true) 
					{
						if (game[k][i] == game[k + 1][i]) 
						{
							lose = false;
						}
					}
				}
			}
		}
	}
	
	if (lose == true) 
	{
		printf("You lost! \n ");
	}

	return lose;
}

void CopyArray(int game[4][4], int copy[4][4])
{
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++) 
		{
			copy[i][j] =game[i][j];
		}
	}
}

bool CheckMove (int game[4][4], int copy[4][4])
{
	bool check = false;
	for (int i = 0; i < 4 && check==false; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (copy[i][j] != game[i][j]) 
			{
				check = true;
			}
			
		}
	}
	return check;
}

void main()
{

	srand(time(NULL));
	printf("*************************2048**************************\n");
	printf("  To win this game, one box must have the value 2048\n\n ");
	int game[4][4] = { 0 };
	int copy[4][4] = { 0 };
	int score = 0;

	SetupGame(game);
	ShowGame(game);

	bool win=false;
	bool lose = false;
	bool move;
	while (!win && !lose)
	{
		char movement;
		do 
		{
			printf("  Input z (=Up), q (=Left), s(=Down) or d (=Right)\n");
			scanf_s(" %c", &movement);

		} while (movement != 'z' && movement != 'q' && movement != 's' && movement != 'd');

		CopyArray(game,copy);
		
		switch (movement)
		{
			case 'z':
				score=Up(game,score);
				
				break;

			case 'q':
				score=Left(game,score);
				break;

			case 's':
				score=Down(game,score);
				break;

			case 'd':
				score=Right(game,score);
				break;

			default:
				break;
		}

		move = CheckMove(game,copy);
		if (move == true) 
		{
			OneValue(game);
		}
		
		ShowGame(game);
		printf("Score = %d\n\n", score);

		win = Win(game);
		lose = Lose(game);
		printf("-------------------------------------------------- \n\n");
	}
	
}