#pragma once
class Proces
{
	public: 
		Proces();
		Proces(int index, int priority, int remainingTimeToEndOfProces, const int& _RemainingTimeToExpropriation);
		int Index = -1;
		int Priority = 0;
		int RemainingTimeToEndOfProces = 0;

		int RemainingTimeToExpropriation = 0;

		//int czyAktualnieRobiony = 0;
		//int numerProckaNaKrorymJestRobiony = -1;
};

