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

DWORD WINAPI traduz(LPVOID param);

struct handlesGT {
	HANDLE mem;
	HANDLE pip;
};