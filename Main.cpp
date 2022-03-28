/******************************************************************************
*  Main.
*
*  The main function for the Introduction to Neural Networks Project
*
*  Code written by Z. J. Parker for udemy Course.
*  This file is part of the Introduction to Neural Networks Project
*  Copyright included in repo.
******************************************************************************/

#include <iostream>
#include <string>

#include "Utilities\MathUtils.h"

bool CompareStrings(std::string& Str1, std::string& Str2)
{
	return ((Str1.size() == Str2.size()) && std::equal(Str1.begin(), Str1.end(), Str2.begin(), [](char& C1, char& C2)
		{return (C1 == C2 || std::toupper(C1) == std::toupper(C2)); }));
}

void RunRandTest()
{
	std::cout << "SUPER FAST UINT64: \n";
	uint64_t FirstTest = UMath::SRandomVeryFast();
	std::cout << "Default: " << FirstTest << std::endl;

	uint64_t SecondTest = UMath::SRandomVeryFast(0, true);
	std::cout << "Seed 0: " << SecondTest << std::endl;

	uint64_t ThirdTest = UMath::SRandomVeryFast(324, true);
	std::cout << "Seed 324: " << ThirdTest << std::endl;

	std::cout << "SUPER FAST LOOP DOUBLE: \n";
	for (size_t i = 0; i < 5; i++)
	{
		double LoopTest = UMath::SRandomVeryFast();
		std::cout << "Default Loop [" << i << "] : " << LoopTest << std::endl;
	}

	std::cout << "\n\n\n\n\nFAST UINT64:";
	FirstTest = UMath::SRandomFast();
	std::cout << "Default: " << FirstTest << std::endl;
	SecondTest = UMath::SRandomFast(0, true);
	std::cout << "Default: " << SecondTest << std::endl;
	ThirdTest = UMath::SRandomFast(324, true);
	std::cout << "Default: " << ThirdTest << std::endl;

	std::cout << "FAST LOOP DOUBLE: \n";
	for (size_t i = 0; i < 5; i++)
	{
		double LoopTest = UMath::SRandomFast();
		std::cout << "Default Loop [" << i << "] : " << LoopTest << std::endl;
	}
}

int main()
{
	std::string Test{ "null" };
	std::string CheckValue{ "DonE" };
	//RunRandTest();
	std::cout << "Enter 'done' : ";
	std::cin >> Test;

	if (CompareStrings(Test, CheckValue))
	{
		std::cout << "\n\nThis worked!";
	}
	else
	{
		std::cout << "\n\nThis did not work!";
	}



	return 0;
}