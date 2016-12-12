#pragma once

#include <stdexcept>

using namespace std;

class ImpossibleSpareException : public runtime_error {

public:

	ImpossibleSpareException() :
		runtime_error("There is an impossible spare in your scorecard")
	{
	}

	virtual ~ImpossibleSpareException() throw() {}
};