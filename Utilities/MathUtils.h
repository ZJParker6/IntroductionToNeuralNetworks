/******************************************************************************
*  Math Utility Functions.
*
*  A collection of math helper functions and strucutres
*
*  Code written by Z. J. Parker for udemy Course. 
*  This file is part of the Introduction to Neural Networks Project
*  Copyright included in repo.
******************************************************************************/

#pragma once
#include <cmath>

namespace UMath
{
/******************************************************************************
* FUNCTION LIBRARY: COMMON MATH FUNCTIONS
* These functions are intended general use across all classes
* There is no specific use case for these functions.
******************************************************************************/

	/* Returns a ratio of a value between 0.0 and 1.0f */
	inline float GetRatio(float ValueIn, float Minimum, float Maximum)
	{
		if (ValueIn >= Maximum)
		{
			// raw value is equal to or greater than max, so ratio is at max
			return 1.0f;
		}
		else if (ValueIn > Minimum)
		{
			// standard ratio calculation
			return (ValueIn - Minimum) / (Maximum - Minimum);
		}
		else
		{
			// a catch-all
			return 0.0f;
		}
	}

	/* Returns a +1 or -1 based on the relation of T to 0; 0 is returned as +1 */
	template<class T>
	inline static T ValueSign(const T x)
	{
		return (x >= (T)0) ? (T)+1 : (T)-1;
	}

	/* return a true for even and false for odd */
	template<class T>
	inline bool CheckIsEven(T x)
	{
		if (std::fmod(x, 2) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}