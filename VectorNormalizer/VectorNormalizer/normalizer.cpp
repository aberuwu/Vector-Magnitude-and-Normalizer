/*
Programmed by: Cesar I. Mendoza (aberuwu)
Course: MATH 30700 - Applied Linear Algebra
Insitution: Lewis University
Term: Spring 2020
Purpose: This small program take in any 1xn vector
		 and calculates the magnitude and normalizes
		 the vector.
*/

#include <iostream>
#include <cmath>

double magnitude(double* arr[], int columns);
void normalize(double* arr[], int columns);

int const ROWS = 1;

int main()
{
	int columns{};
	double element;

	std::cout << "--------------------------------- Vector Normalizer ---------------------------------" << std::endl;
	std::cout << " Programmed by: Cesar I. Mendoza (aberuwu) " << std::endl;
	std::cout << " Course: MATH 30700 - Applied Linear Algebra - Lewis University" << std::endl;
	std::cout << " Usage: This program takes in any 1xn vector" << std::endl;
	std::cout << " calculates it's magnitude and normalizes the vector." << std::endl;
	std::cout << std::endl;
	std::cout << " Magnitude Formula: Let A be a 1xn vector -> ||A|| = sqrt(ax^2 + ay^2 + ... an^2)" << std::endl;
	std::cout << std::endl;
	std::cout << " Normalization Formula: ||A||n = sqrt((ax^2/||A||) + (ay^2/||A||) + ... (an^2/||A||))" << std::endl;
	std::cout << "-------------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;

	bool status = true;

	while (status == true)
	{
		std::cout << "Enter number of columns in vector: ";
		std::cin >> columns;

		double** vector = new double* [ROWS];
		vector[ROWS] = new double[columns];

		for (int i = 0; i < columns; ++i)
		{
			std::cout << "Enter value at a" << ROWS << i + 1 << ": ";
			std::cin >> element;
			vector[ROWS][i] = element;
		}

		std::cout << std::endl;
		std::cout << "A = " << "[";
		std::cout << " ";
		for (int i = 0; i < columns; ++i)
		{
			std::cout << vector[ROWS][i];
			if (i < columns)
			{
				std::cout << " ";
			}
		}
		std::cout << "]";
		std::cout << std::endl;

		double value = 0;

		std::cout << std::endl;
		std::cout << "Calculating vector magnitude..." << std::endl;
		value = magnitude(vector, columns);

		std::cout << "||A|| = " << value << std::endl;

		std::cout << std::endl;
		std::cout << "Normalizing vector..." << std::endl;
		normalize(vector, columns);

		char yn = 'y';

		std::cout << std::endl;
		std::cout << "Would you like to normalize another vector? (y/n): ";
		std::cin >> yn;

		if (yn == 'y')
		{
			status = true;

		}
		else
			status = false;

		std::cout << std::endl;
	}

	return 0;
}


double magnitude(double *arr[], int columns)
{
	double value = 0;
	double magnitude = 0;

	std::cout << std::endl;

	for (int i = 0; i < columns; ++i)
	{
		value = arr[ROWS][i];
		value *= value;
		magnitude += value;
	}
	
	magnitude = sqrt(magnitude);
	return magnitude;
}

void normalize(double *arr[], int columns)
{
	double value = 0;
	double magn = magnitude(arr, columns);

	std::cout << "Normalized - A = " << "[";
	std::cout << " ";
	for (int i = 0; i < columns; ++i)
	{
		value = arr[ROWS][i];
		value = value / magn;
		arr[ROWS][i] = value;

		std::cout << arr[1][i];
		if (i < columns)
		{
			std::cout << " ";
		}
	}
	std::cout << "]" << std::endl;

	std::cout << std::endl;
	std::cout << "Calculating magnitude for normalized vector..." << std::endl;

	double magnor = magnitude(arr, columns);

	std::cout << "||A|| = " << magnor << " <-- The magnitude of any normalized vector is a Unit Vector!"<<std::endl;
		
	std::cout << std::endl;
}