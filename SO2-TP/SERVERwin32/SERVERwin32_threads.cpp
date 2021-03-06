
#include "SERVERwin32_header.h"


int criarProcesso(TCHAR * exeGateway) {

	PROCESS_INFORMATION pi;
	STARTUPINFO si;

	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	if (CreateProcess(NULL, exeGateway, NULL, NULL, 0, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)) {
		_tprintf(TEXT("[DEBUG] fun��o criaProcesso terminou com code 0\n"));
		return 0;
	}
	else {
		_tprintf(TEXT("[DEBUG] fun��o criaProcesso terminou com code 1\n"));
		return 1;
	}
}

DWORD WINAPI Gerir(LPVOID param) {

	HINSTANCE y = (HINSTANCE )param;

	_tprintf(TEXT("[Thread %d]Vou come�ar a trabalhar\n"), GetCurrentThreadId());

	DADOS *shm;

	PodeEscrever = CreateSemaphore(NULL, Buffers, Buffers, NomeSemaforoPodeEscrever);
	PodeLer = CreateSemaphore(NULL, 0, Buffers, NomeSemaforoPodeLer);
	hMutexE = CreateMutex(NULL, FALSE, NomeMutexEscritor); //criar mutex

	hMemoria = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, sizeof(DADOS), NomeMemoria);
	if (PodeEscrever == NULL || PodeLer == NULL || hMemoria == NULL) {
		_tprintf(TEXT("[Erro]Cria��o de objectos do Windows(%d)\n"), GetLastError());
		return -1;
	}

	shm = (DADOS*)MapViewOfFile(hMemoria, FILE_MAP_WRITE, 0, 0, sizeof(DADOS));
	if (shm == NULL) {
		_tprintf(TEXT("[Erro]Mapeamento da mem�ria partilhada(%d)\n"), GetLastError());
		return -2;
	}

	while (fecharMemoria) {
		WaitForSingleObject(PodeEscrever, INFINITE);
		WaitForSingleObject(hMutexE, INFINITE); //esperar mutex

		ReleaseMutex(hMutexE);
		_tprintf(TEXT("Escrever para buffer \n"));

		Sleep(1000);
		ReleaseSemaphore(PodeLer, 1, NULL);

	}

	UnmapViewOfFile(shm);
	CloseHandle(PodeEscrever);
	CloseHandle(PodeLer);
	CloseHandle(hMemoria);
	CloseHandle(hMutexE); //fechar mutex

	return 0;
}


DWORD WINAPI lermemoria(LPVOID param) {

	return 0;
}

DWORD WINAPI escrevermemoria(LPVOID param) {

	return 0;
}

DWORD WINAPI processar(LPVOID param) {

	return 0;
}