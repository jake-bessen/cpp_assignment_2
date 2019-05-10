#include "guessingGame.h"

string guessingGame::retrieveGuess(string revealedLetters, string wordDefinition, int wordLength) 
{
	string guess = revealedLetters;
	int emptyLetters = wordLength - revealedLetters.length();
	cout << "definition; \n"
		<< wordDefinition << "\n"
		<< "_____________________\n"
		<< "clue: ";
	cout << revealedLetters;
	for (int i = 0; i < emptyLetters; i++) {
		cout << "-";
	}
	cout << endl << "Word:";
	cin >> guess;
	if (emptyLetters == 0) {
		system("pause");
	}
	system("CLS");
	return guess;
}

void guessingGame::guessingGameMenu(string Word, string definition) // state machine for guessing game
{	
	string guess;
	string revealedLetters;
	int wordLength = size(Word);
	bool correct;
	int x = 0;
	while (x != -1) {
		switch (x)	{
		case 0:
			guess = retrieveGuess(revealedLetters , definition, wordLength) ;
			system("CLS");
			if ( Word == guess ) {
				x = 3;
				correct = true;
			}
			else {
				x = 1;
				correct = false;
			}
			break;
		case 1:
			revealedLetters = Word[0];
			guess = retrieveGuess(revealedLetters , definition, wordLength) ;
			system("CLS");
			if ( Word == guess ) {
				x = 3;
				correct = true;
			}
			else {
				x = 2;
				correct = false; 
			}
			break;
		case 2:
			revealedLetters = { Word[0] , Word[1] };
			guess = retrieveGuess(revealedLetters , definition, wordLength) ;
			system("CLS");
			if ( Word == guess ) {
				x = 3;
				correct = true;
			}
			else {
				x = 3;
				correct = false;
			}
			break;
		case 3:
			if (correct) {
				cout << "Correct!" << endl;
			}
			else {
				cout << "Wrong!" << endl;
			}
			cout << "Word: " << Word << endl;
			cout << "Definition: "<< definition << endl;
			system("pause");
			system("CLS");
			x = -1;
			break;
		}
	}
}
