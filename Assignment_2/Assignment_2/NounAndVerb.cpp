#include "NounAndVerb.h"



NounAndVerb::NounAndVerb(string inName, string inDefinition) : Word(inName, inDefinition){
}

string NounAndVerb::getDefinition()
{
	return "(n.v.) " + definition;
}
