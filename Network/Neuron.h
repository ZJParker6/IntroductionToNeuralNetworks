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

class Neuron
{
public:
/************************************************
* CONSTRUCTORS AND DESTRUCTORS
************************************************/
	Neuron();
	~Neuron();



/************************************************
* METHODS
************************************************/


	/************************************************
	* GETTERS
	************************************************/
public:
	/* Returns the activation output of a neuron */
	double GetNeuronOutput(double InputValue, double* Weight) { return InputValue * *Weight;  }
};

