#include "Trigram.h"

Trigram::Trigram() {}

void Trigram::loadString(string testString) {
	int	rowIndex, columnIndex, resultIndex;
	testString = ' ' + testString + ' ';
	for (string::iterator i = testString.begin(); i <= testString.end() - 3; i++) {
		rowIndex = returnIndex(*i);
		columnIndex = returnIndex(*(i + 1));
		// -------------------------
		resultIndex = returnIndex(*(i + 2));
		if (rowIndex != -1 && columnIndex != -1 && resultIndex != -1) {
			index[rowIndex][columnIndex][resultIndex]++;
		}
	}
}

int Trigram::returnIndex(char a)
{
	int index = -1;
	int currentCharCode = (int)a;
	if (currentCharCode == (int)' ') {
		index = 0;
	}
	else if ('a' <= currentCharCode && currentCharCode <= 'z') {
		index = currentCharCode - 'a' + 1;
	}
	return index;
}

char Trigram::returnChar(int index){
	char indexChar = ' ';
	if(index == 0) {
		indexChar = ' ';
	}
	else {
		indexChar = index - 1 + 'a';
	}
	return indexChar;
}

void Trigram::normaliseIndex() {
	for (int row = 0; row < 27; row++) {
		for (int column = 0; column < 27; column++) {
			populateOrderedList(row, column);
			populateProbability(row, column);
			populateCumulativeTable(row, column);
		}
	}
}

void Trigram::populateProbability(int row, int column) {
	int sumMN = 0;
	double sum = 0;
	for (int i = 0; i < 27; i++) {
		sumMN = sumMN + index[row][column][i];
	}
	for (int i = 0; i < 27; i++) {
		if (sumMN != 0) {
			lookupTable[row][column][i] = (double)index[row][column][i] / sumMN;
		}
	}
}

void Trigram::populateCumulativeTable(int row, int column){
	cumulativeLookupTable[row][column][0] = lookupTable[row][column][0];
	for (int i = 1; i < 27; i++) {
		cumulativeLookupTable[row][column][i] = cumulativeLookupTable[row][column][i - 1] + lookupTable[row][column][i];
	}
}

void Trigram::populateOrderedList(int row, int  column) {
	int j, x, y;
	int prob[27] = { 0 };
	int letter[27] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26 }; 
	for (int i = 0; i < 27; i++) {
		prob[i] = index[row][column][i];
		if (index[row][column][i] == 0) {
			letter[i] = -1;
		}
	}
	// Sorting algorithm
	for (int i = 0; i < 27; i++) {
		x = prob[i];
		y = letter[i];
		j = i - 1;
		while (j >= 0 && prob[j] > x) {
			prob[j + 1] = prob[j];
			letter[j + 1] = letter[j];
			j = j - 1;
		}
		prob[j + 1] = x;
		letter[j + 1] = y;
	}
	// Insert element into table 
	for (int i = 0; i < 27; i++) {
		orderLikelyhood[row][column][i] = letter[i];
	}
}

string Trigram::produceFakeWord() {
	srand(seed);
	seed++;
	char randomChar = rand() % 26 + 2 + 'a';
	double random = (rand() % 100) * 0.01;
	string fakeWord = "-";
	fakeWord[0] = randomChar;
	fakeWord = fakeWord + randLetter(returnIndex(' '), returnIndex(fakeWord[0]), random, false );
	while (*(fakeWord.end()-1) != ' ') {
		int letterCount = 2;
		random = (rand() % 100) * 0.01;
		if (letterCount < 5) {
			fakeWord = fakeWord + randLetter(returnIndex(*(fakeWord.end() - 2)), returnIndex(*(fakeWord.end() - 1)), random, false);
		}
		else if (letterCount >= 5 && letterCount << 20){
			fakeWord = fakeWord + randLetter(returnIndex(*(fakeWord.end() - 2)), returnIndex(*(fakeWord.end() - 1)), random, true);
		}
		
		letterCount++;
	}
	return fakeWord;
}

string Trigram::randLetter(int letter1, int letter2, double randomNumber, bool makeItStop) {
	string outputString = "-";
	if (makeItStop != 0 && cumulativeLookupTable[letter1][letter2][0] > 0.1) {
		outputString[0] = returnChar(0);
		return outputString;
	}
	else {
		for (int i = 0; i < 27; i++) {
			if (randomNumber < cumulativeLookupTable[letter1][letter2][i] && makeItStop == false) {
				outputString[0] = returnChar(i);
				return outputString;
			}
		}
	}
	return outputString;
}

void Trigram::trigramMenu(){
	int x = 0;
	char xChar[50];
	while (x != -1) {
		switch (x) {
		case 0:
			cout << "Trigram Menu \n"
				<< "--------------- \n"
				<< "1) List fake words \n"
				<< "2) Find letter comination \n"
				<< "3) Exit \n\n"
				<< "Please enter a menu item: ";
			cin >> xChar;
			x = stringConvert(xChar);
			system("CLS");
			break;
		case 1:
			for (int i = 0; i < 50; i++) {
				cout << produceFakeWord() << endl;
			}
			system("pause");
			system("CLS");
			x = 0;
			break;
		case 2:
			threeMostLikely();
			system("pause");
			system("CLS");
			x = 0;
			break;
		case 3:
			x = -1;
			break;
		}
	}
}

void Trigram::threeMostLikely(){
	string searchWord;
	cout << "Enter two letter combination: ";
	cin >> searchWord;
	cout << endl;
	getThreeMostLikely( returnIndex(searchWord[0])  ,   returnIndex(searchWord[1]) );
}

void Trigram::getThreeMostLikely(int row, int column){
	cout << "1) \"" << returnChar(orderLikelyhood[row][column][26]) << "\" ";
	cout << "P(" << returnChar(orderLikelyhood[row][column][26]) << "|" << returnChar(row) << returnChar(column) << ")" << " = " << lookupTable[row][column][ orderLikelyhood[row][column][26] ] << endl;
	
	cout << "2) \"" << returnChar(orderLikelyhood[row][column][25]) << "\" ";
	cout << "P(" << returnChar(orderLikelyhood[row][column][25]) << "|" << returnChar(row) << returnChar(column) << ")" << " = " << lookupTable[row][column][ orderLikelyhood[row][column][25] ] << endl;
	
	cout << "3) \"" << returnChar(orderLikelyhood[row][column][24]) << "\" ";
	cout << "P(" << returnChar(orderLikelyhood[row][column][24]) << "|" << returnChar(row) << returnChar(column) << ")" << " = " << lookupTable[row][column][ orderLikelyhood[row][column][24] ] << endl;
}

int Trigram::stringConvert(char xChar[2]) {
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
