#pragma once

#include "Emulation.h"
#include "OSRS_Amulette.h"
#include "OSRS_Biere.h"
#include "TxtFilesInteractions.h"

extern string g_texteLu;

using namespace std;

int main() {
	string texte = "";
	while (true) {

		
		if (GetAsyncKeyState(VK_LEFT)) {
			texte = EmulerTypeTxtFile("C:\\Remi\\Code\\PC\\projetperso-emulation\\BeeMovie.txt", 30, texte);
		}
		cout << texte << endl;
		// afficherPosCurseur();

		if (GetAsyncKeyState(VK_DOWN)) { // Exit
			return 0;
		}
	}
}