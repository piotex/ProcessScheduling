#include "Proces.h"

Proces::Proces() {
	Index = -1;
	Priority = 0;
	RemainingTimeToEndOfProces = 0;
	RemainingTimeToExpropriation = 0;

}
Proces::Proces(int index, int priority, int remainingTimeToEndOfProces, const int& remainingTimeToExpropriation) {
	Index = index;
	Priority = priority;
	RemainingTimeToEndOfProces = remainingTimeToEndOfProces;
	RemainingTimeToExpropriation = remainingTimeToExpropriation;
}