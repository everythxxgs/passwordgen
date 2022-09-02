
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include <conio.h>
#include <dos.h>
#include <windows.h>
#include <time.h>
#include <string.h>

using namespace std;

int main()
{
	char dec;
	std::cout << "Generate or check?" << endl;
	cin >> dec;
	srand((unsigned)time(NULL));
	system("cls");
	if (dec == 'g') {
		char characters[] = "qwertzuioplkjhgfdayxcvbnmQWERTZUIOPLKJHGFDSAYXCVBNM";
		char numbers[] = "0123456789";
		char symbols[] = "~!@#$%^&*()_-+={[}]|\'<,>.?/";
		string password;
		int length, cNum, nNum, sNum;
		bool charactersTick, numbersTick, symbolsTick;

		ofstream out_file;

		out_file.open("Password.txt");

		std::cout << "Enter the number of digits for your password " << endl;
		cin >> length;

		std::cout << "Enter true if characters should be included " << endl;
		cin >> charactersTick;

		std::cout << "Enter true if numbers should be included " << endl;
		cin >> numbersTick;

		std::cout << "Enter true if symbols should be included " << endl;
		cin >> symbolsTick;

		

		for (int i = 1; i <= length; i++)
		{

			switch (rand() % 3) {
			case 1:
				if (charactersTick == 1) {
					cNum = rand() % 52;

					out_file << characters[cNum];
					i++;
				}

			case 2:

				if (numbersTick == 1) {
					nNum = rand() % 10;

					out_file << numbers[nNum];
					i++;
				}

			case 3:
				if (symbolsTick == 1) {
					sNum = rand() % 28;

					out_file << symbols[sNum];
					i++;
				}

			}
			i--;
		}

		cout << "Done\n";
	}
	else
	{
		char password[50];

		std::cout << "Enter your Password 50 Chars " << endl;
		cin >> password;

		int baseScore = 50;
		
		char pass[50] = "";
		int excess = strlen(password) - 6;
		int numUpper = 0;
		int numSymbol = 0;
		int numLower = 0;
		int numDigit = 0;

		int bonusExcess = 3;
		int bonusUpper = 4;
		int bonusNumbers = 5;
		int bonusSymbols = 5;
		int bonusCombo = 0;
		int bonusFlatLower = 0;
		int bonusFlatNumber = 0;

		for (int i = 0; i<strlen(password); i++)
		{
			if( password[i] >= 48 && password [i] <= 57)
			{//0-9
				numDigit++;
			}
			if (password[i] >= 97 && password[i] <= 125)
			{//a-z
				numLower++;
			}
			if (password[i] >= 65 && password[i] <= 90)
			{//A-Z
				numUpper++;
			}
			if (password[i] >= 33 && password[i] <= 47)
			{//symbols
				numSymbol++;
			}
		}
		if (numUpper>0 && numDigit> 0 && numSymbol>0)
		{
			bonusCombo = 25;
		}

		else if ((numUpper > 0 && numDigit > 0) || (numUpper > 0 && numSymbol > 0) || (numSymbol > 0 && numDigit > 0))
		{
			bonusCombo = 15;
		}
		int score = baseScore + (excess * bonusExcess) + (numUpper * bonusUpper) + (numDigit * bonusNumbers) + (numSymbol * bonusSymbols) + bonusCombo + bonusFlatLower + bonusFlatNumber;

		if (score < 50) {
			cout << "Password Status: Weak";
		}
		else if (score >= 50 && score < 75) {
			cout << "Password Status: Average";
		}
		else if (score >= 75 && score < 100) {
			cout << "Password Status: Strong";
		}
		else if (score >= 100) {
			cout << "Password Status: Godlike";
		}
	}
	return 0;

}
