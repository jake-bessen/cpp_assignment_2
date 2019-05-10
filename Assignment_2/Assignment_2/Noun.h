#ifndef NOUN_H
#define NOUN_H

#include "Word.h"
class Noun : virtual public Word {
public:
	Noun() {}
	Noun(string, string);
	bool isNoun();
	string getDefinition();
};

#endif
