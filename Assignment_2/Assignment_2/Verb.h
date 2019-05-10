#ifndef VERB_H
#define VERB_H
#include "Word.h"
class Verb : virtual public Word
{
public:
	Verb() {}
	Verb( string , string );
	bool isVerb();
	string getDefinition();
};
#endif
