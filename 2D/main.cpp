#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n-------------------------------\n"
//#define BASICS
//#define MATRIX_ADDITION

void main()
{
	setlocale(LC_ALL, "");

#ifdef BASICS

	const int ROWS = 8;//количество строк
	const int COLS = 5;//количество элементов строки (столбцов)
	int arr[ROWS][COLS] =
	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
#endif

	//The matrix
	const int ROWS = 3;
	const int COLS = 3;
	int A[ROWS][COLS];
	int B[ROWS][COLS];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			A[i][j] = rand() % 10;
			B[i][j] = rand() % 10;
		}
	}
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << A[i][j] << tab;
		}
		cout << endl;
	}
	cout << delimiter;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << B[i][j] << tab;
		}
		cout << endl;
	}
	cout << delimiter << endl;
	int C[ROWS][COLS] = {};//Мартица результат

#ifdef MATRIX_ADDITION
	//Matrix addition
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}
#endif // MATRIX_ADDITION

	//Matrix multiplication
	//При умножении матрицы А на матрицу Б получаем результирующую 
	//матрицу С. ЧТобы получить один элемент матрицы С, необходимо
	//все элементы строки матрицы А умножить на соответствующие элементы 
	//столбца матрицы Б и полученные произведения сложить
	int rez = 0;
	for (int i = 0; i < ROWS; i++)
	{
			for (int j = 0; j < COLS; j++)
			{
				for (int k = 0; k < ROWS; k++)
				{
					rez += A[i][k] * B[k][j];
				}
				C[i][j] = rez;
			}
	}
	
	//вывод
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << C[i][j] << tab;
		}
		cout << endl;
	}
	//Sarrus
	int sum1 = 0, multiply = 1, sum2 = 0, box = 0, k = 0, a=0,b=0, c=0;
	int arr[3] = { 0,1,2 };
	int arr1[3] = { 2,1,0 };
	int arr2[3] = { 0,1,2 };
	for (int i = 0; i < 3; i++)
	{
		k = 0;
		multiply = 1;
		for (int j = 0; j < 3; j++,k++)
		{
			a = arr[j]; b = arr2[k]; c = A[a][b];
			multiply *= c;
		}
		box = arr2[0];
		for (int k = 0; k < 2; k++)
		{
			arr2[k] = arr2[k + 1];
		}
		arr2[2] = box;
		sum1 += multiply;
	}
	cout << "sum1 " << sum1 << endl;
	multiply = 1;
	for (int i = 0; i < 3; i++)
	{
		k = 0;
		multiply = 1;
		for (int j = 0; j < 3; j++, k++)
		{
			a = arr[j]; b = arr1[k]; c = A[a][b];
			multiply *= c;
		}
		box = arr1[2];
		for (int k = 2; k > 0; k--)
		{
			arr1[k] = arr1[k - 1];
		}
		arr1[0] = box;
		sum2 += multiply;
	}
	cout << "sum2 " << sum2 << endl;
	cout << "Определитель матрицы С по алгоритму Саррюса, равен: " << sum1 + sum2 << endl;
}