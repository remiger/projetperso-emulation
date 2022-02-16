#pragma once

#include "Emulation.h"
#include "OSRSGeneral.h"

void ChoisirAmulette(bool ruby) {
	if (ruby) {

		// RUBY: PlacerCurseurEtAttendre(598, 352, 500, true);
		// Saphire:
		PlacerCurseurEtAttendre(496, 352, 500, true);
	}
	else {
		PlacerCurseurEtAttendre(450, 351, 500, true);
	}
}

void ToggleCourse() {
	PlacerCurseurEtAttendre(1372, 154, 200, true);
}

// Amulette mould 2e position banque
// Gold bars 3e position banque
// Ruby 4e position
// Commencer a la banque avec inventaire ouvert
// Unzoom au max
void SmeltAmulette(bool ruby) {
	// Items inventaire
	RetirerItemBanque(0, 1, false);
	RetirerItemBanque(0, 2, true);
	if (ruby) {
		RetirerItemBanque(0, 3, true);
	}
	ToggleCourse();
	Sleep(500);
	//Go furnace
	PlacerCurseurEtAttendre(1136, 317, 1000, true);
	longWait(10);

	// Forger amulette
	ChoisirAmulette(ruby);
	longWait(23);

	if (!ruby) {
		// Recliquer sur furnace a moitie de linventaire
		PlacerCurseurEtAttendre(806, 446, 500, true);
		Sleep(1000);

		// Choisir amulette de nouveau
		ChoisirAmulette(ruby);
		longWait(23);
	}

	ToggleCourse();
	Sleep(1000);

	// Aller banque
	PlacerCurseurEtAttendre(335, 609, 500, true);
	longWait(5);

	DepositAllItemsBank();
	Sleep(1000);
}

// Commencer avec right arrow
// Arreter avec left arrow
// Amulette mould 2e position banque Gold bars 3e position banque Ruby 4e position
void CircuitCompletAmulette(bool ruby) {
	if (GetAsyncKeyState(VK_RIGHT)) {
		cout << "beginning in 2.5s!" << endl;
		int nombreRun = 0;

		// Setup
		Sleep(2500);
		MettreCameraEnHaut();
		OuvrirBanque();
		AjusterQuantiteARetirer("14");
		Sleep(500);
		randomTime(500);
		cout << "cam up + open bank" << endl;
		do {
			SmeltAmulette(ruby);
			nombreRun++;
			cout << "completed run " << nombreRun << endl;
		} while (!GetAsyncKeyState(VK_LEFT) || nombreRun < 300);
	}
}