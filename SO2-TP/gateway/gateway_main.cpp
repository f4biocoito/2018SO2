
#include "gateway_header.h"

int _tmain(int argc, LPTSTR argv[]) {

#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif

	gotoxy(0, 10);
	_tprintf(TEXT("Sou o gateway"));
	Sleep(4000);


	return 0;
}