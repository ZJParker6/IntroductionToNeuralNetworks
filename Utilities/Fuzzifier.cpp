#include "Fuzzifier.h"

Fuzzifier::Fuzzifier()
{
}

Fuzzifier::~Fuzzifier()
{
}

void Fuzzifier::SetName(std::string Input)
{
	CategoryName = Input;
}

void Fuzzifier::SetValues(float& InputLow, float& InputMid, float& InputHigh)
{
	LowValue = InputLow;
	MidValue = InputMid;
	HighValue = InputHigh;
}

float Fuzzifier::GetShare(const float& Input)
{
	// Set local values
	float MidLowLocal, HighMidLocal;

	MidLowLocal = MidValue - LowValue;
	HighMidLocal = HighValue - MidValue;

	// Check input is valid (if it is within range)
	if (Input <= LowValue || Input >= HighValue)
	{
		return 0.0f;
	}
	else
	{
		if (Input > MidValue)
		{
			return ((HighValue - Input) / HighMidLocal);
		}
		else if (Input == MidValue)
		{
			return 1.0f;
		}
		else
		{
			return ((Input - LowValue) / MidLowLocal);
		}
	}


}
