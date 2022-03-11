#pragma once

#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <iostream>
#include <charconv>
#include <system_error>
#include <array>
#include <conio.h>
#include<stdio.h>
#include<ctype.h>

using namespace std;

const int AEROBAS = 0x32;
const int HASHTAG = 0x33;

//Simule une lettre
void uneLettre(char a) {
	INPUT Input = { 0 };
	Input.type = INPUT_KEYBOARD;
	Input.ki.wVk = VkKeyScanA(a);
	SendInput(1, &Input, sizeof(Input));
	ZeroMemory(&Input, sizeof(Input));
	Input.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &Input, sizeof(Input));
}

void sendKeyDown(unsigned char keyCode)
{
	INPUT input;
	input.type = INPUT_KEYBOARD;

	input.ki.wVk = keyCode;
	input.ki.dwFlags = 0;
	input.ki.time = 0;
	input.ki.dwExtraInfo = 0;

	SendInput(1, &input, sizeof(INPUT));
}

void sendKeyUp(unsigned char keyCode)
{
	INPUT input;
	input.type = INPUT_KEYBOARD;

	input.ki.wVk = keyCode;
	input.ki.dwFlags = KEYEVENTF_KEYUP;
	input.ki.time = 0;
	input.ki.dwExtraInfo = 0;

	SendInput(1, &input, sizeof(INPUT));
}

//Shift qqch ou le qqch est a (parametre)
void symbolWShift(int a) {
	sendKeyDown(VK_SHIFT);
	sendKeyDown(a);
	sendKeyUp(a);
	sendKeyUp(VK_SHIFT);
}

void uneLettreMajuscule(char a) {
	sendKeyDown(VK_SHIFT);
	uneLettre(a);
	sendKeyUp(VK_SHIFT);
}

void ctrlTab() {
	sendKeyDown(VK_CONTROL);
	sendKeyDown(VK_TAB);
	sendKeyUp(VK_TAB);
	sendKeyUp(VK_CONTROL);
}

void altTab() {
	sendKeyDown(VK_LMENU);
	sendKeyDown(VK_TAB);
	sendKeyUp(VK_TAB);
	sendKeyUp(VK_LMENU);
}

void pressEsc() {
	sendKeyDown(VK_ESCAPE);
	sendKeyUp(VK_ESCAPE);
}

