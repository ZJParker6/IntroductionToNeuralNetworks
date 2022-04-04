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
#include <cmath>

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
	std::vector<double> Outputs, HiddenOutputs, UpwardPrediction, UpError, DownwardPrediction, DownError;
	size_t NumOfOutputs{ 0 };
	double Error{ 0.0f }, Loss{ 0.0f };

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

	void ResetAllResults(int OutputLengthIn, int HiddenLengthIn);

	void CalcError(double ExpectedIn, double ObservedIn);
	void CalcLossFunction();

	void CalcUpwardPrediction(std::vector<double>* InputValues, std::vector<std::vector<double>>* WeightsIn, double& StepAmountIn);
	void CalcDownPrediction(std::vector<double>* InputValues, std::vector<std::vector<double>>* WeightsIn, double& StepAmountIn);

	void CaldPredictionErrors(double ExpectedIn, int IndexRef);

	/************************************************
	* GETTERS
	************************************************/
public:
	/* Returns the activation output of a neuron */
	double GetNeuronOutput(double InputValue, double* Weight) { return InputValue * *Weight;  }
	double GetNeuronOutput(int IndexRef) { return Outputs.at(IndexRef); }
	/* Returns all the outputs of a hidden neuron*/
	std::vector<double> GetHiddenOutputs() { return HiddenOutputs;  }

	/* returns the error */
	double GetError() const { return Error; }
	/* Returns the loss value */
	double GetLoss() const { return Loss; }
	/* returns the downward prediction */
	double GetDownprediction(int IndexRef) const { return DownwardPrediction.at(IndexRef); }
	/* returns the upward prediction */
	double GetUpprediction(int IndexRef) const { return UpwardPrediction.at(IndexRef); }
	/* Reutn the upward loss */
	double GetUpError(int IndexRef) const { return UpError.at(IndexRef); }
	/* Reutn the downward loss */
	double GetDownError(int IndexRef) const { return DownError.at(IndexRef); }
};

