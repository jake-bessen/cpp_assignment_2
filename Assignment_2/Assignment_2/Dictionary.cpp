#include "Dictionary.h"


Dictionary::Dictionary() {}

Dictionary::~Dictionary() {}

//iterates through dictionary vector and returns pointer to word object for the string passed in or null if the word doesn't exist
Word* Dictionary::findWord(string searchWord) {
	string test_word;
	for (std::vector<Word*>::iterator pDictionaryVector = dictionary_vector.begin(); pDictionaryVector != dictionary_vector.end(); ++pDictionaryVector) {
		test_word = (*pDictionaryVector)->getWord();
		if (test_word == searchWord) {
			return (*pDictionaryVector);
		}
	}

	return nullptr;
}

//iterates through dictionary vector and runs function isQu to determine if a word has q without folloing u. 
void Dictionary::findQu() {
	string testWord;
	cout << "list of words with q without following u;" << endl;

	for (std::vector<Word*>::iterator pDictionaryVector = dictionary_vector.begin(); pDictionaryVector != dictionary_vector.end(); ++pDictionaryVector) {
		testWord = (*pDictionaryVector)->getWord();
		isQu(testWord);
	}
}

// itterates through test_word and prints if it has a q without folling u.  
void Dictionary::isQu(string test_word) {
	// following " " allows for words where q is the final letter.
	test_word = test_word + " ";
	for (string::iterator i = test_word.begin(); i != test_word.end(); ++i) {
		if ((*i) == 'q' && (*(i + 1)) != 'u') {
			cout << test_word << endl;
		}
	}
}

//iterates through dictionary vector and runs function isThreeZees to determine if a word has more than 3 z's. 
void Dictionary::threeZees() {
	string testWord;

	cout << "List of words with more than three z's;" << endl;
	for (std::vector<Word*>::iterator word = dictionary_vector.begin(); word != dictionary_vector.end(); ++word) {
		testWord = (*word)->getWord();
		isThreeZees(testWord);
	}
}

// iterates through input word, counts the number of z's and prints the word if the number is greater than 3. 
void Dictionary::isThreeZees(string testWord) {
	int numberOfZees = 0;
	for (string::iterator i = testWord.begin(); i != testWord.end(); ++i) {
		if ((*i) == 'z') {
			numberOfZees++;
		}
		if (numberOfZees >= 3) {
			cout << testWord << endl;
			i = (testWord.end() - 1);
		}
	}
	numberOfZees = 0;
}

//loads and parses the dictionary file specified
void Dictionary::loadDictionary(string dictionaryFile) {
	ifstream myfile(dictionaryFile);
	string record;
	cout << "loading dictionary . . .";
	if (myfile.is_open()) {
		Word *currentWord = new Word;
		int lineNumber = 1;
		while (!myfile.eof()) {
			getline(myfile, record);
			if ((lineNumber % 4) == 1) {
				currentWord->setWord(record);
			}
			else if ((lineNumber % 4) == 2) {
				currentWord->setDefinition(record);
			}
			else if ((lineNumber % 4) == 3) {
				for () {
					
				}
				switch (record[0]) {
				case 1: // Verb
					Verb * currentVerb = new Verb
					
					dictionary_vector.push_back(currentWord);
					break;
				}
				dictionary_vector.push_back(currentWord);
				currentWord = new Word;
			}
			lineNumber++;
		}
	}
	myfile.close();
	system("CLS");
}
