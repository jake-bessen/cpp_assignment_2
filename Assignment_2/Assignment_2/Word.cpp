#include "Word.h"
using namespace std;
Word::Word() {}

Word::~Word() {}

string Word::getWord() {
	return word;
}

void Word::setWord(string inName) {
	word = inName;
}

string Word::getDefinition() {
	return definition;
}

void Word::setDefinition(string inDefinition) {
	definition = inDefinition;
}

void Word::printDefinition() {
	cout << getDefinition() << endl;
}

bool Word::isPalendrome() {
	string reverseWord = word;
	reverse(reverseWord.begin(),reverseWord.end());
	for (string::iterator i = word.begin(); i != word.end(); ++i) {
		if (*i != *(reverseWord.begin()+(i - word.begin())) || word.length() == 1) {
			return false;
		}
	}
	return true;
}

bool Word::isVerb() {
	return false;
}

bool Word::isNoun() {
	return false;
}