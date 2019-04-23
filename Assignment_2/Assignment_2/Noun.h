#pragma once
#include "Word.h"
class Noun : virtual public Word {
public:
	Noun() {}
	Noun(string, string);
	bool isNoun();
	string getDefinition();
};

