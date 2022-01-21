#include "Processor.h"

Processor::Processor()
{
}

Processor::Processor(const int& _index, const int& _RemainingTimeToExpropriation)
{
	Index = _index;
	RemainingTimeToExpropriation = _RemainingTimeToExpropriation;
}
