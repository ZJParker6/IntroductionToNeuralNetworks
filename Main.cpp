#include <iostream>

#include "Utilities\MathUtils.h"

int main()
{
	double UserValue{ 0.0f };
	std::cout << "Please enter a value: ";
	std::cin >> UserValue;

	std::cout << "\nThe value " << UserValue << " is even: " << UMath::CheckIsEven(UserValue);
	std::cout << "\nAnd this value is positive? " << UMath::ValueSign(UserValue);
	return 0;
}