
#include "SERVERwin32_header.h"


DWORD WINAPI comanda(LPVOID param) {


	TCHAR exeGateway[StrTam] = TEXT("..\\Debug\\gateway.exe");

	if (criarProcesso(exeGateway) == 0) {
		_tprintf(TEXT("[DEBUG] Sucesso a criar o processo gateway\n"));
	}
	else
		_tprintf(TEXT("[DEBUG] Erro a criar o processo gateway\n"));


	return 0;
}



int criarProcesso(TCHAR * exeGateway) {

	_tprintf(TEXT("[DEBUG] função criaProcesso a correr\n"));

	TCHAR resp;

	_tprintf(TEXT("Lançar o Gateway (S/N)?"));
	_tscanf_s(TEXT("%c"), &resp, 1);

	if (resp == 'S' || resp == 's') {
		PROCESS_INFORMATION pi;
		STARTUPINFO si;

		ZeroMemory(&si, sizeof(STARTUPINFO));
		si.cb = sizeof(STARTUPINFO);
		if (CreateProcess(NULL, exeGateway, NULL, NULL, 0, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)) {
			//WaitForSingleObject(pi.hProcess, INFINITE);
			_tprintf(TEXT("[DEBUG] função criaProcesso terminou com code 0\n"));
			return 0;
		}
		else {
			_tprintf(TEXT("[DEBUG] função criaProcesso terminou com code 1\n"));
			return 1;
		}
	}
	_tprintf(TEXT("[DEBUG] função criaProcesso terminou com code 2\n"));
	return 2;
}