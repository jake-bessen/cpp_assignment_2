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
	cout << "List of words with more than three z's;" << endl;	
	for (std::vector<Word*>::iterator word = dictionary_vector.begin(); word != dictionary_vector.end(); ++word) {
		isThreeZees((*word)->getWord());
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

void Dictionary::printVerbNoun() {
	for (std::vector<Word*>::iterator word = dictionary_vector.begin(); word != dictionary_vector.end(); ++word) {
		if ((*word)->isVerb() && (*word)->isNoun()) {
			cout << (*word)->getWord() << endl;
		}
	}
}

void Dictionary::palendrome() {

	for (std::vector<Word*>::iterator word = dictionary_vector.begin(); word != dictionary_vector.end(); ++word) {
		if ((*word)->isPalendrome()) {
			cout << (*word)->getWord() << endl;
		}
	}
}

void Dictionary::anagram(string inputString){
	for (std::vector<Word*>::iterator word = dictionary_vector.begin(); word != dictionary_vector.end(); ++word) {
		if (	isAnagram(inputString, (*word)->getWord())	) {
			cout << (*word)->getWord() << endl;
		}
	}
}

bool Dictionary::isAnagram(string str1, string str2) {
	int count1[26] = {0};
	int count2[26] = {0};
	for (string::iterator i = str1.begin(); i != str1.end(); ++i) {
		count1[*i - 'a'] ++;
	}
	for (string::iterator i = str2.begin(); i != str2.end(); ++i) {
		count2[*i - 'a'] ++;
	}
	for (int i = 0 ; i < 26; i++) {
		if (count1[i] != count2[i])
			return false;
	}

	return true;
}

//loads and parses the dictionary file specified
void Dictionary::loadDictionary(string dictionaryFile) {
	ifstream myfile(dictionaryFile);
	string record , word , definition;
	cout << "loading dictionary . . .";
	if (myfile.is_open()) {
		int lineNumber = 1;	
		while (!myfile.eof()) {

			getline(myfile, record);
			if ((lineNumber % 4) == 1) {
				word = record;
			}
			else if ((lineNumber % 4) == 2) {
				definition = record;
			}
			else if ((lineNumber % 4) == 3) {
				Word * currentWord;
				string::iterator x = record.begin();
				string::iterator y = record.end();
				int recordType = (*x - 'a') * 100 + (*(y - 1) - 'a');
				switch (recordType)
				{
				case 2121: // Verb "vv" (v - a) * 100 + (v - a) = 2121
					currentWord = new Verb(word, definition);
					dictionary_vector.push_back(currentWord);
					break;
				case 1313: // Noun "nn" (n - a) * 100 + (n - a) = 1313
					currentWord = new Noun(word, definition);
					dictionary_vector.push_back(currentWord);
					break;
				case 9: // Adjective "aj" (a - a) * 100 + (j - a) = 0009
					currentWord = new Adjective(word, definition);
					dictionary_vector.push_back(currentWord);
					break;	
				case 21: // Adverb "av" (a - a) * 100 + (v - a) = 0021
					currentWord = new Adverb(word, definition);
					dictionary_vector.push_back(currentWord);
					break;
				case 1202: // MiscWord "mc" (m - a) * 100 + (c - a) = 1202
					currentWord = new MiscWord(word, definition);
					dictionary_vector.push_back(currentWord);
					break;
				case 1321: // NounAndVerb "nv" (n - a) * 100 + (v - a) = 1321
					currentWord = new NounAndVerb(word, definition);
					dictionary_vector.push_back(currentWord);
					break;
				case 1515: //Preposition "pp" (p - a) * 100 + (p - a) = 1515
					currentWord = new Preposition(word, definition);
					dictionary_vector.push_back(currentWord);
					break;	
				case 1513: //ProperNoun "pn" (p - a) * 100 + (p - a) = 1513
					currentWord = new ProperNoun(word, definition);
					dictionary_vector.push_back(currentWord);
					break;
				default:
					break;
				}
			}
			lineNumber++;
		}
	}
	myfile.close();
	system("CLS");
}
