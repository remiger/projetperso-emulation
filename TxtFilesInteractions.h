#pragma once

#include <fstream>
#include <filesystem>

string g_texteLu = "";
const char SYMBOLESSPECIAUX[] = { '!', '@', '#','$','%','^','&','*','(',')','?',':', '"', '{', '}', '|', '<', '>' };

void ListeFichiersRepository(string pathToDirectory) {
	for (const auto& entry : std::filesystem::directory_iterator(pathToDirectory))
		std::cout << entry.path() << std::endl;
}

// Press right arrow pour pauser
// file name must include .txt et le path avec double backslash '\\'
string EmulerTypeTxtFile(string nomFichier, int tempsEntreLettres, string texteDejaEcrit) {
	char x;
	string sum = "";
	ifstream inFile;
	inFile.open(nomFichier);

	// si ne trouve pas de fichier txt lisible
	if (!inFile) {
		cerr << "Unable to open file " << nomFichier << "\n";
		exit(1);   // call system to stop
	}

	// si le fichier txt est lisible
	std::cout << "txt file opened" << endl;
	while (inFile >> std::noskipws >> x) {
		bool normal = true;
		sum = sum + x;

		// si on est rendu a ce char dans le string total
		if (sum.length() > texteDejaEcrit.length()) {
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
		}


		if (GetAsyncKeyState(VK_RIGHT)) {
			break;
		}
	}
	inFile.close();
	std::cout << "txt file closed" << endl;
	return sum;
}