#pragma once
#include "Word.h"
class Verb : virtual public Word
{
public:
	Verb() {}
	Verb( string , string );
	bool isVerb();
	string getDefinition();
};

