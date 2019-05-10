#ifndef TRIGRAM_H
#define TRIGRAM_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Trigram
{
public:
	Trigram();
	void loadString(string);
	void computeLookupTables();
	void trigramMenu();
	void threeMostLikely();
private:
	void populateCumulativeTable(int, int);
	void populateProbability(int, int);
	void populateOrderedList(int, int);
	string produceFakeWord();
	string randLetter(int, int, double, bool);
	void getThreeMostLikely(int, int);
	int returnIndex(char);
	char returnChar(int);
	int stringConvert(char xChar[2]);

	int index[27][27][27] = { 0 };
	int orderLikelyhood[27][27][27] = { 0 }; //Example output; likelyhood(1,1) = [-1 -1 -1 . . . -1 19 0 24 19 2]
	double lookupTable[27][27][27] = { 0 }; //Example output; Y(1,1) = [0 0 0 0.4 0 . . . 0.3 . . . 0.24 0 . . . 0 0.16 0]
	double cumulativeLookupTable[27][27][27] = { 0 }; //example output; Y(1,1) = [0 0.25 0.27 0.27 . . . 0.27 0.27 0.27 0.27 0.8 1]
	unsigned int seed = 1;
};

#endif