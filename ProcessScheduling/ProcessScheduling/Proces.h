#pragma once
class Proces
{
	public: 
		Proces();
		Proces(int number, int priority, int remainingTime);
		int Index = -1;
		int Priority = 0;
		int RemainingTimeToEndOfProces = 0;

		//int czyAktualnieRobiony = 0;
		//int numerProckaNaKrorymJestRobiony = -1;
};

