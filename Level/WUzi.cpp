#include<iostream>
#include<windows.h>
using namespace std;
struct coord
{
	int x;
	int y;
};

void Updboard(char chess[][16]);
void Updchess(coord step, char chess[][16], int n);
int ChessCheck(char board[][16], coord step, char sign);

int main()
{
	coord step;
	char board[16][16];
	for (int i = 0; i < 16; i++)
	{
		for (int nn = 0; nn < 16; nn++)
		{
			board[i][nn] = '*';
		}
	}

	int count(1);
	Updboard(board);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	count % 2 == 1 ? cout << "O's Turn"  : cout << "X's Turn" ;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	cout << endl;
	while (true)
	{
		cin >> step.x >> step.y;
		if (board[step.x - 1][step.y - 1] != '*')
		{
			cout << "This position has been set" << endl;
			continue;
		}
		Updchess(step, board, count);
		system("cls");
		Updboard(board);
		
		cout << endl;
		if (count % 2 == 1 && ChessCheck(board, step, 'O'))
		{
			cout << "THe O wiN";
			break;
		}
		else if (count % 2 == 0 && ChessCheck(board, step, 'X'))
		{
			cout << "THe X wiN";
			break;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		count % 2 == 1 ? cout << "X's Turn" : cout << "O's Turn";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
		cout << endl;
		count++;
	}


}


void Updboard(char chess[][16])
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_GREEN);
	cout << "X  Y ";
	
	for (int i = 1; i < 17; i++)
	{
		i<11?cout << i<<"   ": cout << i << "  ";
	}
	cout << endl;
	for (int i = 0; i < 16; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);
		if (i + 1 < 10)
		{
			cout << i + 1 << "  ";
		}
		else
		{
			cout << i + 1 << " ";
		}
		for (int a = 0; a < 16; a++)
		{
			
			
			cout << "  ";
			if (chess[i][a]=='O')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
				cout << chess[i][a] << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
			}
			else if (chess[i][a] == 'X')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
				cout << chess[i][a] << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
			}
			else
			{
				cout << chess[i][a] << " ";
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
		cout << endl;
		cout << endl;
	}
}




void Updchess(coord step, char chess[][16], int n)
{
	if (n % 2 == 1)
	{
		chess[step.x - 1][step.y - 1] = 'O';
	}
	else
	{
		chess[step.x - 1][step.y - 1] = 'X';
	}
}


int ChessCheck(char board[][16], coord step, char sign)
{
	int xcount(0), ycount(0), xycount(0), count1(1);
	for (int i = 16; i >= -16; i--)
	{
		if (step.x + i >= 0 && step.x + i <= 15)
		{
			if (board[step.x + i][step.y - 1] == sign)
			{
				if (board[step.x + i][step.y - 1] == '*')
				{
					continue;
				}
				ycount++;
			}
		}		
	}
	for (int i = 16; i >= -16; i--)
	{
		if (step.y + i >= 0 && step.y + i <= 15)
		{
			if (board[step.x - 1][step.y + i] == sign)
			{
				if (board[step.x -1][step.y +i] == '*')
				{
					continue;
				}
				xcount++;
			}
		}

	}
	for (int i = 16; i >= -16; i--)
	{
		
		
		if (step.y + i >= 0 && step.y + i <= 15 && step.x + i >= 0 && step.x + i <= 15)
		{
			if (board[step.x + i][step.y + i] != '*' && board[step.x + i][step.y + i] == sign)
			{
				xycount++;
			}
				
		}
		
	}
	for (int i = 16; i >0; i--)
	{							
			if (board[step.x + i - 1][step.y - i - 1] == sign)
			{
				if (board[step.x + i - 1][step.y - i - 1] == '*')
				{
					continue;
				}
				count1++;
			}					
	}
	for (int i = 16; i > 0; i--)
	{
		if (board[step.x - i - 1][step.y + i - 1] == sign)
		{
			if (board[step.x - i - 1][step.y + i - 1] =='*')
			{
				continue;
			}
			count1++;
		}
	}
	
	if (xcount == 5 || ycount == 5 || count1 == 5 || xycount == 5)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	//for (int i = 3; i > -4; i--)
	//{
	//	if (step.x + i >= 0 && step.x + i <= 2)
	//	{
	//		if (board[step.x + i][step.y - 1] == sign)
	//		{
	//			xcount++;
	//		}
	//	}
	//	for (int a = 3; a > -4; a--)
	//	{
	//		if (step.y + a >= 0 && step.y + a <= 2)
	//		{
	//			if (board[step.x - 1][step.y + a] == sign)
	//			{
	//				ycount++;
	//			}
	//		}
	//	}
	//		
	//	
	//}
	//if (xcount == 3 || ycount == 3 || xycount == 3)
	//{
	//	
	//	return 1;
	//}
	//else
	//{
	//	return 0;
	//}
}