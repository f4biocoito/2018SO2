
#include "SERVERwin32_header.h"


TCHAR NomePrograma[] = TEXT("SERVERwin32");

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow) {
	HWND hWnd; 
	HWND hDlg;
	MSG lpMsg; 
	MSG lpMsgDlg;
	WNDCLASSEX wcApp;

#ifdef UNICODE
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif
	hInstancia = hInst;
	Game jogo;

	HANDLE hT;
	DWORD threadId;
	hT = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Gerir, (LPVOID)&hInstancia, 0, &threadId);
	
	
	TCHAR exeGateway[StrTam] = TEXT("..\\x64\\Debug\\GATEWAYconsole.exe");

	if (criarProcesso(exeGateway)==1) {
		return(1);
	}
	
	wcApp.cbSize = sizeof(WNDCLASSEX); 
	wcApp.hInstance = hInst;
	wcApp.lpszClassName = NomePrograma;
	wcApp.lpfnWndProc = TrataEventos; 
	wcApp.style = CS_HREDRAW | CS_VREDRAW;
	wcApp.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON_taskbar));
	wcApp.hIconSm = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON_window));
	wcApp.hCursor = LoadCursor(NULL, IDC_ARROW); 
	wcApp.lpszMenuName = NULL;
	wcApp.cbClsExtra = 0; 
	wcApp.cbWndExtra = 0; 
	wcApp.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	
	if (!RegisterClassEx(&wcApp)) {
		return(1);
	}
	
	hWnd = CreateWindow(NomePrograma,TEXT("Server Console"),WS_OVERLAPPEDWINDOW, 
		CW_USEDEFAULT, CW_USEDEFAULT,1280, 720,(HWND)HWND_DESKTOP, 
		(HMENU)LoadMenu(hInst, MAKEINTRESOURCE(IDR_MENU_janela)),
		(HINSTANCE)hInst, 0); 

	ShowWindow(hWnd, nCmdShow); 
	UpdateWindow(hWnd);

	hDlg = CreateDialogParam(hInst, MAKEINTRESOURCE(IDD_DIALOG_setup), 0, DialogSetup, 0);
	ShowWindow(hDlg, nCmdShow);

	while ((GetMessage(&lpMsgDlg, NULL, 0, 0))) {
			TranslateMessage(&lpMsgDlg);
			DispatchMessage(&lpMsgDlg);
	}

	while (GetMessage(&lpMsg, NULL, 0, 0)) {
		TranslateMessage(&lpMsg); 
		DispatchMessage(&lpMsg); 
	}
	
	return((int)lpMsg.wParam); 
}
