#pragma once

#include "Emulation.h"
#include "OSRS_Amulette.h"
#include "OSRS_Biere.h"
#include "TxtFilesInteractions.h"

using namespace std;

int main() {
	while (true) {

		
		if (GetAsyncKeyState(VK_LEFT)) {
			EmulerTypeTxtFile("C:\\Remi\\Code\\PC\\projetperso-emulation\\BeeMovie.txt", 30);
		}
		
		// afficherPosCurseur();

		if (GetAsyncKeyState(VK_RIGHT)) { // Exit
			return 0;
		}
	}
}