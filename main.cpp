#pragma once

#include "Emulation.h"
#include "OSRS_Amulette.h"
#include "OSRS_Biere.h"
#include <fstream>

using namespace std;

//are you enjoying mistplay pop up
//SetCursorPos(866, 509);
//simpleClick();
//longWait(1);

const char SYMBOLESCHAR[] = { 0b00100001, 0b01000000, 0b00100011, 0b00100100, 0b00100101, 0b01011110, 0b01011110, 0b00100110, 0b00101010, 0b00101000, 0b00101001 };

string OpenFile(string nomFichier) {
	char x;
	string sum = "";
	ifstream inFile;
	inFile.open(nomFichier);
	if (!inFile) {
		cerr << "Unable to open file " << nomFichier << "\n";
		exit(1);   // call system to stop
	}
	string directory;
	const size_t last_slash_idx = nomFichier.rfind('\\');
	if (std::string::npos != last_slash_idx)
	{
		directory = nomFichier.substr(0, last_slash_idx);
		cout << directory << endl;
	}
	while (inFile >> std::noskipws >> x) {
		if (x == '\n') {
			if (sum[sum.length()] != '\n') {
				enter();
			}
		}
		else {
			string s(1, x);
			unePhrase(s);
		}
		for (int i = 0; i < 8; i++) {
			printf("%d", !!((x << i) & 0x80));
		}
		printf("\n");
		sum = sum + x;
	}

	inFile.close();
	cout << "txt file read" << endl;
	return sum;
}

int main() {
	Sleep(3000);
	for (int i = 0; i < strlen(SYMBOLESCHAR); i++) {
		char lettre = i;
		uneLettreMajuscule(lettre);
	}
	//OpenFile("C:\\Users\\e2095138\\Documents\\code\\projetperso-emulation\\test.txt");
	//cout << ;
	while (true) {
		
		if (GetAsyncKeyState(VK_RIGHT)) {
			cout << "lets begin" << endl;
			Sleep(2500);
			
			do {

				

			} while (!GetAsyncKeyState(VK_LEFT));
		}
		
		// afficherPosCurseur();

		if (GetAsyncKeyState(VK_LEFT)) { // Exit
			return 0;
		}
	}
}