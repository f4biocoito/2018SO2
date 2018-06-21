
#include "SERVERwin32_header.h"


int criarProcesso(TCHAR * exeGateway) {

	PROCESS_INFORMATION pi;
	STARTUPINFO si;

	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	if (CreateProcess(NULL, exeGateway, NULL, NULL, 0, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)) {
		_tprintf(TEXT("[DEBUG] função criaProcesso terminou com code 0\n"));
		return 0;
	}
	else {
		_tprintf(TEXT("[DEBUG] função criaProcesso terminou com code 1\n"));
		return 1;
	}
}
