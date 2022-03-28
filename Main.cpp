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
#include <vector>
#include "Utilities\MathUtils.h"
#include "Utilities\Fuzzifier.h"

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

void RunFuzzifier()
{
	// indices and control variables
	int k{ 0 }, NumOfCategories{ 0 };
	uint64_t RandomInt{ 0 };

	// User input variables
	float InputLow{ 0.0f }, InputMid{ 0.0f }, InputHigh{ 0.0f }, InputValue{ 1.0f };
	std::string InputString{ "Null" };

	// System variables
	std::vector<Fuzzifier*> FuzzPtr;
	std::vector<float> RelativeProbability;
	float Total{ 0.0f }, RunTotal{ 0.0f };

	std::cout << "Enter number of categories: ";
	std::cin >> NumOfCategories;
	if (NumOfCategories <= 0)
	{
		exit;
	}
	FuzzPtr.resize(NumOfCategories);
	RelativeProbability.resize(NumOfCategories);

	// Get the category names from the user and the values
	 for (size_t i = 0; i < NumOfCategories; i++)
	 {
		// used for checking when the user is done adding categories
		std::string CheckValue{ "Done" };

		// promot the user to add categories
		std::cout << "\nPlease enter a category: \nWhen you are done, type 'done' : \n\n";
		FuzzPtr.at(i) = new Fuzzifier;
		std::cin >> InputString;

		// break from the loop once 'done' has been inputed by the end user. Check is case INsensitive.
		if (CompareStrings(InputString, CheckValue))
			break;

		// add the name to the particular fuzzifier pointer.
		FuzzPtr[i]->SetName(InputString);

		std::cout << "\nTypoe in the values for the low, miod, and high values for " << FuzzPtr[i]->GetCategoryName() << " Category. \n";
		std::cout << "Seperate the values with spaces (e.g., 1.0 1.5 2.0) \n";
		std::cout << "Low, Mid, High Vlaues: \n\n";

		std::cin >> InputLow >> InputMid >> InputHigh;
		FuzzPtr[i]->SetValues(InputLow, InputMid, InputHigh);
	}

	 std::cout << "\n\n";
	 std::cout << "=================================\n";
	 std::cout << "== Fuzzifier is Ready for Data ==\n";
	 std::cout << "=================================\n";

	 while (true)
	 {
		 std::cout << "\nInput a data value point.";
		 std::cout << "\nType '-99' to terminate.\n";
		 std::cin >> InputValue;

		 if (InputValue == -99)
			 break;

		 // Calculate relative probabilities of inputed values into each category
		 Total = 0.0f; // reset total
		 for (k = 0; k < NumOfCategories; k++)
		 {
			 RelativeProbability[k] = 100 * FuzzPtr[k]->GetShare(InputValue);
			 Total += RelativeProbability[k];
		 }

		 RandomInt = UMath::SRandomVeryFast(0, false, Total);

		 k = 0;
		 RunTotal = RelativeProbability[k];

		 if (Total != 0)
		 {
			 while (RunTotal < RandomInt && k < NumOfCategories)
			 {
				 k++;
				 RunTotal += RelativeProbability[k];
			 }

			 std::cout << "\n\nOutput Fuzzy Category Is: " << FuzzPtr[k]->GetCategoryName();
			 std::cout << "\nCategory\tMembership\n";
			 std::cout << "--------------------------\n";

			 for (k = 0; k < NumOfCategories; k++)
			 {
				 std::cout << FuzzPtr[k]->GetCategoryName() << "\t\t" << (RelativeProbability[k] / Total) << "\n";
			 }
		 }
		 else
		 {
			 std::cout << "Data out of range! \n";
		 }

	 }

}


int main()
{
	//RunRandTest();
	RunFuzzifier();
	

	return 0;
}