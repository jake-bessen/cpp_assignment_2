#include "Verb.h"



Verb::Verb( string inName , string inDefinition ) : Word( inName , inDefinition ){
	
}


bool Verb::isVerb() {
	return true;
}

string Verb::getDefinition()
{
	return "(v.) " + definition;
}
