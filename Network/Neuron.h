/******************************************************************************
*  Neuron.
*
*  The neuron code for the Introduction to Neural Networks Project
*
*  Code written by Z. J. Parker for udemy Course.
*  This file is part of the Introduction to Neural Networks Project
*  Copyright included in repo.
******************************************************************************/

#pragma once
#include <vector>

class Neuron
{
public:
/************************************************
* CONSTRUCTORS AND DESTRUCTORS
************************************************/
	Neuron();
	~Neuron();

/************************************************
* ATTRIBUTES
************************************************/
private:
	std::vector<double> Outputs, HiddenOutputs;
	size_t NumOfOutputs{ 0 };

/************************************************
* METHODS
************************************************/
	/************************************************
	* SETTERS
	************************************************/
public:
	/* Sets the vector lengths by resizing them */
	void SetVectorLength(int LengthIn);
	void SetHiddenVectorLength(int LengthIn);

	/* Calculates the output */
	void CalcResult(double* InputValue, std::vector<double>* WeightIn);
	double CalcResult(std::vector<double>* InputValues, std::vector<double>* WeightsIn);
	double MultipleInSingleOut(std::vector<double>* InputValues, std::vector<double>* WeightsIn, int VectorLengthIn);
	void MultipleInMultipleOut(std::vector<double>* InputValues, std::vector<std::vector<double>>* WeightsIn);
	void MultipleHidden(std::vector<double>* InputValues, std::vector<std::vector<double>>* WeightsIn);
	/************************************************
	* GETTERS
	************************************************/
public:
	/* Returns the activation output of a neuron */
	double GetNeuronOutput(double InputValue, double* Weight) { return InputValue * *Weight;  }
	double GetNeuronOutput(int IndexRef) { return Outputs.at(IndexRef); }
	/* Returns all the outputs of a hidden neuron*/
	std::vector<double> GetHiddenOutputs() { return HiddenOutputs;  }
};

