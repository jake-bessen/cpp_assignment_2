#ifndef GUESSINGGAME_H
#define GUESSINGGAME_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class guessingGame
{
public:
	guessingGame() {}
	void guessingGameMenu(string, string);
	string retrieveGuess(string, string, int);
};

#endif

