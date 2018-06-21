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

#include "resource.h"


#define StrTam 40


LRESULT CALLBACK TrataEventos(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK DialogSetup(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK DialogInfo(HWND, UINT, WPARAM, LPARAM);


int criarProcesso(TCHAR * exeGateway);

