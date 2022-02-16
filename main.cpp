#pragma once

#include "Emulation.h"
#include "MistplaySetUp.h"
#include "OSRS_Amulette.h"
#include "OSRS_Biere.h"

using namespace std;

//are you enjoying mistplay pop up
//SetCursorPos(866, 509);
//simpleClick();
//longWait(1);

void ToggleArret() {
	
}

int main() {
	while (true) {
		//LoopViderBiere(0, 4);
		CircuitCompletAmulette(true);
		



		//if (GetAsyncKeyState(VK_RIGHT)) {
		//	cout << "lets begin" << endl;
		//	Sleep(2500);
		//	
		//	do {
		//		simpleClick();
		//		randomTime(20);

		//	} while (!GetAsyncKeyState(VK_LEFT));
		//}
		//
		afficherPosCurseur();

		if (GetAsyncKeyState(VK_LEFT)) { // Exit
			return 0;
		}
	}
}