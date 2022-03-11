#pragma once

#include <fstream>
#include <filesystem>

const char SYMBOLESSPECIAUX[] = { '!', '@', '#','$','%','^','&','*','(',')','?',':', '"', '{', '}', '|', '<', '>' };

void ListeFichiersRepository(string pathToDirectory) {
	for (const auto& entry : std::filesystem::directory_iterator(pathToDirectory))
		std::cout << entry.path() << std::endl;
}

// Press votre touche definiee pour commencer
// file name must include .txt et le path avec double backslash '\\'
string EmulerTypeTxtFile(string nomFichier, int tempsEntreLettres) {
	char x;
	char previouschar;
	string sum = "";
	ifstream inFile;
	inFile.open(nomFichier);
	if (!inFile) {
		cerr << "Unable to open file " << nomFichier << "\n";
		exit(1);   // call system to stop
	}

	while (inFile >> std::noskipws >> x) {
		bool normal = true;
		previouschar = x;

		// Verifier si symboles
		for (size_t i = 0; i < strlen(SYMBOLESSPECIAUX); i++) {
			if (x == SYMBOLESSPECIAUX[i]) {
				cout << SYMBOLESSPECIAUX[i] << endl;
				cout << x;
				uneLettreMajuscule(SYMBOLESSPECIAUX[i]);
				normal = false;
			}
		}

		// Si pas de symbole
		if (normal) {
			string s(1, x);
			unePhrase(s, tempsEntreLettres);
		}


		sum = sum + x;
		if (GetAsyncKeyState(VK_RIGHT)) {
			inFile.close();
			exit(1);
		}
	}

	inFile.close();
	std::cout << "txt file read" << endl;
	return sum;
}