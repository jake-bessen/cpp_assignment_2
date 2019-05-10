#ifndef PROPERNOUN_H
#define PROPERNOUN_H

#include "Noun.h"
class ProperNoun : virtual public Noun {
public:
	ProperNoun();
	ProperNoun(string, string);
	string getWord();
	string getDefinition();
};
#endif
