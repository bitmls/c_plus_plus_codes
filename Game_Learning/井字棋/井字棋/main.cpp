#include <graphics.h>

char board_data[3][3] = {
	{'-', '-', '-'},
	{'-', '-', '-'},
	{'-', '-', '-'}
};

char current_piece = 'O';
unsigned char step = 0;

// ʤ�����
bool CheckWin(char c) {
	if (board_data[0][0] == c && board_data[0][1] == c && board_data[0][2] == c)
		return true;
	else if (board_data[1][0] == c && board_data[1][1] == c && board_data[1][2] == c)
		return true;
	else if (board_data[2][0] == c && board_data[2][1] == c && board_data[2][2] == c)
		return true;
	else if (board_data[0][0] == c && board_data[1][0] == c && board_data[2][0] == c)
		return true;
	else if (board_data[0][1] == c && board_data[1][1] == c && board_data[2][1] == c)
		return true;
	else if (board_data[0][2] == c && board_data[1][2] == c && board_data[2][2] == c)
		return true;
	else if (board_data[0][0] == c && board_data[1][1] == c && board_data[2][2] == c)
		return true;
	else if (board_data[0][2] == c && board_data[1][1] == c && board_data[2][0] == c)
		return true;
	return false;
}

// ƽ�ּ��
bool CheckDraw() {
	if (step >= 9)
		return true;
	return false;
}

// ���̻���
void DrawBoard() {
	line(0, 200, 600, 200);
	line(0, 400, 600, 400);
	line(200, 0, 200, 600);
	line(400, 0, 400, 600);
}

// ���ӻ���
void DrawPiece() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board_data[i][j] == 'O')
				circle(i * 200 + 100, j * 200 + 100, 100);
			else if (board_data[i][j] == 'X') {
				line(i * 200, j * 200, (i + 1) * 200, (j + 1) * 200);
				line((i + 1) * 200, j * 200, i * 200, (j + 1) * 200);
			}
		}
	}
}

// ������ʾ��Ϣ
void DrawTipText() {
	static TCHAR str[64];
	_stprintf_s(str, _T("��ǰ��������Ϊ��%c"), current_piece);

	settextcolor(RGB(225, 175, 45));
	outtextxy(0, 0, str);
}

int main() {
	initgraph(600, 600);

	ExMessage msg;

	bool running = true;

	BeginBatchDraw();
	while (running) {
		DWORD start_time = GetTickCount();

		while (peekmessage(&msg)) {
			// �ж��������Ƿ���
			if (msg.message == WM_LBUTTONDOWN) {
				int x = msg.x;
				int y = msg.y;

				int x_index = x / 200;
				int y_index = y / 200;

				if (board_data[x_index][y_index] == '-') {
					board_data[x_index][y_index] = current_piece;
					step++;

					// �л���������
					if (current_piece == 'O')
						current_piece = 'X';
					else
						current_piece = 'O';
				}
			}
		}

		cleardevice();
		DrawBoard();
		DrawPiece();
		DrawTipText();
		FlushBatchDraw();

		if (CheckWin('X')) {
			MessageBox(GetHWnd(), _T("X ��һ�ʤ"), _T("��Ϸ����"), MB_OK);
			running = false;
		}
		else if (CheckWin('O')) {
			MessageBox(GetHWnd(), _T("O ��һ�ʤ"), _T("��Ϸ����"), MB_OK);
			running = false;
		}
		else if (CheckDraw()) {
			MessageBox(GetHWnd(), _T("ƽ��"), _T("��Ϸ����"), MB_OK);
			running = false;
		}

		DWORD end_time = GetTickCount();
		DWORD delta_time = end_time - start_time;

		if (delta_time < 1000 / 60) {
			Sleep(1000 / 60 - delta_time);
		}
	}
	EndBatchDraw();

	return 0;
}