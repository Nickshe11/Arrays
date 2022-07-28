#include<iostream>
#define tab "\t"
#define delimiter "--------------------------------"
//#define SORT
//#define UniqueRandom
#define Comparison
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	const int ROWS = 3;//строки
	const int COLS = 4;//столбцы
	int arr[ROWS][COLS]{};
	int box, mark = 0;
#ifdef SORT
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
				switch (k > i)
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
#endif // SORT

#ifdef UniqueRandom
	// Заполнение массива уникальными числами

	cout << delimiter << "\nЗаполнение массива уникальными числами" << endl;
	mark = 0;
	int brr[ROWS][COLS]{};
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			brr[i][j] = rand() % 100;
			if (j == 0)
			{
				for (int k = i - 1; k >= 0; k--)
				{
					for (int l = COLS - 1; l >= 0; l--)
					{
						if (brr[i][j] == brr[k][l])
						{
							mark = 1;
						}
					}
				}
			}
			else
			{
				for (int k = i; k >= 0; k--)
				{
					if (k == i)
					{
						for (int l = j - 1; l >= 0; l--)
						{
							if (brr[i][j] == brr[k][l])
							{
								mark = 1;
							}
						}

					}
					else
					{
						for (int l = COLS - 1; l >= 0; l--)
							if (brr[i][j] == brr[k][l])
							{
								mark = 1;
							}
					}
				}
			}
			if (mark == 1)
			{
				j--;
			}

		}
	}
	//Вывод массива после заполнения
	cout << endl;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << brr[i][j] << tab;
		}
		cout << endl;
	}

#endif//UniqueRandom

#ifdef Comparison


	// Сравнение элементов массива

	cout << delimiter << "\nСравнение элементов массива" << endl;
	mark = 0;
	box = 0;
	int counter = 0;
	int crr[COLS][ROWS]{};
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			crr[i][j] = rand() % 10;
		}
	}

	//Вывод массива после заполнения
	cout << endl;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << crr[i][j] << tab;
		}
		cout << endl;
	}

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			for (int k = i; k < ROWS; k++)
			{
				for (int l = j-1; l < COLS; l++)
				{
					if ((crr[i][j]) == crr[k][l])
					{
						counter++;//дальше обратное сравнение
					}
				}
			}
		}
	}


#endif // Comparison


}



