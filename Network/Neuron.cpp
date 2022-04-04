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

void Neuron::SetHiddenVectorLength(int LengthIn)
{
	HiddenOutputs.resize(LengthIn);
}

void Neuron::CalcResult(double* InputValue, std::vector<double>* WeightIn)
{
	for (size_t i = 0; i < NumOfOutputs; i++)
	{
		Outputs.at(i) = *InputValue * WeightIn->at(i);
	}
}

double Neuron::CalcResult(std::vector<double>* InputValues, std::vector<double>* WeightsIn)
{
	double OutputLocal{ 0.0f };

	for (size_t i = 0; i < NumOfOutputs; i++)
	{
		OutputLocal += InputValues->at(i) * WeightsIn->at(i);
	}
	return OutputLocal;
}

double Neuron::MultipleInSingleOut(std::vector<double>* InputValues, std::vector<double>* WeightsIn, int VectorLengthIn)
{
	Outputs.resize(1);
	NumOfOutputs = VectorLengthIn;
	Outputs.at(0) = CalcResult(InputValues, WeightsIn);
	return Outputs.at(0);
}

void Neuron::MultipleInMultipleOut(std::vector<double>* InputValues, std::vector<std::vector<double>>* WeightsIn)
{
	for (size_t k = 0; k < WeightsIn->size(); k++)
	{
		for (size_t i = 0; i < WeightsIn->at(k).size(); i++)
		{
			Outputs.at(k) += InputValues->at(i) * WeightsIn->at(i).at(k);
		}
	}
}

void Neuron::MultipleHidden(std::vector<double>* InputValues, std::vector<std::vector<double>>* WeightsIn)
{
	for (size_t k = 0; k < WeightsIn->size(); k++)
	{
		for (size_t i = 0; i < WeightsIn->at(k).size(); i++)
		{
			HiddenOutputs.at(k) += InputValues->at(i) * WeightsIn->at(i).at(k);
		}
	}
}
