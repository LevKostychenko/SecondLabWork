// SecondLabWork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Matrix.h"

int main()
{
	bool isProccessStopped = false;
	while (!isProccessStopped)
	{
		int matrixSize = 0;
		char _continue = 'n';

		std::cout << "\nEnter matrix size: ";
		std::cin >> matrixSize;
		Matrix AMatrix(matrixSize);
		Matrix BMatrix(matrixSize);

		AMatrix.GetMatrix();
		std::cout << "\n\n";
		BMatrix.GetMatrix();
		std::cout << "\n\n";

		std::cout << "Matrix multiplication: \n";
		Matrix multiplicatedMatrix(matrixSize);
		multiplicatedMatrix = AMatrix * BMatrix;
		multiplicatedMatrix.MatrixDisplay();

		std::cout << "Matrix sum: \n";
		Matrix summaredMatrix(matrixSize);
		summaredMatrix = AMatrix + BMatrix;
		summaredMatrix.MatrixDisplay();

		std::cout << "Do you want to continue? (y/n): ";
		std::cin >> _continue;

		isProccessStopped = _continue == 'n';	
	}

	system("pause");
}