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
#include <random>
#include <set>
#include <stdexcept>

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

/******************************************************************************
* RANDOM GENERATORS (PRNGs)
* These structs/functions are designed to generator PRNs
* There are different approaches that can be used for different use cases
******************************************************************************/

	/* Gets random seed for PRNG */
	inline uint64_t SeedGenerator(uint32_t Seed = 0, bool bUseOverride = false)
	{
		if (!bUseOverride)
		{
			// Get a distrubtion of random numbers
			std::random_device RDLocal;
			std::mt19937 generator(RDLocal());
			std::uniform_int_distribution<uint32_t> PossibleSeedsLocal(0, 10000);

			// set Seed value
			return PossibleSeedsLocal(generator);
		}
		else
		{
			// return a seed provided by the user
			return Seed;
		}
	}

	/* XOR shift random number generator */
	struct SRandomVeryFast
	{
	private: 
		uint64_t T{ 0 };
		uint64_t ShuffleTable[4]{ 0 };
		uint64_t Result{ 0 };
		uint64_t XorShuffle(uint64_t Seed);
		uint32_t Seed{ 0 };
		bool bUserOverride{ false };

		int64_t MAX_RANDOM = 0x7fff; // 32767

	public:
		SRandomVeryFast(uint32_t SeedIn = 0, bool bUserOverrideIn = false, int64_t MaxIn = 0x7fff)
		{
			Seed = SeedIn;
			bUserOverride = bUserOverrideIn;
			MAX_RANDOM = MaxIn;
		}

		// conversion to float, returns a random float between 0 and 1 (1 exlusive)
		operator double()
		{
			return double(XorShuffle(SeedGenerator(Seed, bUserOverride)) * (1.0f / 31415926538979.0f));
		}

		// conversion to uint64, returns random int64 between 0 and MAX_RANDOM (MAX_RANDOM inclusive)
		operator uint64_t()
		{
			return XorShuffle(SeedGenerator(Seed, bUserOverride)) & MAX_RANDOM;
		}
	};

	inline uint64_t SRandomVeryFast::XorShuffle(uint64_t Seed)
	{
		// This is the next() function from Marsaglia's xorshfit generator

		ShuffleTable[0] = Seed;
		ShuffleTable[1] = 362436069;
		ShuffleTable[2] = 521288629;

		ShuffleTable[0] ^= ShuffleTable[0] << 16;
		ShuffleTable[0] ^= ShuffleTable[0] >> 5;
		ShuffleTable[0] ^= ShuffleTable[0] << 1;

		T = ShuffleTable[0];
		ShuffleTable[0] = ShuffleTable[1];
		ShuffleTable[1] = ShuffleTable[2];
		ShuffleTable[2] = T ^ ShuffleTable[0] ^ ShuffleTable[1];

		Result = ShuffleTable[2];

		return Result;
	}

	/* Fast random number generator strucutre using the linear congruential generator (LCG) */
	struct SRandomFast
	{
	private:
		uint32_t Seed{ 0 };
		bool bUserOverride{ false };
		uint64_t GetFastRandom(uint64_t Seed);

		int64_t MAX_RANDOM = 0x7fff; // 32767


	public:

		SRandomFast(uint32_t SeedIn = 0, bool bUserOverrideIn = false, int64_t MaxIn = 0x7fff)
		{
			Seed = SeedIn;
			bUserOverride = bUserOverrideIn;
			MAX_RANDOM = MaxIn;
		}

		// conversion to float, returns a random float between 0 and 1 (1 exlusive)
		operator double()
		{
			return double(GetFastRandom(SeedGenerator(Seed, bUserOverride)) * (1.0f / 31415926538979.0f));
		}

		// conversion to uint64, returns random int64 between 0 and MAX_RANDOM (MAX_RANDOM inclusive)
		operator uint64_t()
		{
			return GetFastRandom(SeedGenerator(Seed, bUserOverride)) & MAX_RANDOM;
		}
	};

	inline uint64_t SRandomFast::GetFastRandom(uint64_t Seed)
	{
		// Multiplier * X + Increment.
		Seed = 1664525L * Seed + 1013904223L; // values lifted from the LCG algorithm

		uint64_t IntLocal = 0x3f800000 | (0x007fffff & Seed);

		return (*&IntLocal) - 1.0f;
	}

	/* Returns a random double (0 to 1; 1 exclusive) meant for minor application in other math utilities*/
	inline double RandomDouble(bool bUseVerFast = true)
	{
		// return 0-999, devides this by 1000 to create a range of 0 to 1
		if (bUseVerFast == true)
		{
			return double(SRandomVeryFast() % 1000) / 1000; 
		}
		else
		{
			return double(rand() % 1000) / 1000;
		}
	}

	/* returns amount number(s) from 0 to UpperLimit*/
	inline std::set<int> GetRandomDistinctNumber(int UpperLimit, int Amount)
	{
		// Declare a set
		std::set<int> GeneratedNumbers;

		//Iterate through set
		while (GeneratedNumbers.size() < Amount)
		{
			// add a random number to set
			GeneratedNumbers.insert(SRandomVeryFast() % UpperLimit);
		}
		return GeneratedNumbers;
	}

/************************************************
* Random Bools
************************************************/
	/* Get a random bool (t/f) with 50% of true */
	inline bool GetRandBool()
	{
		// Get random number
		double RNum = RandomDouble();
		if (RNum < .5)
		{
			// if RNum is less than 50% return true
			return true;
		}
		return false;
	}

	/* Get a random bool (t/f) with user inputed chance */
	inline bool GetRandBool(double Probability)
	{
		/* Example use:
		*  bool b = GetRandbool(.7)
		* Check if .7 is in range (it is), gets a random double (in 0 to .9999 range). 
		* Check if double is under probability, if it is = true
		* 
		* Probability = probability of success 	*/

		if (Probability < 0 || Probability > 1)
		{
			// thus the probability out of range of 0 to 100%
			throw std::runtime_error("Entered Probability is Not Valid. Probability should be between 0 to 1");
		}

		// Get random number
		double RNum = RandomDouble();
		if (RNum <= Probability)
		{
			// if RNum is less than 50% return true
			return true;
		}
		return false;
	}

	/* Get a random bool (t/f) with user inputed ratio. Get ratio prevents value from being greater than 1 */
	inline bool GetRandBool(float ValueIn, float Minimum, float Maximum)
	{
		double Probability = GetRatio(ValueIn, Minimum, Maximum);

		// Get random number
		double RNum = RandomDouble();
		if (RNum <= Probability)
		{
			// if RNum is less than 50% return true
			return true;
		}
		return false;
	}
}