#include "ProperNoun.h"


ProperNoun::ProperNoun()
{
}

ProperNoun::ProperNoun(string inWord, string inDefinition) : Word(inWord, inDefinition)
{
}

string ProperNoun::getWord(){
	string capitalWord = word;
	string::iterator i = capitalWord.begin();
	*i = (*i - 'a') + 'A';

	return capitalWord;
}

string ProperNoun::getDefinition()
{
	return "(pn.) " + definition;
}
