#pragma once

#include <stdexcept>
#include <string>

using namespace std;

class InvalidPinsCharException : public runtime_error {

public:

	InvalidPinsCharException() :
		runtime_error("There is an invalid character in your scorecard")
	{
	}

	virtual ~InvalidPinsCharException() throw() {}
};