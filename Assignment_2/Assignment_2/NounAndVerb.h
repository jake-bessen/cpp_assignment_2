#ifndef NOUNANDVERB_H
#define NOUNANDVERB_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Noun.h"
#include "Verb.h"


class NounAndVerb : public Noun, public Verb{
public:
	NounAndVerb(string, string);
	string getDefinition();
};

#endif
