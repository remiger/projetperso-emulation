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

void UpgradeUnPath(int nomPath) {
	if (nomPath > 0) {
		Sleep(40);
	}
	for (int i = 0; i < nomPath; i++) {
		simpleClick();
		Sleep(30);
		randomTime(3);
	}
}

void UpgradePathsSouris(bool gauche, int pathOne, int pathTwo, int pathThree) {
	gauche ? SetCursorPos(276, 388) : SetCursorPos(1255, 397);
	UpgradeUnPath(pathOne);
	gauche ? SetCursorPos(274, 518) : SetCursorPos(1244, 512);
	UpgradeUnPath(pathTwo);
	gauche ? SetCursorPos(272, 638) : SetCursorPos(1248, 634);
	UpgradeUnPath(pathThree);
}

// 0: first, 1: last, 2: close, 3: strong
void AjusterCible(bool gauche, int target) {
	switch (target) {
	case 0:
		break;
	case 1:
		gauche ? SetCursorPos(287, 302) : SetCursorPos(1266, 304);
		simpleClick();
		Sleep(30);
		break;
	case 2:
		gauche ? SetCursorPos(287, 302) : SetCursorPos(1266, 304);
		simpleClick();
		Sleep(30);
		simpleClick();
		Sleep(30);
		break;
	case 3:
		gauche ? SetCursorPos(72, 300) : SetCursorPos(1044, 302);
		simpleClick();
		Sleep(30);
		break;
	default:
		break;
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

void PlacerMonkeySouris(int posXDepart, int posYDepart, int pathOne, int pathTwo, int pathThree, bool gauche, int posX, int posY) {
	// timestamp debut
	clock_t start = clock();

	// choisir monke
	SetCursorPos(posXDepart, posYDepart);
	sendLMouseDown();
	Sleep(30);
	
	// positionner monke on map
	SetCursorPos(posX, posY);
	Sleep(30);
	sendLMouseUp();
	Sleep(30);
	simpleClick();

	// click monke if upgrade needed
	if (pathOne > 0 || pathTwo > 0 || pathThree > 0) {
		simpleClick();
		Sleep(80);
	}

	// abort if needed
	if (GetAsyncKeyState(VK_LEFT)) {
		exit(1);
	}

	UpgradePathsSouris(gauche, pathOne, pathTwo, pathThree);

	// abort if needed
	if (GetAsyncKeyState(VK_LEFT)) {
		exit(1);
	}

	Sleep(60);

	// timestamp fin
	clock_t end = clock();
	double cpu_time_used = ((double)(double(end) - double(start))) / CLOCKS_PER_SEC;
	cout << "monkey place en " << cpu_time_used << "s\n";
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