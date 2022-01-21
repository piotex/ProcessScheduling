#pragma once

#include "Proces.h"

class Processor
{
	public:
		int RemainingTimeToExpropriation = 0;
		int Index = 0;
		Proces ActualProces;

		Processor();
		Processor(const int& index, const int& _RemainingTimeToExpropriation);
};

