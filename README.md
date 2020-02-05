# Vector-Magnitude-and-Normalizer
Small C++ program that takes in any 1xn vector, calculates it's magnitude, and normalizes it.

# Quick Code Preview

```
//Code Showing vector magnitude calculation function

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

```
