#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Word.h"
#include "Verb.h"
using namespace std;

class Dictionary {
public:
	Dictionary();
	~Dictionary();
	Word* findWord(string);
	void findQu();
	void isQu(string);
	void threeZees();
	void isThreeZees(string);
	void loadDictionary(string);
private:
	vector<Word*> dictionary_vector;
};

#endif
