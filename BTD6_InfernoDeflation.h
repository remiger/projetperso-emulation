#pragma once

#include "Emulation.h"
#include "BTD6.h"
#include <stdlib.h>

void InfernoDeflation() {
	PlacerMonkeySouris(1462, 190, 0, 0, 2, false, 357, 217);

	sourisScrollDown(1370, 502, 234);

	PlacerMonkeySouris(1374, 683, 0, 3, 2, false, 652, 297);
	PlacerMonkeySouris(1374, 683, 0, 3, 2, false, 655, 562);
	PlacerMonkeySouris(1370, 359, 2, 0, 4, false, 350, 639);
	PlacerMonkeySouris(1370, 359, 2, 0, 4, true, 949, 207);

	// Play fforward
	SetCursorPos(1470, 810);
	simpleClick();
	Sleep(50);
	simpleClick();
	Sleep(50);

	// Mettre curseur zone vide
	SetCursorPos(668, 127);
	for (int i = 0; i < 370; i++) {
		Sleep(1000);
		simpleClick();
		if (GetAsyncKeyState(VK_LEFT)) {
			exit(1);
		}
	}

	QuitterNiveau();
}