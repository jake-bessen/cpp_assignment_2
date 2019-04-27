#pragma once
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
	int returnIndex(char);
	void loadString(string);
	char returnChar(int);
	void normaliseIndex();
	void populateCumulativeTable(int, int);
	void populateProbability(int, int);
	void populateOrderedList(int, int);
	string produceFakeWord();
	string randLetter(int, int, double, bool);
	void trigramMenu();
	void threeMostLikely();
	void getThreeMostLikely(int, int);
protected:

private:
	int stringConvert(char xChar[2]);

	int index[27][27][27] = { 0 };
	int orderLikelyhood[27][27][27] = { 0 }; // change name to: sortedLikelyhoodLookup eg output; likelyhood(1,1) = [-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 0 5 19 26]
	double lookupTable[27][27][27] = { 0 }; // change name to: probabilityLookup eg output; Y(1,1) = [0 0 0 0 0 0 0.24 0 0 0 0.16 0 etc]
	double cumulativeLookupTable[27][27][27] = { 0 }; // change name to: cumulativeprobabilityLookup eg output; Y(1,1) = [0 0.25 0.27 0.27 0.27 0.27 0.27 0.27 0.8 1 etc]
	unsigned int seed = 1;
};

