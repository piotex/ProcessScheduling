#pragma once

#include "Proces.h"

class Processor
{
	public:
		int Index = 0;
		Proces ActualProces;

		Processor();
		Processor(const int& index);
};

