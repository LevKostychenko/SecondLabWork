#pragma once
#include "pch.h"
#include <iostream>
#include <algorithm> 

class Matrix
{
private:
	float** _data;
	int _size;

public:
	Matrix(int matrixSize);

	Matrix(int matrixSize, float **matrixData);

	Matrix(const Matrix &matrix);

	int GetSize()
	{
		return this->_size;
	}

	float** Data()
	{
		return this->_data;
	}

	friend Matrix operator * (Matrix A, Matrix B);

	friend Matrix operator + (Matrix A, Matrix B);

	void GetMatrix();

	void MatrixSummary(Matrix& A, Matrix& B);

	void MatrixMultiplication(Matrix& A, Matrix& B);

	void MatrixDisplay();

	Matrix& operator = (Matrix B);

	~Matrix()
	{
		for (size_t i = 0; i < this->_size; i++)
		{
			delete[] this->_data[i];
		}
		delete[] this->_data;
	}
};
