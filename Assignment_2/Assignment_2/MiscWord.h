#ifndef MISCWORD_H
#define MISCWORD_H

#include "Word.h"
class MiscWord : virtual public Word {
public:
	MiscWord() {}
	MiscWord(string, string);
	string getDefinition();
};

#endif
