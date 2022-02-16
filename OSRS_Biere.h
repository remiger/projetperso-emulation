#pragma once

#include "OSRSGeneral.h"

void BoireToutesBierres() {
	for (int rangee = 0; rangee < 4; rangee++) {
		for (int colonne = 0; colonne < 7; colonne++) {
			CliquerItemInventaire(rangee, colonne);
			Sleep(1100);
			randomTime(100);
		}
	}
}

void LoopViderBiere(int rangeeBiereBanque, int colonneBiereBanque) {
	if (GetAsyncKeyState(VK_RIGHT)) {
		cout << "engage drinking beer in 2.5s!" << endl;
		Sleep(2500);
		MettreCameraEnHaut();

		OuvrirBanque();
		Sleep(500);
		randomTime(100);

		AjusterQuantiteARetirer("99");
		Sleep(500);
		randomTime(500);

		int nbInventairesBu = 0;
		do {
			RetirerItemBanque(rangeeBiereBanque, colonneBiereBanque, true);
			Sleep(400);
			randomTime(50);
			FermerBanque();
			Sleep(500);
			randomTime(200);

			BoireToutesBierres();

			OuvrirBanque();

			nbInventairesBu++;
			cout << "we drank " << nbInventairesBu << " so far!" << endl;
		} while (!GetAsyncKeyState(VK_DOWN));

	}
}