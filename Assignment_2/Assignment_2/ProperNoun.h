#pragma once
#include "Noun.h"
class ProperNoun : public Noun {
public:
	ProperNoun();
	ProperNoun(string, string);
	string getWord();
	string getDefinition();
};

