#ifndef PREPOSITION_H
#define PREPOSITION_H

#include "MiscWord.h"
class Preposition : public MiscWord {
public:
	Preposition();
	Preposition(string, string);
	string getDefinition();
};

#endif
