
#include "header_dll.h"


TCHAR NomeMemoria[] = TEXT("Nome da Mem�ria Partilhada");
TCHAR NomeSemaforoPodeEscrever[] = TEXT("Sem�foro Pode Escrever");
TCHAR NomeSemaforoPodeLer[] = TEXT("Sem�foro Pode Ler");
TCHAR NomeMutexEscritor[] = TEXT("Mutex escritor");

void gotoxy(int x, int y)
{
	static HANDLE hStdout = NULL;
	COORD coord;
	coord.X = x;
	coord.Y = y;
	if (!hStdout)
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hStdout, coord);
}

void clrscr(void)
{
	HANDLE hConsoleOut = NULL;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	CHAR attribute = 0x07;

	COORD c;
	DWORD len, wr;

	if (!hConsoleOut) {
		hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
	}

	len = csbiInfo.dwSize.X * csbiInfo.dwSize.Y;
	c.X = c.Y = 0;
	FillConsoleOutputCharacter(hConsoleOut, ' ', len, c, &wr);
	FillConsoleOutputAttribute(hConsoleOut, attribute, len, c, &wr);

	gotoxy(1, 1);
}