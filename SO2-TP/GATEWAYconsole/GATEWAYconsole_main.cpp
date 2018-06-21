
#include "GATEWAYconsole_header.h"


int _tmain(int argc, LPTSTR argv[]) {

#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif

	gotoxy(0, 10);
	_tprintf(TEXT("Sou o gateway"));
	Sleep(4000);

	handlesGT HTTT;
	HANDLE hT;
	DWORD threadId;

	//criar memoria e pipes

	hT = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)traduz, (LPVOID)&HTTT, 0, &threadId);



	return 0;
}