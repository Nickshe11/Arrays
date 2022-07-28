#include<iostream>
#define tab "\t"
#define delimiter "--------------------------------"

//#define SORT
//#define UniqueRandom
//#define Comparison

using namespace std;
const int ROWS = 3;//������
const int COLS = 4;//�������

void create(int arr[ROWS][COLS], const int ROWS, const int COLS);
void print(int arr[ROWS][COLS], const int ROWS, const int COLS);

void main()
{
	setlocale(LC_ALL, "");
	int box, mark = 0;
#ifdef SORT
	int arr[ROWS][COLS]{};
	create(arr, ROWS,COLS);
	print(arr, ROWS, COLS);
	
	//���������� �� �����������
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
						if (arr[i][j] > arr[k][l])
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
						if (arr[i][j] > arr[k][l])
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
	//����� ������� ����� ����������
	cout << endl;
	print(arr, ROWS, COLS);
#endif // SORT

#ifdef UniqueRandom
	// ���������� ������� ����������� �������

	cout << delimiter << "\n���������� ������� ����������� �������" << endl;
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
	//����� ������� ����� ����������
	cout << endl;
	print(brr, ROWS, COLS);

#endif//UniqueRandom

#ifdef Comparison
	// ��������� ��������� �������

	cout << delimiter << "\n��������� ��������� �������" << endl;
	mark = 0;
	box = 0;
	int counter = 0;
	//�������� �������
	int crr[ROWS][COLS]{};
	create(crr, ROWS, COLS);

	//����� ������� ����� ����������
	cout << endl;
	print(crr, ROWS, COLS);
	//���������
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			counter = 0;
			mark = 0;
			for (int k = i; k < ROWS; k++)
			{
				if (k == i)
				{
					for (int l = j + 1; l < COLS; l++)
					{
						if ((crr[i][j]) == crr[k][l])
						{
							counter++;
						}
					}
				}
				else
				{
					for (int l = 0; l < COLS; l++)
					{
						if ((crr[i][j]) == crr[k][l])
						{
							counter++;
						}
					}
				}
			}
			if (counter > 0)//���� ����� ����������
			{
				for (int k = i; k >= 0; k--)
				{
					if (k == i)
					{
						for (int l = j - 1; l >= 0; l--)
						{
							if (crr[i][j] == crr[k][l])
							{
								mark = 1;
							}
						}
					}
					else
					{
						for (int l = COLS; l >= 0; l--)
						{
							if (crr[i][j] == crr[k][l])
							{
								mark = 1;
							}
						}
					}
				}
			}
			if (mark == 0 && counter > 0)
			{
				cout << "\n����� " << crr[i][j] << " ����������� " << counter << " ���." << endl;
			}
		}
	}


#endif // Comparison
}
void create(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}
}

void print(int arr[ROWS][COLS], const int ROWS, const int COLS)
{

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}




