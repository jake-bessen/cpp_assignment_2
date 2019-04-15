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

string Word::getType() {
	return string();
}

void Word::setType(string intype)
{
	type = intype;
}

void Word::printDefinition() {
	cout << getDefinition() << endl;
}