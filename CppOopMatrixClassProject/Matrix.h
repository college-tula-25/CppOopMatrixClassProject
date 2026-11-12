#pragma once

template <typename T>
class MatrixHIterator;

template <typename T>
class MatrixVIterator;

template <typename T>
class Matrix
{
	T** matrix;
	size_t rows;
	size_t columns;
public:
	Matrix(size_t rows, size_t columns);

	size_t Rows() const;
	size_t Columns() const;

	void SetItem(size_t row, size_t column, T value);
	T GetItem(size_t row, size_t column) const;

	MatrixHIterator<T> HBegin();
	MatrixVIterator<T> VBegin();

	~Matrix();
};

template<typename T>
class MatrixHIterator
{
	Matrix<T> matrix;
	int row, column;
public:
	MatrixHIterator(Matrix<T> matrix);

	void Set();
	void Next();
	bool IsEnd();
	T Current();
};


template<typename T>
class MatrixVIterator
{
	Matrix<T> matrix;
	int row, column;
public:
	MatrixVIterator(Matrix<T> matrix);

	void Set();
	void Next();
	bool IsEnd();
	T Current();
};


template<typename T>
inline Matrix<T>::Matrix(size_t rows, size_t columns)
	: rows{ rows }, columns{ columns }
{
	matrix = new T*[rows];
	for (int i{}; i < rows; i++)
		matrix[i] = new T[columns];
}

template<typename T>
inline size_t Matrix<T>::Rows() const
{
	return rows;
}

template<typename T>
inline size_t Matrix<T>::Columns() const
{
	return columns;
}

template<typename T>
inline void Matrix<T>::SetItem(size_t row, size_t column, T value)
{
	matrix[row][column] = value;
}

template<typename T>
inline T Matrix<T>::GetItem(size_t row, size_t column) const
{
	return matrix[row][column];
}

template<typename T>
inline Matrix<T>::~Matrix()
{
	for (int i{}; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
}
