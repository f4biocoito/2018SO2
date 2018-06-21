
#include "CLIENTwin32_header.h"


LRESULT CALLBACK TrataEventos(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam) {
	switch (messg) {
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		case WM_CLOSE:
			if (MessageBox(hWnd, TEXT("Sair do Cliente?"), TEXT("Pretende Sair"), MB_ICONQUESTION | MB_YESNO) == IDYES) {
				DestroyWindow(hWnd);
				return 1;
			}
			break;

		case WM_KEYDOWN:
			switch (wParam) {
				case 0x1B: //ESC
					if (MessageBox(hWnd, TEXT("Sair do Cliente?"), TEXT("Pretende Sair"), MB_ICONQUESTION | MB_YESNO) == IDYES) {
						DestroyWindow(hWnd);
						return 1;
					}
					break;

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
		case WM_COMMAND:
			switch (wParam) {
				case IDM_Criar:
					DialogBox(hInstCli, MAKEINTRESOURCE(IDD_DLG_name), hWnd, DialogName);
					break;
				case IDM_Info:
					DialogBox(hInstCli, MAKEINTRESOURCE(IDD_DLG_Info), hWnd, DialogInfo);
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




LRESULT CALLBACK DialogName(HWND hDlg, UINT messg, WPARAM wParam, LPARAM lParam) {

	HWND hwndOwner;
	RECT rc, rcDlg, rcOwner;

	UNREFERENCED_PARAMETER(lParam);
	switch (messg) {

	case WM_INITDIALOG:
		// Get the owner window and dialog box rectangles. 
		if ((hwndOwner = GetParent(hDlg)) == NULL) {
			hwndOwner = GetDesktopWindow();
		}
		GetWindowRect(hwndOwner, &rcOwner);
		GetWindowRect(hDlg, &rcDlg);
		CopyRect(&rc, &rcOwner);
		// Offset the owner and dialog box rectangles so that right and bottom 
		// values represent the width and height, and then offset the owner again 
		// to discard space taken up by the dialog box. 
		OffsetRect(&rcDlg, -rcDlg.left, -rcDlg.top);
		OffsetRect(&rc, -rc.left, -rc.top);
		OffsetRect(&rc, -rcDlg.right, -rcDlg.bottom);
		// The new position is the sum of half the remaining space and the owner's 
		// original position. 
		SetWindowPos(hDlg, HWND_TOP,
			rcOwner.left + (rc.right / 2),
			rcOwner.top + (rc.bottom / 2),
			0, 0, SWP_NOSIZE);

		return TRUE;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_CLOSE:
		DestroyWindow(hDlg);
		return 1;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK) {
			GetDlgItemText(hDlg, IDC_Nome, Nome_jogador, 10);
			EndDialog(hDlg, LOWORD(wParam));
			return 5;
		}
		if (LOWORD(wParam) == IDCANCEL) {
			DestroyWindow(hDlg);
			return 1;
		}

	default:
		return(DefWindowProc(hDlg, messg, wParam, lParam));
	}
	return 0;
}



//IDD_DLG_Info
LRESULT CALLBACK DialogInfo(HWND hDlg, UINT messg, WPARAM wParam, LPARAM lParam) {

	HWND hwndOwner;
	RECT rc, rcDlg, rcOwner;

	UNREFERENCED_PARAMETER(lParam);
	switch (messg) {
	case WM_INITDIALOG:
		// Get the owner window and dialog box rectangles. 
		if ((hwndOwner = GetParent(hDlg)) == NULL) {
			hwndOwner = GetDesktopWindow();
		}
		GetWindowRect(hwndOwner, &rcOwner);
		GetWindowRect(hDlg, &rcDlg);
		CopyRect(&rc, &rcOwner);
		// Offset the owner and dialog box rectangles so that right and bottom 
		// values represent the width and height, and then offset the owner again 
		// to discard space taken up by the dialog box. 
		OffsetRect(&rcDlg, -rcDlg.left, -rcDlg.top);
		OffsetRect(&rc, -rc.left, -rc.top);
		OffsetRect(&rc, -rcDlg.right, -rcDlg.bottom);
		// The new position is the sum of half the remaining space and the owner's 
		// original position. 
		SetWindowPos(hDlg, HWND_TOP,
			rcOwner.left + (rc.right / 2),
			rcOwner.top + (rc.bottom / 2),
			0, 0, SWP_NOSIZE);

		return TRUE;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_CLOSE:
		EndDialog(hDlg, LOWORD(wParam));
		return 1;

	default:
		return(DefWindowProc(hDlg, messg, wParam, lParam));
	}
	return 0;
}