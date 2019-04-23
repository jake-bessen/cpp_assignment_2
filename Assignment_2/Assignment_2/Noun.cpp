#include "Noun.h"

Noun::Noun(string inName, string inDefinition) : Word(inName, inDefinition)
{
}

bool Noun::isNoun() {
	return true;
}

string Noun::getDefinition()
{
	return "(n.) " + definition;
}
