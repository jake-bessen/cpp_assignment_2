#include "Trigram.h"

Trigram::Trigram() {}

void Trigram::loadString(string testString) // Loads a string into the index matrix.  
{
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

int Trigram::returnIndex(char a) // returns index value between zero and 26 from char input
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

char Trigram::returnChar(int index) // Returns character from index value
{
	char indexChar = ' ';
	if(index == 0) {
		indexChar = ' ';
	}
	else {
		indexChar = index - 1 + 'a';
	}
	return indexChar;
}

void Trigram::computeLookupTables() //Itterates through index matrix and creates ordered matrix, 
// probability matrix and cumulative probability matrix.  
{
	for (int row = 0; row < 27; row++) {
		for (int column = 0; column < 27; column++) {
			populateOrderedList(row, column);
			populateProbability(row, column);
			populateCumulativeTable(row, column);
		}
	}
}

void Trigram::populateProbability(int row, int column) //Prob(x, y , i1) = Index(x , y , i1 ) / sum( Index( x , y , i1 ) ... Index(x , y , in) ) 
{
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

void Trigram::populateOrderedList(int row, int  column) { // creates a lookup table for the ordered most likely letters 
	int j, x, y;
	int prob[27] = { 0 };
	int letter[27] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26 }; 
	for (int i = 0; i < 27; i++) {
		prob[i] = index[row][column][i];
		if (index[row][column][i] == 0) {
			letter[i] = -1;
		}
	}
	// Insertion sorting algorithm implemetation
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
	// places sorted list into ordered likelyhood lookup table 
	for (int i = 0; i < 27; i++) {
		orderLikelyhood[row][column][i] = letter[i];
	}
}

string Trigram::produceFakeWord() { // generates a fake word by randomly generating letters. The likelyhood of a particular letter being chosen is weighted according to its trigram probability
	srand(seed);
	seed++;
	double random = (rand() % 100) * 0.01;
	string fakeWord = "a";

	// The first letter is generated
	fakeWord[0] = returnChar(rand() % 26 + 1); // (1)

	// returns the second letter based on " x" combination
	fakeWord = fakeWord + randLetter(returnIndex(' '), returnIndex(fakeWord[0]), random, false ); 

	// continues ammending random letters to string until "x " combination,
	while (*(fakeWord.end()-1) != ' ') {
		int letterCount = 0;
		random = (rand() % 100) * 0.01;
		// if the word gets too long, look for any likely ending
		if (letterCount < 2) {
			fakeWord = fakeWord + randLetter(  returnIndex(*(fakeWord.end() - 2)),  returnIndex(*(fakeWord.end() - 1)), random, false  );
		}
		else {
			fakeWord = fakeWord + randLetter(  returnIndex(*(fakeWord.end() - 2)),  returnIndex(*(fakeWord.end() - 1)), random, true  );
		}
		
		letterCount++;
	}
	return fakeWord;
}

string Trigram::randLetter(int letter1, int letter2, double randomNumber, bool makeItStop) {
	// Using the cumulative probability table a letter is randomly chosen, with letters that have a higher likelyhood
	// more likely to be picked 
	string outputString = "a";
	if ( (makeItStop == true)  &  (0.1 < cumulativeLookupTable[letter1][letter2][0])  ) {
		outputString[0] = returnChar(0);
		return outputString;
	}
	else { // looks for where the random number between 0 and 1 fits in the cumulative distribution
		for (int i = 0; i < 27; i++) {
			if (randomNumber < cumulativeLookupTable[letter1][letter2][i] && makeItStop == false) {
				outputString[0] = returnChar(i);
				return outputString;
			}
		}
	}
	return outputString;
}

void Trigram::trigramMenu() // state machine for UI
{
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
		default:
			x = 0;

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

void Trigram::getThreeMostLikely(int row, int column) // Prints to screen the three most likely following letters from orderedLikelyhood lookup table based on the input index. Also prints the respective probabilities
{ 
	cout << "1) \"" << returnChar(orderLikelyhood[row][column][26]) << "\" ";
	cout << "P(" << returnChar(orderLikelyhood[row][column][26]) << "|" << returnChar(row) << returnChar(column) << ")" << " = " << lookupTable[row][column][  orderLikelyhood[row][column][26]  ] << endl;
	
	cout << "2) \"" << returnChar(orderLikelyhood[row][column][25]) << "\" ";
	cout << "P(" << returnChar(orderLikelyhood[row][column][25]) << "|" << returnChar(row) << returnChar(column) << ")" << " = " << lookupTable[row][column][  orderLikelyhood[row][column][25]  ] << endl;
	
	cout << "3) \"" << returnChar(orderLikelyhood[row][column][24]) << "\" ";
	cout << "P(" << returnChar(orderLikelyhood[row][column][24]) << "|" << returnChar(row) << returnChar(column) << ")" << " = " << lookupTable[row][column][  orderLikelyhood[row][column][24]  ] << endl;
}

int Trigram::stringConvert(char xChar[2]) // Improves trigram menu item selection robustness.  
{ 
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
