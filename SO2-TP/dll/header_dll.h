#define UNICODE
#define _UNICODE

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

#define IN_FIELD_X 20
#define IN_FIELD_Y 22
#define STR_SIZE 10
#define BufferSize 100
#define Buffers 10


extern "C"
{
	extern DLL_IMP_API TCHAR NomeMemoria[];
	extern DLL_IMP_API TCHAR NomeSemaforoPodeEscrever[];
	extern DLL_IMP_API TCHAR NomeSemaforoPodeLer[];
	extern DLL_IMP_API TCHAR NomeMutexEscritor[];

	HANDLE DLL_IMP_API PodeEscrever;
	HANDLE DLL_IMP_API PodeLer;
	HANDLE DLL_IMP_API hMemoria;
	HANDLE DLL_IMP_API hMutexE;

	BOOL DLL_IMP_API fecharMemoria;

	TCHAR DLL_IMP_API Num_jogadores[2];
	TCHAR DLL_IMP_API Nome_jogador[10];
	HINSTANCE DLL_IMP_API hInstancia;
	HINSTANCE DLL_IMP_API hInstCli;


	struct DLL_IMP_API HNDL {
		HANDLE * hPipes;

	};

	struct DLL_IMP_API Game {
		int sizex = IN_FIELD_X;
		int sizey = IN_FIELD_X;

	};

	struct DLL_IMP_API Player {
		int pontuacao;
		TCHAR nome[STR_SIZE];
		int posx;
		int posy;
		int rapidez;
		int poder;
		TCHAR comando[STR_SIZE];
	};

	struct DLL_IMP_API Chat {
		TCHAR PtrMemoria[Buffers][BufferSize];
		int posLeitura, posEscrita;
	};

	struct DLL_IMP_API DADOS {
		Game jogo;
		Chat conversa;
		Player * jogadores;
		Player * invasores;
	};

	DLL_IMP_API void gotoxy(int x, int y);
	DLL_IMP_API void clrscr(void);
}

