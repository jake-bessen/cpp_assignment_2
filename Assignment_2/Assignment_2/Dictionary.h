#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Trigram.h"
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

class Dictionary : public Trigram {
public:
	Dictionary();
	~Dictionary();
	Word* findWord(string);
	void loadTrigram();
	void findQu();
	void threeZees();
	void printVerbNoun();
	void palendrome();
	void anagram(string);	
	void loadDictionary(string);
	void getTotalNumberOfWords();
private:
	void isQu(string);
	void isThreeZees(string);
	bool isAnagram(string, string);
	vector<Word*> dictionary_vector;
};

#endif
