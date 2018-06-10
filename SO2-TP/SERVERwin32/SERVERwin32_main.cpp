#include <windows.h>
#include <tchar.h>

#include "resource.h"

LRESULT CALLBACK TrataEventos(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK DialogProc(HWND, UINT, WPARAM, LPARAM);

TCHAR NomePrograma[] = TEXT("SERVERwin32");

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow) {
	HWND hWnd; 
	HWND hDlg;
	MSG lpMsg; 
	MSG lpMsgDlg;
	WNDCLASSEX wcApp;

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
	
	if (!RegisterClassEx(&wcApp))
		return(0);
	
	hWnd = CreateWindowW(NomePrograma,TEXT("Server Console"),WS_OVERLAPPEDWINDOW, 
		CW_USEDEFAULT, CW_USEDEFAULT,1280, 720,(HWND)HWND_DESKTOP, 
		(HMENU)LoadMenu(hInst, MAKEINTRESOURCE(IDR_MENU_janela)),
		(HINSTANCE)hInst, 0); 

	ShowWindow(hWnd, nCmdShow); 
	UpdateWindow(hWnd);

	hDlg = CreateDialogParam(hInst, MAKEINTRESOURCE(IDD_DIALOG_setup), 0, DialogProc, 0);
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

LRESULT CALLBACK TrataEventos(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam) {
	switch (messg) {
	case WM_DESTROY: 
		PostQuitMessage(0);
		break;
	case WM_CLOSE:
		if (MessageBox(hWnd,TEXT("Sair do Servidor?"), TEXT("Pretende Sair"),MB_ICONQUESTION | MB_YESNO) == IDYES){
			DestroyWindow(hWnd);
		}
		return (0);
	default:

		return(DefWindowProc(hWnd, messg, wParam, lParam));
		break;
	}
	return(0);
}

LRESULT CALLBACK DialogProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam){
	switch (messg) {
	case WM_DESTROY: 
		PostQuitMessage(0);
		break;
	default:

		return(DefWindowProc(hWnd, messg, wParam, lParam));
		break;
	}
	return(0);
}