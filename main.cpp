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
		sum = sum + x;
	}

	inFile.close();
	cout << "txt file read" << endl;
	return sum;
}

int main() {

	while (true) {
		
		if (GetAsyncKeyState(VK_RIGHT)) {
			cout << "lets begin" << endl;
			Sleep(2500);
			
			do {

				unePhrase(OpenFile("C:\\Users\\e2095138\\Documents\\code\\projetperso-emulation\\test.txt"));

			} while (!GetAsyncKeyState(VK_LEFT));
		}
		
		afficherPosCurseur();

		if (GetAsyncKeyState(VK_LEFT)) { // Exit
			return 0;
		}
	}
}