
#include "CLIENTwin32_header.h"


LRESULT CALLBACK TrataEventos(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam) {
	switch (messg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CLOSE:
		if (MessageBox(hWnd, TEXT("Sair do Cliente?"), TEXT("Pretende Sair"), MB_ICONQUESTION | MB_YESNO) == IDYES) {
			DestroyWindow(hWnd);
		}
		return (0);

	case WM_KEYDOWN:
		switch (wParam) {
		case 0x1B: //ESC
			if (MessageBox(hWnd, TEXT("Sair do Cliente?"), TEXT("Pretende Sair"), MB_ICONQUESTION | MB_YESNO) == IDYES) {
				DestroyWindow(hWnd);
			}
			return (0);

		case VK_LEFT:

			break;

		case VK_RIGHT:

			break;

		case VK_UP:

			break;

		case VK_DOWN:

			break;

		default:
			break;

		}

	default:

		return(DefWindowProc(hWnd, messg, wParam, lParam));
		break;
	}
	return(0);
}
