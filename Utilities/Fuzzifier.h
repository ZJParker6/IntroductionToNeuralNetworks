/******************************************************************************
*  Fuzzifier Function.
*
*  This will fuzzify data and is part of the Introduction to Neural Networks Project
*
*  Code written by Z. J. Parker for udemy Course.
*  This file is part of the Introduction to Neural Networks Project
*  Copyright included in repo.
******************************************************************************/

#pragma once
#include <string>


class Fuzzifier
{
/************************************************
* CONSTRUCTORS AND DESTRUCTORS
************************************************/
public: 
	Fuzzifier();
	~Fuzzifier();

/************************************************
* ATTRIBUTES
************************************************/
private:
	float LowValue{ 0.0f }, MidValue{ 0.5f }, HighValue{ 1.0f };
	std::string CategoryName{ "Default" };

/************************************************
* METHODS
************************************************/
public:
	/************************************************
	* SETTERS
	************************************************/
	/* Used to set the category name */
	void SetName(std::string Input);

	/* Set the values for low, mid, and high */
	void SetValues(float& InputLow, float& InputMid, float& InputHigh);

	/************************************************
	* GETTERS
	************************************************/
	/* Returns the category name */
	std::string GetCategoryName() const { return CategoryName; }

	/* reutns the LOW value */
	float GetLowValue()const { return LowValue; }
	/* reutns the MID value */
	float GetMidValue()const { return MidValue; }
	/* reutns the HIGH value */
	float GetHighValue()const { return HighValue; }

	/* Returns get category membership, ranging between 0 and 1 */
	float GetShare(const float& Input);
};

