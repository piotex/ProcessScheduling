#include "Proces.h"

Proces::Proces() {

}
Proces::Proces(int index, int priority, int remainingTimeToEndOfProces) {
	Index = index;
	Priority = priority;
	RemainingTimeToEndOfProces = remainingTimeToEndOfProces;
}