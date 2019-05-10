#ifndef ADVERB_H
#define ADVERB_H


#include "Word.h"
class Adverb : public Word {
public:
	Adverb(string, string);
	string getDefinition();
};

#endif

