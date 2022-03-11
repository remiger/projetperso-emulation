#pragma once

#include "Emulation.h"
#include <stdlib.h>

// constantes banque
const int BANQUEPOSXDEPART = 470;
const int BANQUEPOSYDEPART = 115;
const int BANQUELARGEURX = 50;
const int BANQUELONGUEURY = 40;

// constantes inventaire
const int INVENTAIREPOSXDEPART = 1350;
const int INVENTAIREPOSYDEPART = 590;
const int INVENTAIRELARGEURX = 41;
const int INVENTAIRELONGUEURY = 35;

// true = click gauche, false = click droit
void PlacerCurseurEtAttendre(int x, int y, int temps, bool clickGauche) {
	SetCursorPos(x, y);
	Sleep(temps);
	if (clickGauche) {
		randomTime(100);
		simpleClick();
	}
	else{
		randomTime(100);
		simpleClickDroit();
	}
}

void MettreCameraEnHaut() {
	sendKeyDown(0x26);
	Sleep(2000);
	sendKeyUp(0x26);
}

void DepositAllItemsBank() {
	PlacerCurseurEtAttendre(831, 676, 500, true);
}

// Ouvrir banque proche furnace
void OuvrirBanque() {
	PlacerCurseurEtAttendre(765, 468, 500, true);
	cout << "cum" << endl;
	Sleep(1000);
	cout << "fart" << endl;
	DepositAllItemsBank();
	Sleep(1000);
}

void AjusterQuantiteARetirer(string nouvelleQte) {
	PlacerCurseurEtAttendre(BANQUEPOSXDEPART, BANQUEPOSYDEPART, 700, false);
	PlacerCurseurEtAttendre(BANQUEPOSXDEPART, (BANQUEPOSYDEPART + 90), 500, true);
	Sleep(1000);
	unePhrase(nouvelleQte, 50);
	enter();
	Sleep(500);
	DepositAllItemsBank();
	randomTime(100);
}

void RetirerItemBanque(int rangee, int colonne, bool retirerX) {
	int posX = BANQUEPOSXDEPART;
	int posY = BANQUEPOSYDEPART;
	for (int i = 0; i < colonne; i++) {
		posX += BANQUELARGEURX;
	}
	for (int i = 0; i < rangee; i++) {
		posY += BANQUELONGUEURY;
	}
	SetCursorPos(posX, posY);

	Sleep(500);

	if (retirerX) {
		randomTime(100);
		simpleClickDroit();

		SetCursorPos(posX, posY + 70);
		Sleep(400);
		randomTime(50);
		simpleClick();

	}
	else {
		randomTime(100);
		simpleClick();
	}
}

void FermerBanque() {
	PlacerCurseurEtAttendre(871, 44, 500, true);
}

void CliquerItemInventaire(int rangee, int colonne) {
	int posX = INVENTAIREPOSXDEPART;
	int posY = INVENTAIREPOSYDEPART;
	for (int i = 0; i < rangee; i++) {
		posX += INVENTAIRELARGEURX;
	}
	for (int i = 0; i < colonne; i++) {
		posY += INVENTAIRELONGUEURY;
	}
	SetCursorPos(posX, posY);
	Sleep(500);

	randomTime(100);
	simpleClick();
}