#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Word.h"
#include "Verb.h"
#include "Noun.h"
#include "Adjective.h"
#include "Adverb.h"
#include "MiscWord.h"
#include "NounAndVerb.h"
#include "Preposition.h"
#include "ProperNoun.h"
using namespace std;

class Dictionary {
public:
	Dictionary();
	~Dictionary();
	Word* findWord(string);
	void findQu();
	void isQu(string);
	void threeZees();
	void printVerbNoun();
	void isThreeZees(string);
	void palendrome();
	void anagram(string);	
	bool isAnagram(string, string);
	void loadDictionary(string);
private:
	vector<Word*> dictionary_vector;
};

#endif
