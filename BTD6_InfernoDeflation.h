#pragma once

#include "Emulation.h"
#include "BTD6.h"
#include <stdlib.h>

void InfernoDeflation() {
	sourisScrollDown(1370, 502, 234);

	PlacerMonkeySouris(1374, 683, 0, 3, 2, false, 652, 297);
	Sleep(400);
	PlacerMonkeySouris(1374, 683, 0, 3, 2, false, 655, 562);
	Sleep(400);
	PlacerMonkeySouris(1370, 359, 2, 0, 4, false, 350, 639);
	Sleep(400);
	PlacerMonkeySouris(1370, 359, 2, 0, 4, true, 949, 207);
	Sleep(1400);

	// Play fforward
	SetCursorPos(1470, 810);
	simpleClick();
	Sleep(1000);
	simpleClick();
	Sleep(1000);

	// Mettre curseur zone vide
	SetCursorPos(668, 127);
	for (int i = 0; i < 372; i++) {
		Sleep(1000);
		simpleClick();
		if (GetAsyncKeyState(VK_LEFT)) {
			exit(1);
		}
	}

	QuitterNiveau();
}