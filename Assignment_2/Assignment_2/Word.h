#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Word {
public:
	Word ();
	Word ( string , string );
	~Word ();
	virtual string getWord();
	void setWord(string);
	virtual string getDefinition();
	void setDefinition(string);
	void printDefinition();
	bool isPalendrome();
	virtual bool isVerb();
	virtual bool isNoun();
protected:
	string word;
	string definition;
};

#endif