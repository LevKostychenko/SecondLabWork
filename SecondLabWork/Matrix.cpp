#include "pch.h"
#include "Matrix.h"
#include "MatrixExtencion.h"

Matrix::Matrix(const Matrix &matrix)
{
	this->_size = matrix._size;
	this->_data = MatrixExtencion::MatrixInitialize(matrix._size, matrix._data);
}

Matrix::Matrix(int matrixSize)
{
	this->_size = matrixSize;
}

Matrix::Matrix(int matrixSize, float **matrixData)
{
	this->_size = matrixSize;
	this->_data = MatrixExtencion::MatrixInitialize(matrixSize, matrixData);
}

void Matrix::MatrixSummary(Matrix& A, Matrix& B)
{
	this->_data = MatrixExtencion::MatrixInitialize(this->_size);

	for (int i = 0; i < A._size; i++)
	{
		this->_data[i] = new float[A._size];
		for (int j = 0; j < A._size; j++)
		{
			this->_data[i][j] = A._data[i][j] + B._data[i][j];
		}
	}
}

void Matrix::MatrixMultiplication(Matrix& A, Matrix& B)
{
	this->_data = MatrixExtencion::MatrixInitialize(this->_size);

	for (int i = 0; i < A._size; i++)
	{
		for (int j = 0; j < B._size; j++)
		{
			for (int k = 0; k < A._size; k++)
				this->_data[i][j] += A._data[i][k] * B._data[k][j];
		}
	}
}

void Matrix::GetMatrix()
{
	this->_data = MatrixExtencion::MatrixInitialize(this->_size);

	for (int rowsCounter = 0; rowsCounter < this->_size; rowsCounter++)
	{
		for (int columnsCount = 0; columnsCount < this->_size; columnsCount++)
		{
			this->_data[rowsCounter][columnsCount] = rand() % 40;
			std::cout << this->_data[rowsCounter][columnsCount] << " ";
		}

		std::cout << "\n";
	}
}

void Matrix::MatrixDisplay()
{
	for (int i = 0; i < this->_size; i++)
	{
		for (int j = 0; j < this->_size; j++)
		{
			std::cout << this->_data[i][j] << "\t";
		}
		std::cout << "\n";
	}

	std::cout << "\n";
}

Matrix operator * (Matrix A, Matrix B)
{	
	float** matrixData = new float*[A._size];

	for (int i = 0; i < A._size; i++)
	{
		matrixData[i] = new float[B._size];
		for (int j = 0; j < B._size; j++)
		{
			matrixData[i][j] = 0;
			for (int k = 0; k < A._size; k++)
				matrixData[i][j] += A._data[i][k] * B._data[k][j];
		}
	}
	
	return Matrix(A._size, matrixData);
}

Matrix& Matrix::operator= (Matrix B)
{
	this->_data = MatrixExtencion::MatrixInitialize(B._size, B._data);
	this->_size = B._size;
	return *this;
}

Matrix operator + (Matrix A, Matrix B)
{
	float** matrixData = new float*[A._size];

	for (int i = 0; i < A._size; i++)
	{
		matrixData[i] = new float[A._size];
		for (int j = 0; j < A._size; j++)
		{
			matrixData[i][j] = A._data[i][j] + B._data[i][j];
		}
	}

	return Matrix(A._size, matrixData);
}