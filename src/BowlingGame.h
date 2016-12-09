#pragma once

#include <string>

#include "BowlingThrow.h"

using namespace std;

class BowlingGame
{
public:
	BowlingGame();
	~BowlingGame();

	void setSequence(const string sequence);
	int getScore();

private:
	BowlingThrow **bowlingThrows;
	int numberOfThrows;
	int numberOfFrames;
};

