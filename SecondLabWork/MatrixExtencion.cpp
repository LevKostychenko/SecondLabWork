#include "pch.h"
#include "MatrixExtencion.h"

float** MatrixExtencion::MatrixInitialize(int size, float** data)
{
	float **matrix = new float*[size];

	for (size_t i = 0; i < size; i++)
	{
		matrix[i] = new float[size];
		for (size_t j = 0; j < size; j++)
		{
			matrix[i][j] = data[i][j];
		}
	}

	return matrix;
}

float** MatrixExtencion::MatrixInitialize(int size)
{
	float **matrix = new float*[size];

	for (int i = 0; i < size; i++)
	{
		matrix[i] = new float[size];
		for (int j = 0; j < size; j++)
		{
			matrix[i][j] = 0;
		}
	}

	return matrix;
}