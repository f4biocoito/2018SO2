
#include "server_header.h"

int _tmain(int argc, LPTSTR argv[]) {

#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif

	TCHAR exeGateway[StrTam] = TEXT("..\\Debug\\gateway.exe");
	
	if (criarProcesso(exeGateway) == 0) {
		_tprintf(TEXT("[DEBUG] Sucesso a criar o processo gateway\n"));
	}
	else
		_tprintf(TEXT("[DEBUG] Erro a criar o processo gateway\n"));




	_tprintf(TEXT("[DEBUG] Server a terminar\n"));
	Sleep(6000);

	return 0;
}

