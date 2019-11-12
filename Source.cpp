#include<iostream>
using std::cout;
using std::cin;
using std::endl;

void FillRand(int Arr[], const int n);

void Print(int Arr[], const int n);

void Sort(int Arr[], const int n);

int  Sum(int Arr[], const int n);

double Avg(int Arr[], const int n);

int  minValueIn(int Arr[], const int n);

int  maxValueIn(int Arr[], const int n);

void ShiftLeft(int Arr[], const int n);

void ShiftRight(int Arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;
	int Arr[n];

	FillRand(Arr, n);
	Print(Arr, n);
	Sort(Arr, n);
	Print(Arr, n);
	cout << "Сумма элементов массива: " << Sum(Arr, n) << endl;
	cout << "Среднее арифметическое : " << Avg(Arr, n) << endl;
	cout << "Минимальное значение в массиве: " << minValueIn(Arr, n) << endl;
	cout << "Максимальное значение в массиве: " << maxValueIn(Arr, n) << endl;
	cout << "циклический сдвиг массива влево:" << endl;
	ShiftLeft(Arr, n);
	Print(Arr, n);
	cout << endl << endl;
	Sort(Arr, n);
	cout << "циклический сдвиг массива вправо:" << endl;
	ShiftRight(Arr, n);
	Print(Arr, n);

}

void FillRand(int Arr[], const int n)
{
	//Заполнение массива случайными числами:
	for (int i = 0; i < n; i++)
	{
		Arr[i] = rand() % 100;
	}
}

void Print(int Arr[], const int n)
{
	//Вывод массива на экран:
	for (int i = 0; i < n; i++)
	{
		cout << Arr[i] << "\t";
	}
	cout << endl;
}

void Sort(int Arr[], const int n)
{
	//Сортировка:
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (Arr[j] < Arr[i])
			{
				int buffer = Arr[i];
				Arr[i] = Arr[j];
				Arr[j] = buffer;
			}
		}
	}
}

int  Sum(int Arr[], const int n)
{
	int Sum = 0;
	for (int i = 0; i < n; i++)
	{
		Sum += Arr[i];
	}
	return Sum;
}

double Avg(int Arr[], const int n)
{
	return (double)Sum(Arr, n) / n;
}

int  minValueIn(int Arr[], const int n)
{
	int min = Arr[0];
	for (int i = 0; i < n; i++)
	{
		if (Arr[i] < min)min = Arr[i];
	}
	return min;
}

int maxValueIn(int Arr[], const int n)
{
	int max = Arr[0];
	for (int i = 0; i < n; i++)
	{
		if (Arr[i] > max)max = Arr[i];
	}
	return max;
}

void ShiftLeft(int Arr[], const int n)
{
	int num = 3;
	for (int j = n-1; j > 0; j--)
	{
		for (int i = 0; i < num; i++)
		{
			int buffer = Arr[i];
			Arr[i] = Arr[j];
			Arr[j] = buffer;
		}
	}
}
void ShiftRight(int Arr[], const int n)
{
	int num = 1;
	for (int i = 0; i < num; i++)
	{
		int buffer1 = Arr[n - 1];
		for (int j = n-1; j >=0; j--)
		{
			Arr[j] = Arr[j - 1];
		
		}
		Arr[0]=buffer1;
	}
}