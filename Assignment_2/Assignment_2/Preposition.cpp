#include "Preposition.h"



Preposition::Preposition() {
}

Preposition::Preposition(string inWord, string inDefinition) : Word(inWord, inDefinition)
{
}

string Preposition::getDefinition() {
	return "(prep) " + definition;
}


