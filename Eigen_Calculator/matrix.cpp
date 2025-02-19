#include <iostream>
#include "matrix.hpp"

Matrix Matrix::operator +(const Matrix& Operand)
{
	if (Operand.rows != this->rows || Operand.columns != this->columns)
	{
		return Matrix();
	}

	Matrix Return(Operand.rows, Operand.columns);

	for (uint8_t Rows = 0; Rows < rows; ++Rows)
	{
		for (uint8_t Col = 0; Col < columns; Col++)
		{
			Return.matrix[Rows][Col] = this->matrix[Rows][Col] + Operand.matrix[Rows][Col];
		}
	}

	return Return;
}


Matrix Matrix::operator -(const Matrix& Operand)
{
	if (Operand.rows != this->rows || Operand.columns != this->columns)
	{
		return Matrix();
	}

	Matrix Return(Operand.rows, Operand.columns);

	for (uint8_t Rows = 0; Rows < rows; ++Rows)
	{
		for (uint8_t Col = 0; Col < columns; Col++)
		{
			Return.matrix[Rows][Col] = this->matrix[Rows][Col] - Operand.matrix[Rows][Col];
		}
	}

	return Return;
}

Matrix Matrix::Multiply(const Matrix& Operand)
{
	const uint8_t Middle = this->columns;

	if (this->columns != Operand.rows)
	{
		return Matrix();
	}

	Matrix Return(this->rows, Operand.columns);

	for (uint8_t Row_Iter = 0; Row_Iter < Return.rows; ++Row_Iter)
	{
		for (uint8_t Col_Iter = 0; Col_Iter < Return.columns; Col_Iter++)
		{
			Return.matrix[Row_Iter][columns] = 0;
			for (uint8_t Mid_Iter = 0; Mid_Iter < Middle; ++Mid_Iter)
			{
				//Return.matrix[Rows][Col] = this->matrix[Rows][Col] + Operand.matrix[Rows][Col];
				Return.matrix[Row_Iter][Col_Iter] += this->matrix[Row_Iter][Mid_Iter] * Operand.matrix[Mid_Iter][Col_Iter];
			}
		}
	}

	return Return;
}

void Matrix::Print() const
{
	for (uint8_t Row = 0; Row < rows; ++Row)
	{
		for (uint8_t Column = 0; Column < columns; ++Column)
		{
			std::cout << matrix[Row][Column] << " ";
		}
		std::cout << std::endl;
	}
}
