#include "BowlingThrow.h"

#include <ctype.h>
#include "ImpossibleSpareException.h"
#include "InvalidPinsCharException.h"

BowlingThrow::BowlingThrow(char pinsChar, int currentFrame) :
	pinsChar(pinsChar),
	frame(currentFrame)
{
	nextThrow = nullptr;
	previousThrow = nullptr;
}


BowlingThrow::~BowlingThrow()
{
}

void BowlingThrow::setNext(BowlingThrow *next) {

	nextThrow = next;
}

void BowlingThrow::setPrev(BowlingThrow *prev) {

	previousThrow = prev;
}

int BowlingThrow::getNumberOfPins()
{
	if (pinsChar == '-')
		return 0;
	else if (pinsChar == 'X' || pinsChar == 'x')
		return 10;
	else if (pinsChar == '/')
		return 10 - previousThrow->getNumberOfPins();
	else
		return pinsChar - '0';
}

void BowlingThrow::checkIfPinsCharIsValid()
{
	if (pinsChar == '/' && (!previousThrow || (previousThrow && previousThrow->getFrame() != frame)))
		throw ImpossibleSpareException();

	if (!isdigit(pinsChar) && pinsChar != '-' && pinsChar != 'X' && pinsChar != 'x' && pinsChar != '/')
		throw InvalidPinsCharException();
}

int BowlingThrow::getScore()
{
	int score = getNumberOfPins();

	if (nextThrow && frame < 9 && (isSpare() || isStrike())) {

		score += nextThrow->getNumberOfPins();

		if (isStrike() && nextThrow->getNext())
			score += nextThrow->getNext()->getNumberOfPins();
	}

	return score;
}