// Jake Bessen - CSP2104 Assignment 1
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Dictionary.h"
using namespace std;

// Returns int value only if arbitary input string is an int value between 0 and 9
int stringConvert(char xChar[2]) {
	int x;
	int xMat[2] = { xChar[0] - '0', xChar[1] };
	if (xMat[0] >= 0 && xMat[0] <= 9 && xMat[1] == 0) {
		x = xMat[0];
	}
	else {
		x = 0;
	}
	return x;
}

int main() {
	// Dictionary object declared and dictionary file loaded
	Dictionary dictionary;
	dictionary.loadDictionary("dictionary2019.txt");

	//state machine variable declearations
	int x = 0;
	char x_char[50];
	string search;
	Word* pSearchWord;
	// state machine for menu
	while (x != -1) {
		switch (x)
		{
		case 0:
			
			cout << "Main Menu \n"
				<< "----------------------------------------------------- \n"
				<< "1) Dictionary \n"
				<< "2) List words with three or more z's \n"
				<< "3) List words with the letter q without a following u \n"
				<< "4) List Words that are both a noun and a verb \n"
				<< "5) List words that are palindromes \n"
				<< "6) Anagram generator \n"
				<< "7) Guessing game \n"
				<< "8) Fun with Tri-Grams \n"
				<< "9) Exit \n"
				<< endl;
			cout << "\nPlease enter menu item: ";

			// Menu input with string conversion function for robustness
			cin >> x_char;
			x = stringConvert(x_char);
			system("CLS");
			break;
		case 1:
			// Dictionary search menu
			cout << "please enter search word:" << endl;
			cin >> search;
			system("CLS");
			pSearchWord = dictionary.findWord(search);
			//exception handling for null pointer return
			if (pSearchWord != nullptr) {
				cout << pSearchWord->getWord() << endl;
				cout << "Definition: " << pSearchWord->getDefinition() << endl;
			}
			else {
				cout << "Word not found" << endl;
			}
			system("pause");
			system("CLS");
			x = 0;
			break;
		case 2:
			// Three z's function menu
			dictionary.threeZees();
			system("pause");
			system("CLS");
			x = 0;
			break;
			
		case 3:
			//Q without folling u menu
			dictionary.findQu();	
			system("pause");
			system("CLS");
			x = 0;
			break;
		
		case 4:
			cout << "The following words are verbs as well as nouns" << endl;
			dictionary.printVerbNoun();
			system("pause");
			system("CLS");
			x = 0;
			break;
		case 5:
			cout << "The following words are palendromes" << endl;
			dictionary.palendrome();
			system("pause");
			system("CLS");
			x = 0;
			break;
		case 6:
			cout << "Please enter anagram search word: ";
			cin >> search;;
			cout << endl;
			dictionary.anagram(search);
			system("pause");
			system("CLS");
			x = 0;
			break;
		case 7:
			
			system("pause");
			system("CLS");
			x = 0;
			break;
		case 8:
			
			system("pause");
			system("CLS");
			x = 0;
			break;
		case 9:
			// Program exit functionality 
			char exit[50];
			cout << "are you sure you want to exit? y/n" << endl;
			cin >> exit;
			if (exit[0] == 'y'&& exit[1] == '\0') {
				x = -1;
			}
			else if (exit[0] == 'n' && exit[1] == '\0') {
				x = 0;
				system("CLS");
			}
			else {
				x = 9;
				system("CLS");
			}
			break;
		default:
			// Resets state value if input is invalid
			x = 0;
		}
	}
	return 0;
}