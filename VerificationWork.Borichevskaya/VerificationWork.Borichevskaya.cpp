#include <iostream>
#include <fstream>

using namespace std;

int ContentsFile(char*);
int* InitArray(char*, int);
int* MergeArrays(int*, int, int*, int, int&);
void ShowContentsFile(char*);
void DisplayArray(int*, int);
void CreateFile(char*, int*, int);

int main()
{
	char fileNameFirstNumber[25];
	cout << "Enter the name of source files: " << endl;
	cout << "The first file: ";
	cin >> fileNameFirstNumber;
	char fileNameSecondNumber[25];
	cout << "The second file: ";
	cin >> fileNameSecondNumber;
	char fileNameResultNumbers[25];
	cout << "Enter the name of result file: " << endl;
	cin >> fileNameResultNumbers;
	system("cls");

	cout << "Sourse files: " << endl;
	cout << "The first numbers: " << endl;
	ShowContentsFile(fileNameFirstNumber);
	cout << "The second numbers: " << endl;
	ShowContentsFile(fileNameSecondNumber);

	int l = 0;
	int n = ContentsFile(fileNameFirstNumber);
	int m = ContentsFile(fileNameSecondNumber);
	int* a = InitArray(fileNameFirstNumber, n);
	int* b = InitArray(fileNameSecondNumber, m);
	int* result = MergeArrays(a, n, b, m, l);
	cout << "New array: " << endl;
	DisplayArray(result, l);
	cout << endl;
	CreateFile(fileNameResultNumbers, result, l);
	delete[] a;
	delete[] b;
	delete[] result;
	system("pause");
	system("cls");

	return 0;
}

int ContentsFile(char* fileName)
{
	ifstream streamIn(fileName);
	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	int count = 0, term;
	while (!streamIn.eof())
	{
		streamIn >> term;
		count++;
	}
	streamIn.close();
	return count;
}

int* InitArray(char* fileName, int n)
{
	ifstream streamIn(fileName);
	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		streamIn >> arr[i];
	streamIn.close();
	return arr;
}

int* MergeArrays(int* a, int n, int* b, int m, int& l)
{
	l = n + m;
	int* c = new int[l];
	int i = 0, j = 0, k = 0;
	for (; i < n && j < m; k++)
	{
		if (a[i] < b[j])
		{
			c[k] = a[i];
			i++;
		}
		else
		{
			c[k] = b[j];
			j++;
		}
	}
	if (i == n)
	for (; j < m; j++, k++)
		c[k] = b[j];
	else
	for (; i < n; i++, k++)
		c[k] = a[i];
	return c;
}

void ShowContentsFile(char* fileName)
{
	ifstream streamIn;
	streamIn.open(fileName);
	if (!streamIn.is_open())
	{
		cout << " Cannot open file " << fileName << " to read!" << endl;
		system("pause");
		exit(1);
	}
	char string[25] = "";
	while (!streamIn.eof())
	{
		streamIn.getline(string, 25, '\n');
		cout << string << endl;
	}
}

void DisplayArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "  ";
}

void CreateFile(char* fileName, int* arr, int n)
{
	ofstream streamOut(fileName);
	if (!streamOut.is_open())
	{
		cout << "Cannot open file to write!" << endl;
		system("pause");
		exit(1);
	}
	int temp;
	for (int i = 0; i < n; i++)
	{
		temp = arr[i];
		streamOut << temp << " ";
	}
	streamOut.close();
}