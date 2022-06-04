#pragma once

#include "Emulation.h"
#include "OSRS_Amulette.h"
#include "OSRS_Biere.h"
#include "TxtFilesInteractions.h"

extern int g_texteLu;

using namespace std;


int main() {
	int total = 0;
	while (true) {

		
		if (GetAsyncKeyState(VK_LEFT)) {
			total = EmulerTypeTxtFile("C:\\Remi\\Code\\PC\\projetperso-emulation\\BeeMovie.txt", 50, total);
		}
		// afficherPosCurseur();

		if (GetAsyncKeyState(VK_DOWN)) { // Exit
			return 0;
		}
	}
}