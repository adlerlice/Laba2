#include <iostream>
#include <math.h>
using namespace std;
void fill_arr(int** arr, int rows, int cols, int a, int b);
void red_area_analyze(int** arr, int rows);
void red_area_show_element(int** arr, int rows, int& min, int& imin, int& jmin);
void green_area_analyze(int** arr, int cols);
void green_area_show_element(int** arr, int cols, int a, int& max, int& imax, int& jmax);
void modification(int** arr, int cols, int a, int max, int min, int jmax, int imax, int imin, int jmin, int rows);
int main()
{
	int rows, cols, a, b;
	cout << "Enter left border a= ";
	cin >> a;
	cout << "Enter right border b= ";          // Левая и правая граница значений в матрице
	cin >> b;
	int max = a;
	int imax = 0, jmax = 0;
	int imin = 0, jmin = 0;
	int min = INT_MAX;
	cout << "Enter number of rows = ";
	cin >> rows;
	cout << "\n";
	cols = rows;                        //Количество столбиков в матрице
	cout << "Matrix:\n";
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	fill_arr(arr, rows, cols, a, b);
	red_area_analyze(arr, rows);
	red_area_show_element(arr, rows, min, imin, jmin);
	green_area_analyze(arr, cols);
	green_area_show_element(arr, cols, a, max, imax, jmax);
	modification(arr, cols, a, max, min, jmax, imax, imin, jmin, rows);
	delete[] arr;

}
void fill_arr(int** arr, int rows, int cols, int a, int b)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = a + rand() % (b - a + 1);
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
void red_area_analyze(int** arr, int rows)
{
	cout << "Elements above the main diagonal:\n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (i >= rows - j) cout << arr[i][j] << " ";
		}
	}
	cout << endl;
	system("pause");
}
void red_area_show_element(int** arr, int rows, int& min, int& imin, int& jmin)
{
	cout << "The minimum positive element: ";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (i >= rows - j)
			{
				if (arr[i][j] > 0)
				{
					if (arr[i][j] < min)
					{
						min = arr[i][j];
						imin = i;
						jmin = j;
					}
				}
			}
		}
	}
	if (min > 0 && min != INT_MAX)
	{
		cout << min << "\n";; //Вывод минимального положительного числа выше гланой диагонали
		system("pause");
	}
	else {
		cout << "There aren`t positive elements\n";
	}
}
void green_area_analyze(int** arr, int cols)
{
	cout << "Elemets under the main diagonal and above the collateral diagonal:\n";
	for (int i = 0; i < cols; i++)
		for (int j = i + 1; j < cols - i - 1; j++)
		{
			cout << arr[i][j] << " ";
		}
	system("pause");
}
void green_area_show_element(int** arr, int cols, int a, int& max, int& imax, int& jmax)
{
	cout << "The maximum negative: ";

	for (int i = 0; i < cols; i++)
	{
		for (int j = i + 1; j < cols - i - 1; j++)
		{
			if (arr[i][j] < 0)
			{
				if (arr[i][j] > max)
				{
					max = arr[i][j];
					imax = i;
					jmax = j;
				}
			}
		}
	}
	cout << max;
	system("pause");
}
void modification(int** arr, int cols, int a, int max, int min, int jmax, int imax, int imin, int jmin, int rows)
{
	if (max < 0 && max != a && min > 0 && min != INT_MAX) {
		cout << "New modified matrix: \n";
		int extra;
		extra = arr[imin][jmin];
		arr[imin][jmin] = arr[imax][jmax];
		arr[imax][jmax] = extra;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << arr[i][j] << "\t";

			}
			cout << endl;
		}
	}
	else if (max >= 0 || max == a)
	{
		cout << "No negative elements  under the main diagonal and above the collateral diagonal, change data.";
	}
	else if (min <= 0 || min == INT_MAX)
	{
		cout << "No positive elements above the main diagonale, change data.";
	}
	else
	{
		cout << "No negative elements  under the main diagonal and above the collateral diagonal and No positive elements above the main diagonale.";
	}
}
