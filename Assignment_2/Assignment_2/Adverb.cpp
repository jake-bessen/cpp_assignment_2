#include "Adverb.h"

Adverb::Adverb(string inWord, string inDefinition) : Word(inWord, inDefinition){

}


string Adverb::getDefinition()
{
	return "(adv.) " + definition;
}
