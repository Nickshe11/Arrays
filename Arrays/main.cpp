#include<iostream>
using namespace std;

#define tab "\t"

void main()
{
	setlocale(LC_ALL, "");
	const int MAX = 15;
	int arr[MAX]{};
	int mark = 0, counter = 0;
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % 10;
	}
	for (int i = 0; i < MAX; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
	for (int j = 0; j < MAX; j++)
	{
		counter = 0;
		mark = 0;
		for (int i = j; i < MAX; i++)
		{
			if (arr[j] == arr[i + 1])
			{
				counter++; mark = 1;
			}
		}
		if (counter > 0)
		{
			for (int k = j - 1; k >= 0; k--)
			{
				if (arr[j] == arr[k])
				{
					mark = 2;
				}
			}
		}
		if (mark == 1)
		{
			cout << "Число " << arr[j] << " повторяется " << counter << " раз" << endl;
		}
	}

}