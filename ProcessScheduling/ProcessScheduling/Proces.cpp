#include "Proces.h"

Proces::Proces() {

}
Proces::Proces(int index, int priority, int remainingTimeToEndOfProces, const int& remainingTimeToExpropriation) {
	Index = index;
	Priority = priority;
	RemainingTimeToEndOfProces = remainingTimeToEndOfProces;
	RemainingTimeToExpropriation = remainingTimeToExpropriation;
}