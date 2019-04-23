#include "Adjective.h"



Adjective::Adjective(string inWord, string inDefinition) : Word(inWord, inDefinition) {

}


string Adjective::getDefiniton()
{

	return "(adj.) " + definition;
}
