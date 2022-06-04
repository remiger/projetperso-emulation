#pragma once

#include "Emulation.h"
#include "BTD6.h"
#include <stdlib.h>

void InfernoDeflation() {
	PlacerMonkey('a', 0, 3, 2, 660, 306);
	Sleep(400);
	PlacerMonkey('a', 0, 3, 2, 658, 561);
	Sleep(400);
	PlacerMonkey('x', 2, 0, 4, 350, 639);
	Sleep(400);
	PlacerMonkey('x', 2, 0, 4, 949, 207);
	Sleep(400);
	PlacerMonkey('q', 0, 0, 2, 356, 216);
	Sleep(400);
	
	uneLettre(' ');
	Sleep(200);
	uneLettre(' ');
	Sleep(200);

	// Mettre curseur zone vide
	SetCursorPos(668, 127);
	for (int i = 0; i < 400; i++) {
		Sleep(1000);
		simpleClick();
		if (GetAsyncKeyState(VK_LEFT)) {
			exit(1);
		}
	}

	QuitterNiveau();
}