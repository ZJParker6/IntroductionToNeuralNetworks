#include "Neuron.h"

Neuron::Neuron()
{
}

Neuron::~Neuron()
{
}

void Neuron::SetVectorLength(int LengthIn)
{
	Outputs.resize(LengthIn);

	NumOfOutputs = LengthIn;
}

void Neuron::CalcResult(double* InputValue, std::vector<double>* WeightIn)
{
	for (size_t i = 0; i < NumOfOutputs; i++)
	{
		Outputs.at(i) = *InputValue * WeightIn->at(i);
	}
}
