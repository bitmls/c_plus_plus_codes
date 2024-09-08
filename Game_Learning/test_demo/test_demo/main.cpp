#include <graphics.h>

int main() {
	initgraph(1280, 720);

	int x = 300, y = 300;

	BeginBatchDraw();

	while (1) {
		ExMessage msg;
		while (peekmessage(&msg)) {
			if (msg.message == WM_MOUSEMOVE) {
				x = msg.x;
				y = msg.y;
			}
		}

		cleardevice();
		solidcircle(x, y, 100);
		FlushBatchDraw();
	}

	EndBatchDraw();

	return 0;
}