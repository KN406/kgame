#include "BowlingGame.h"

BowlingGame::BowlingGame() :
	numberOfThrows(0),
	numberOfFrames(0)
{
	bowlingThrows = nullptr;
}


BowlingGame::~BowlingGame()
{
	delete bowlingThrows;
}

void BowlingGame::setSequence(const string sequence) {

	numberOfThrows = sequence.length();
	bowlingThrows = new BowlingThrow*[numberOfThrows];
	bool frameEnd = false;

	for (int i = 0; i < numberOfThrows; i++) {

		bowlingThrows[i] = new BowlingThrow(sequence[i], numberOfFrames);

		if (i > 0) {
			bowlingThrows[i - 1]->setNext(bowlingThrows[i]);
			bowlingThrows[i]->setPrev(bowlingThrows[i - 1]);
		}

		bowlingThrows[i]->alterPinsCharIfNotValid();

		if (bowlingThrows[i]->isStrike()) 
			frameEnd = true;

		if (frameEnd) 
			numberOfFrames++;

		frameEnd = !frameEnd;
	}
}

int BowlingGame::getScore()
{
	int score = 0;

	for (int i = 0; i < numberOfThrows; i++)
		score += bowlingThrows[i]->getScore();

	return score;
}