void simpleClick() {
	INPUT input[2] = {};

	input[0].type = INPUT_MOUSE;
	//input[0].mi.dx = x;
	//input[0].mi.dy = y;
	input[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

	input[1] = input[0];
	input[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;

	SendInput(2, input, sizeof(INPUT));
}

void simpleClickDroit() {
	INPUT input[2] = {};

	input[0].type = INPUT_MOUSE;
	//input[0].mi.dx = x;
	//input[0].mi.dy = y;
	input[0].mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;

	input[1] = input[0];
	input[1].mi.dwFlags = MOUSEEVENTF_RIGHTUP;

	SendInput(2, input, sizeof(INPUT));
}

void doubleClick() {
	for (int i = 0; i < 2; i++) {
		simpleClick();
	}
}

//Simule enter
void enter() {
	INPUT Input = { 0 };
	Input.type = INPUT_KEYBOARD;
	Input.ki.wVk = VK_RETURN;
	SendInput(1, &Input, sizeof(Input));
	ZeroMemory(&Input, sizeof(Input));
	Input.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &Input, sizeof(Input));
}

void tagger(string phrase, string nom) {
	char a[40];
	char b[30];
	for (unsigned int i = 0; i < phrase.length(); i++) {
		a[i] = phrase[i];
		uneLettre(a[i]);
		Sleep(45);
	}
	symbolWShift(AEROBAS);

	for (unsigned int i = 0; i < nom.length(); i++) {
		b[i] = nom[i];
		uneLettre(b[i]);
		Sleep(45);
	}
	enter();
	enter();
}

//Simule une phrase
void unePhrase(string a, int msDelayLettres) {
	char phrase[60];
	for (unsigned int i = 0; i < a.length(); i++) {
		phrase[i] = a[i];
		if (isalpha(phrase[i])) {
			if (isupper(phrase[i])) {
				uneLettreMajuscule(phrase[i]);
			}
			else {
				uneLettre(phrase[i]);
			}
		}
		else {
			uneLettre(phrase[i]);
		}
		Sleep(msDelayLettres);
	}
}

//Random voulu (tempsMax en millisecondes)
void randomTime(int tempsMax) {
	Sleep(rand() % tempsMax);
}

void Dormir(unsigned int temps, int vk_key) {
	SleepEx(temps, GetAsyncKeyState(vk_key));
	//cout << "waited " << temps << " milliseconds, " << " vk_key value: " << GetAsyncKeyState(vk_key) << endl;
	if (GetAsyncKeyState(vk_key)) {
		cout << "penis" << endl;
	}
}

void afficherPosCurseur() {
	char g = _getch();
	POINT xypos;
	if (g == 'g' || g == 'G')
	{
		GetCursorPos(&xypos);
		//cout << "X:" << xypos.x << "\tY:" << xypos.y << endl;
		cout << "SetCursorPos(" << xypos.x << ", " << xypos.y << ");" << endl;
		cout << "simpleClick();" << endl;
		cout << "longWait(1);" << endl;
	}
	else if (g == 'h' || g == 'H')
	{
		GetCursorPos(&xypos);
		//cout << "X:" << xypos.x << "\tY:" << xypos.y << endl;
		cout << "SetCursorPos(" << xypos.x << ", " << xypos.y << ");" << endl;
		cout << "simpleClickDroit();" << endl;
		cout << "longWait(1);" << endl;
	}
}

void sourisMonter(int x, int y, int howBigYouMove) {
	SetCursorPos(x, y);
	for (int i = 0; i < howBigYouMove; i++) {
		Sleep(10);
		SetCursorPos(x, y - i);
	}
}

void sourisDescendre(int x, int y, int howBigYouMove) {
	SetCursorPos(x, y);
	for (int i = 0; i < howBigYouMove; i++) {
		Sleep(10);
		SetCursorPos(x, y + i);
	}
}

void sourisDroite(int x, int y, int howBigYouMove) {
	SetCursorPos(x, y);
	for (int i = 0; i < howBigYouMove; i++) {
		Sleep(10);
		SetCursorPos(x + i, y);
	}
}

void sourisGauche(int x, int y, int howBigYouMove) {
	SetCursorPos(x, y);
	for (int i = 0; i < howBigYouMove; i++) {
		Sleep(10);
		SetCursorPos(x - i, y);
	}
}

void sourisScrollDown(int x, int y, int howMuchYouScroll) {
	if (!GetAsyncKeyState(VK_DOWN)) {
		SetCursorPos(x, y);
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		sourisMonter(x, y, howMuchYouScroll);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	}
}

void sourisScrollUp(int x, int y, int howMuchYouScroll) {
	if (!GetAsyncKeyState(VK_DOWN)) {
		SetCursorPos(x, y);
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		sourisDescendre(x, y, howMuchYouScroll);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	}
}

void sourisScrollRight(int x, int y, int howMuchYouScroll) {
	if (!GetAsyncKeyState(VK_DOWN)) {
		SetCursorPos(x, y);
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		sourisGauche(x, y, howMuchYouScroll);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	}
}

void longWait(double secondes) {
	double millisecondes = secondes * 10;
	for (double i = 0; i < millisecondes; i++) {
		Sleep(100);
		if (GetAsyncKeyState(VK_DOWN)) {
			return;
		}
	}
	return;
}

void clickForTwoHours() {
	cout << "commencement du cliquage pendant 2h" << endl;
	for (int i = 0; i < 120; i++) {
		SetCursorPos(739, 831);
		simpleClick();
		longWait(20);
		if (GetAsyncKeyState(VK_DOWN)) {
			return;
		}
		SetCursorPos(739, 831);
		simpleClick();
		longWait(40);
		if (GetAsyncKeyState(VK_DOWN)) {
			return;
		}
		randomTime(100);
		cout << "we are at i = " << i << " of i < 120" << endl;
	}
	cout << "fin du cliquage pendant 2h" << endl;
}

void clickForFiveMins() {
	for (int i = 0; i < 5; i++) {
		simpleClick();
		longWait(1);
		if (GetAsyncKeyState(VK_DOWN)) {
			return;
		}
		randomTime(100);
	}
}

void clickForThreeMins() {
	for (int i = 0; i < 3; i++) {
		SetCursorPos(739, 831);
		simpleClick();
		longWait(25);
		if (GetAsyncKeyState(VK_DOWN)) {
			return;
		}
		SetCursorPos(739, 831);
		simpleClick();
		longWait(35);
		if (GetAsyncKeyState(VK_DOWN)) {
			return;
		}
		randomTime(100);
	}
}