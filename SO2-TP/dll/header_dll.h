
#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

#ifdef DLL_EXPORTS  //verificar no projeto em C/C++ -> Preprocessor
#define DLL_IMP_API __declspec(dllexport)
#else
#define DLL_IMP_API __declspec(dllimport)
#endif

//#define MIN_FIELD_X 20


extern "C"
{
	//Variáveis globais da DLL
	extern DLL_IMP_API LPCTSTR nMemory;


	//Funções a serem exportadas/importadas
	DLL_IMP_API void gotoxy(int x, int y);
	DLL_IMP_API void clrscr(void);
}

