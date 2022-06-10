#pragma once

#include "Emulation.h"
//#include "MistplaySetUp.h"
//#include "OSRS_Amulette.h"
//#include "OSRS_Biere.h"
#include "BTD6.h"
#include "BTD6_InfernoDeflation.h"
#include "clock.h"

using namespace std;


int main() {
	while (true) {
		if (GetAsyncKeyState(VK_RIGHT)) {
			cout << "lets begin" << endl;

			do {

				ChoisirNiveau(3, 0, 3, 0);
				InfernoDeflation();


			} while (!GetAsyncKeyState(VK_LEFT));
		}
		//
		afficherPosCurseur();

		if (GetAsyncKeyState(VK_UP)) { // Exit
			return 0;
		}
	}
}
