#ifndef ADJECTIVE_H
#define	ADJECTIVE_H


#include "Word.h"
class Adjective : public Word
{
public:
	Adjective(string, string);
	string getDefiniton();
};
#endif