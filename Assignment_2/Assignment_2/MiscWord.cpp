#include "MiscWord.h"

MiscWord::MiscWord(string inWord, string inDefinition) : Word(inWord, inDefinition) {

}

string MiscWord::getDefinition()
{
	return "(misc.) " + definition;
}
