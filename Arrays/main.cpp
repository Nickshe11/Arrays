#include<iostream>
using namespace std;

#define tab "\t"

void main()
{
	setlocale(LC_ALL, "");
	int arr[10]{};
	int a = 0, b = 0, counter = 0;
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 10;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
	for (int i = 0; i < 9; i++)
	{
		if (arr[i] = arr[i + 1])
		{
		counter++;
		cout << "Число " << arr[i] << " повторяется " << counter << " раз" << endl;
		}
	}
		
}