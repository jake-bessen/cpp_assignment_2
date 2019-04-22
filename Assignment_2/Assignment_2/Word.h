#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Word {
public:
	Word();
	~Word();
	string getWord();
	void setWord(string);
	string getDefinition();
	void setDefinition(string);
	void printDefinition();
	bool isPalendrome();
	virtual bool isVerb();
	virtual bool isNoun();
private:
	string word;
	string definition;
};

#endif