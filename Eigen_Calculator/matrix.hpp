#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <vector>

using std::vector;

class Matrix
{
	uint8_t rows;
	uint8_t columns;
	double** matrix;

	inline void Set(uint8_t Row, uint8_t Col)
	{
		matrix = new double* [rows];
		for (size_t i = 0; i < rows; i++)
		{
			matrix[i] = new double[columns];
		}
	}

public :

	Matrix(uint8_t Row = 0, uint8_t Col = 0) : rows(Row), columns(Col), matrix(nullptr) 
	{
		if (rows == 0 || columns == 0)
		{
			return;
		}
		Set(rows, columns);
	}
	
	inline uint8_t No_Row() const
	{
		return rows;
	}

	inline uint8_t No_Col() const
	{
		return columns;
	}

	inline void Enter_Data(double** Data = nullptr)
	{
		for (uint8_t Row = 0; Row < rows; ++Row)
		{
			for (uint8_t Col = 0; Col < columns; Col++)
			{
				matrix[Row][Col] = Data[Row][Col];
			}
		}
	}

	inline void Init(uint8_t Row, uint8_t Col)
	{
		if (matrix == nullptr)
		{
			return;
		}

		Set(Row, Col);
	}

	Matrix operator +(const Matrix& Operand);

	Matrix operator -(const Matrix& Operand);

	Matrix Multiply(const Matrix& Operand);

	void Print() const;

	~Matrix()
	{
		for (size_t i = 0; i < rows; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}
};


#endif
