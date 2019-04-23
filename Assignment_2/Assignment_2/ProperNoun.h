#pragma once
#include "Noun.h"
class ProperNoun : virtual public Noun {
public:
	ProperNoun();
	ProperNoun(string, string);
	string getWord();
	string getDefinition();
};

