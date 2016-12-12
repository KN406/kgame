#pragma once

using namespace std;

class BowlingThrow
{
public:
	BowlingThrow(char pinsChar, int currentFrame);
	~BowlingThrow();

	int getScore();

	BowlingThrow* getNext() { return nextThrow; }
	int getFrame() { return frame; }
	void setNext(BowlingThrow *next);
	void setPrev(BowlingThrow *prev);

	void checkIfPinsCharIsValid();

	bool isStrike() { return (pinsChar == 'x' || pinsChar == 'X'); }
	bool isSpare() { return pinsChar == '/'; }

private:
	int getNumberOfPins();
	
	BowlingThrow* nextThrow;
	BowlingThrow* previousThrow;

	char pinsChar;
	int frame;
};

