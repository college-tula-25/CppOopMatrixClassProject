#include <iostream>

int main()
{
    //const int rows{ 5 };
    //const int columns{ 7 };
    //int matrix[rows][columns];

    //int n{ 123 };
    //int* iptr{ &n };
    //int** iptrptr{ &iptr };
    srand(time(nullptr));

    int rows{ 5 };
    int columns{ 7 };

    // alloc
    int** matrix = new int*[rows];
    for (int i{}; i < rows; i++)
        matrix[i] = new int[columns];


    for (int i{}; i < rows; i++)
        for (int j{}; j < columns; j++)
            matrix[i][j] = rand() % 100;

    for (int i{}; i < rows; i++)
    {
        for (int j{}; j < columns; j++)
            std::cout << matrix[i][j] << "\t";
        std::cout << "\n";
    }
    std::cout << "\n";

    // free
    for (int i{}; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;

}
