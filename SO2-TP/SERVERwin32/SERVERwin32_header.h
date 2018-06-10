#define UNICODE
#define _UNICODE


#include "..\dll\header_dll.h"

#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

#define StrTam 40





LRESULT CALLBACK TrataEventos(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK DialogProc(HWND, UINT, WPARAM, LPARAM);


DWORD WINAPI comanda(LPVOID param);


int criarProcesso(TCHAR * exeGateway);