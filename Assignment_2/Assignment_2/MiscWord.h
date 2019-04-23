#pragma once
#include "Word.h"
class MiscWord : virtual public Word {
public:
	MiscWord() {}
	MiscWord(string, string);
	string getDefinition();
};

