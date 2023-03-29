#pragma once
#include <cstdlib>

ref class Randomex
{
private:
	System::Random^ rand01;
public:

	Randomex()
	{
		srand((unsigned int) time(NULL));
		rand01 = gcnew System::Random();
	}

	//Generates random int in [rangeMin, rangeMax]
	static int RandInt(int rangeMin, int rangeMax)
	{
		return (int)((double)rand() / (RAND_MAX + 1) * ((rangeMax + 1) - rangeMin) + rangeMin);
	}

	//Generates random boolean with probability
	bool RandBool(double probability)
	{
		return rand01->NextDouble() < probability;
	}

	//Generates random RGB color
	static System::Drawing::Color RandColor()
	{
		return System::Drawing::Color::FromArgb(RandInt(50, 255), RandInt(50, 255), RandInt(50, 255));
	}
};