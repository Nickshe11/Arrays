#include<iostream>
using namespace std;
#define tab "\t"

void main()
{
	setlocale(LC_ALL, "");
	int const n = 10;
	int arr[n] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < n; i++) cout << arr[i] << tab;
	cout << endl;
	int shift;
	cout << "Введите количество символов для смещения элементов массива: "; cin >> shift;
	
	int temp[n]{};
	for (int i = 0; i < n; i++)temp[i] = arr[i];
	for (int i = 0; i<n-shift; i++)
	{
		arr[i] = arr[i + shift];
	}
	for (int i = 0; i < shift; i++)
	{
		arr[n - shift + i] = temp[i];
	}
		for (int i = 0; i < n; i++) cout << arr[i] << tab;
		cout << endl; 
}