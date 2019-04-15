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
	string getType();
	void setType(string);
	void printDefinition();
private:
	string word;
	string definition;
	string type;
};

#endif