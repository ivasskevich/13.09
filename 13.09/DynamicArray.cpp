
#include "DynamicArray.h"
#include<Windows.h>

DynamicArray::DynamicArray() :ptr(nullptr), size(0)
{}
DynamicArray::DynamicArray(int S)
{
	cout << "Construct by 1 param\n";
	size = S;
	ptr = new int[S] {0};
}

DynamicArray::DynamicArray(const DynamicArray& a)
{
	cout << "Copy construct\n";
	size = a.size;
	ptr = new int[size];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = a.ptr[i];
	}
}
DynamicArray::~DynamicArray()
{
	cout << "Destruct\n";
	if (ptr != 0)
	{
		delete[] ptr;
	}
	Sleep(1000);
}
void DynamicArray::Input()
{
	//srand(unsigned(time(NULL)));
	for (int i = 0; i < size; i++)
	{
		ptr[i] = rand() % 20;
	}
}
void DynamicArray::Output() const
{
	for (int i = 0; i < size; i++)
	{
		cout << ptr[i] << "\t";
	}
	cout << "\n---------------------------------\n";
}
int* DynamicArray::GetPointer() const
{
	return ptr;
}
int DynamicArray::GetSize() const
{
	return size;
}

void DynamicArray::ReSize(int s)
{
	if (size != s) {
		int* newPointer = new int[s];

		for (int i = 0; i < size; i++) {
			newPointer[i] = ptr[i];
		}
		for (int i = size; i < s; i++) {
			newPointer[i] = 0;
		}

		delete[] ptr;
		ptr = newPointer;
		size = s;
	}
	else {
		cout << "Array have same size. Input" << endl;
	}
}

void DynamicArray::Sort()
{
	for (int i = 1; i < size; i++) {
		int key = ptr[i];
		int j = i - 1;

		while (j >= 0 && ptr[j] > key) {
			ptr[j + 1] = ptr[j];
			j = j - 1;
		}
		ptr[j + 1] = key;
	}
}

int DynamicArray::Search(int a)
{
	for (int i = 0; i < size; i++) {
		if (ptr[i] == a) {
			return i;
		}
	}
	return -1;
}

void DynamicArray::Reverse()
{
	int startIndex = 0;
	int endIndex = size - 1;

	while (startIndex < endIndex) {
		int temp = ptr[startIndex];
		ptr[startIndex] = ptr[endIndex];
		ptr[endIndex] = temp;
		startIndex++;
		endIndex--;
	}
}