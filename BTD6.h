#pragma once

#include "Emulation.h"
#include <stdlib.h>

void UpgradePaths(int pathOne, int pathTwo, int pathThree) {
	for (int i = 0; i < pathOne; i++) {
		uneLettre(',');
		Sleep(100);
		randomTime(50);
	}
	for (int i = 0; i < pathTwo; i++) {
		uneLettre('.');
		Sleep(100);
		randomTime(50);
	}
	for (int i = 0; i < pathThree; i++) {
		uneLettre('/');
		Sleep(100);
		randomTime(50);
	}
}

void PlacerMonkey(char lettreMonkey, int pathOne, int pathTwo, int pathThree, int posX, int posY) {
	SetCursorPos(posX, posY);
	Sleep(100);
	uneLettre(lettreMonkey);
	cout << 0x41 << lettreMonkey << endl;
	Sleep(200);
	simpleClick();
	Sleep(100);
	UpgradePaths(pathOne, pathTwo, pathThree);
}

void QuitterNiveau() {
	// Victory
	SetCursorPos(769, 726);
	simpleClick();
	Sleep(2000);

	// Home
	SetCursorPos(562, 682);
	simpleClick();
	Sleep(4000);
}

void ChoisirNiveau(int mapDifficulteFromZeroToThree, int page, int numeroTableauDeZeroACinq, int easyMediumHard) {
	// Play
	SetCursorPos(669, 734);
	simpleClick();
	Sleep(1500);

	// Difficulte
	switch (mapDifficulteFromZeroToThree) {
	case 0:
		SetCursorPos(468, 783);
		break;
	case 1:
		SetCursorPos(665, 781);
		break;
	case 2:
		SetCursorPos(873, 782);
		break;
	case 3:
		SetCursorPos(1078, 785);
		break;
	default:
		SetCursorPos(468, 783);
		break;
	}
	simpleClick();
	Sleep(1500);
	


	// Page
	SetCursorPos(1313, 346);
	for (int i = 0; i < page; i++) {
		simpleClick();
		Sleep(1500);
		randomTime(50);
	}

	switch (numeroTableauDeZeroACinq) {
	case 0:
		SetCursorPos(435, 217);
		break;
	case 1:
		SetCursorPos(763, 214);
		break;
	case 2:
		SetCursorPos(1081, 222);
		break;
	case 3:
		SetCursorPos(431, 474);
		break;
	case 4:
		SetCursorPos(754, 486);
		break;
	case 5:
		SetCursorPos(1098, 469);
		break;
	default:
		SetCursorPos(435, 217);
		break;
	}
	simpleClick();
	Sleep(1500);
	

	switch (easyMediumHard) {
	case 0:
		SetCursorPos(514, 356);
		break;
	case 1:
		SetCursorPos(771, 363);
		break;
	case 2:
		SetCursorPos(1026, 362);
		break;
	default:
		SetCursorPos(514, 356);
		break;
	}

	
	simpleClick();
	Sleep(1500);
	randomTime(50);

	// Always deflation lul
	SetCursorPos(1019, 378);
	Sleep(500);
	simpleClick();

	// Wait long pcq loading forever
	Sleep(8000);

	// Ok pop up
	SetCursorPos(767, 600);
	Sleep(500);
	simpleClick();

	// Popup disappear
	Sleep(2000);
}