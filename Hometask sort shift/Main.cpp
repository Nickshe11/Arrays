#include<iostream>
#define tab "\t"
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	const int ROWS = 3;//строки
	const int COLS = 4;//столбцы
	int arr[ROWS][COLS]{};
	int box;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	//Сортировка по возрастанию
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			for (int k = i; k < ROWS; k++)
			{
				switch (k>i)
				{
				case(0):
					for (int l = j; l < COLS; l++)
					{
						if (arr[i][j] < arr[k][l])
						{
							box = arr[i][j];
							arr[i][j] = arr[k][l];
							arr[k][l] = box;
						}
					}
					break;
				case (1):
					for (int l = 0; l < COLS; l++)
					{
						if (arr[i][j] < arr[k][l])
						{
							box = arr[i][j];
							arr[i][j] = arr[k][l];
							arr[k][l] = box;
						}
					}
					break;
				}



			}
		}
	}
	//Вывод массива после сортировки
	cout << endl;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}