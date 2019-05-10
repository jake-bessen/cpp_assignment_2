#include "Dictionary.h"

Dictionary::Dictionary() {}

//Iterates through dictionary vector and returns pointer to word object for the string passed in or null if the word doesn't exist
Word* Dictionary::findWord(string searchWord) 
{
	string test_word;
	for (std::vector<Word*>::iterator pDictionaryVector = dictionary_vector.begin(); pDictionaryVector != dictionary_vector.end(); ++pDictionaryVector) {
		test_word = (*pDictionaryVector)->getWord();
		if (test_word == searchWord) {
			return (*pDictionaryVector);
		}
	}
	return nullptr;
}

void Dictionary::processTrigrams() // Loads entire dictionary into index
{
	cout << "Processing Trigrams . . .";
	for (std::vector<Word*>::iterator pDictionaryVector = dictionary_vector.begin(); pDictionaryVector != dictionary_vector.end(); ++pDictionaryVector) {
		loadString((*pDictionaryVector)->getWord());
	}
	computeLookupTables(); // Processes Index into various lookup tables
	system("CLS");
}

//Iterates through dictionary vector and runs function isQu to determine if a word has q without folloing u. 
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

void Dictionary::printVerbNoun() //iterates through dictionary vector and prints a word if (bool) isVerb * isNoun = true
{
	for (std::vector<Word*>::iterator word = dictionary_vector.begin(); word != dictionary_vector.end(); ++word) {
		if ((*word)->isVerb() && (*word)->isNoun()) {
			cout << (*word)->getWord() << endl;
		}
	}
}

void Dictionary::palendrome() // Itterates through dictionary vector and prints if isPalendome = true 
{
	for (std::vector<Word*>::iterator word = dictionary_vector.begin(); word != dictionary_vector.end(); ++word) {
		if ((*word)->isPalendrome()) {
			cout << (*word)->getWord() << endl;
		}
	}
}

void Dictionary::anagram(string inputString) // Itterates through dictionary vector and prints word if isAnagram returns true for input word
{
	for (std::vector<Word*>::iterator word = dictionary_vector.begin(); word != dictionary_vector.end(); ++word) {
		if (	isAnagram(inputString, (*word)->getWord())	) {
			cout << (*word)->getWord() << endl;
		}
	}
}

 // counts instances of each character for strings 1 & 2 then returns true if the number of instances in each string matches
bool Dictionary::isAnagram(string str1, string str2)
{
	int count1[27] = {0};
	int count2[27] = {0};
	for (string::iterator i = str1.begin(); i != str1.end(); ++i) {
		count1[returnIndex(*i)] ++;
	}
	for (string::iterator j = str2.begin(); j != str2.end(); ++j) {
		count2[returnIndex(*j)] ++;
	}
	for (int k = 0 ; k < 27; k++) {
		if (count1[k] != count2[k]) {
			return false;
		}
	}

	return true;
}

int Dictionary::returnIndex(char a) // returns index value between zero and 26 from char input
{
	int index = 0;
	int currentCharCode = (int)a;
	if (currentCharCode == (int)' ') {
		index = 0;
	}
	else if ('a' <= currentCharCode && currentCharCode <= 'z') {
		index = currentCharCode - 'a' + 1;
	}
	return index;
}

void Dictionary::loadGuessingGame() //Picks random verb from verb vector then passes it into guessing game ui.
{
	srand(time(NULL));
	int length = size(verb_vector), wordPosition;
	// bit shift rand() to generate larger random number
	wordPosition = ( long(rand() << 15) + rand() ) % length;
	Word* pVerb = verb_vector[wordPosition];
	guessingGameMenu(pVerb->getWord(),pVerb->getDefinition());
	seed++;
}

void Dictionary::populateVerbVector() // populates vector of verbs used in guessing game
{
	Word* currentVerb;
	for (std::vector<Word*>::iterator pDictionaryVector = dictionary_vector.begin(); pDictionaryVector != dictionary_vector.end(); ++pDictionaryVector) {
		if ((*pDictionaryVector)->isNoun()) {
			currentVerb = *pDictionaryVector;
			verb_vector.push_back(currentVerb);
		}
	}
}

//loads and parses the dictionary file specified
void Dictionary::loadDictionary(string dictionaryFile) 
{
	ifstream myfile(dictionaryFile);
	string record, word = "", definition = "-";
	Word * currentWord;
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
				int wordType = returnCodedType(  record.begin() , record.end()  );
				switch (wordType)
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

int Dictionary::returnCodedType(string::iterator start, string::iterator end ) //returns unique int for verb, noun etc. for use in switch statement
{
	int codedType = (*start - 'a') * 100 + (*(end - 1) - 'a');
	return codedType;
}

void Dictionary::getTotalNumberOfWords() //Prints the size of the dictionary vector
{
	cout << "The dictionary has: " << endl <<size(dictionary_vector) << " word definitions." << endl;
}