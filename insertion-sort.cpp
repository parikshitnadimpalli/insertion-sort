#include <iostream>
#include <limits>
#include <new>
using namespace std;

int integerInput();
int getSize();
void insertionSort(int[], int);
void displayArray(int[], int);

int main()
{
	int size, * arr;

	cout << "Enter the size of the array: ";
	size = getSize();
	arr = new (nothrow) int[size];
	if (arr == nullptr)
	{
		cout << endl << "Failed to allocate memory! Please restart the application.";
		exit(0);
	}

	cout << endl << "Enter all the elements of the array: ";
	for (int i = 0; i < size; i++)
	{
		arr[i] = integerInput();
		cout << "Elements remaining to be entered: " << size - i - 1 << endl;
	}

	insertionSort(arr, size);
	displayArray(arr, size);

	return 0;
}

int integerInput()
{
	int n;

	while (!(cin >> n))
	{
		cin.clear();
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		cout << endl << "Invalid integer input! Please try again with correct input: ";
	}

	return n;
}

int getSize()
{
	int size = integerInput();

	if (size <= 0)
	{
		cout << endl << "Invalid size! Please try again: ";
		size = getSize();
	}

	return size;
}

void insertionSort(int arr[], int size)
{
	int i, temp, j;
	for (i = 1; i < size; i++)
	{
		temp = arr[i];
		j = i - 1;

		while (temp > arr[j] && j >= 0)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = temp;
	}
}

void displayArray(int arr[], int size)
{
	cout << endl << "The sorted array is: ";

	for (int i = 0; i < size; i++)
	{
		cout << "|" << arr[i] << "|";
	}
}