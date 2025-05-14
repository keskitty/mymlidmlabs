#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <vector>

#define endl "\n"
using namespace std;


void InputSet(vector<vector<int>> & matrs, int size)
{
	setlocale(LC_ALL, "Russian");
	cout << "Введенный элемент должен быть равен 0 или 1." << endl;
	for (int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j ++)
		{
			cout << "Введите элемент " << i + 1 << " строки " << j + 1 << " столбца: ";
			cin >> matrs[i][j];

			if (matrs[i][j] == 1 || matrs[i][j] == 0)
			{
				matrs[i].push_back(matrs[i][j]);
			}

			else
			{
				cout << "Неверно введено значение. Попробуйте еще раз" << endl;
				j--;
			}
		}
	}

	cout << endl;
}

void OutputSet(vector<vector<int>>& matrs, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << matrs[i][j] << " ";
		}
		cout << endl;
	}
}

int Reflexivity(vector<vector<int>>& matrs, int size)
{
	bool Reflex = true;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j && matrs[i][j] != 1)
			{
				Reflex = false;
				break;
			}
		}

		if (!Reflex)
		{
			return 0;
		}
	}
	return 1;
}

int Symmetry(vector<vector<int>>& matrs, int size)
{
	bool Reflex = true;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (matrs[i][j] != matrs[j][i])
			{
				Reflex = false;
				break;
			}
		}

		if (!Reflex)
		{
			return 0;
		}
	}
	return 1;
}

int Kosimetric(vector<vector<int>>& matrs, int size)
{
	bool Kstrc = true;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (!(matrs[i][j] == 1 && i != j) || (matrs[j][i] == 0))
			{ 
				//pravilno
			}
			else
			{
				Kstrc = false;
				break;
			}
		}

		if (!Kstrc)
		{
			return 0;
		}
	}
	return 1;
}

int Transition(vector<vector<int>>& matrs, int size)
{
	bool Transt = true;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (matrs[i][j] == 1)
			{
				for (int k = 0; k < size; k++)
				{
					if (matrs[j][k] == 1 && matrs[i][k] != 1)
					{
						Transt = false;
						break;
					}
				}
			}
			if(!Transt) break;
		}
		if (!Transt) return 0;
	}

	return 1;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int size = 0;
	cout << "Введите размерность массива: ";
	cin >> size;
	cout << endl;
	
	vector < vector <int> > matr_otn(size, vector <int>(size));
	InputSet(matr_otn, size);

	cout << "Ваша матрица: " << endl;
	OutputSet(matr_otn, size);
	cout << endl;

	int Rflx = Reflexivity(matr_otn, size);
	if (Rflx == 1) cout << "Отношение обладает свойством рефлексивности" << endl;
	if (Rflx == 0) cout << "Отношение не обладает свойством рефлексивности" << endl;

	int Symtr = Symmetry(matr_otn, size);
	if (Symtr == 1) cout << "Отношение обладает свойством симметричности" << endl;
	if (Symtr == 0) cout << "Отношение не обладает свойством симметричности" << endl;	
	
	int Kstr = Kosimetric(matr_otn, size);
	if (Kstr == 1) cout << "Отношение обладает свойством кососимметричности" << endl;
	if (Kstr == 0) cout << "Отношение не обладает свойством кососимметричности" << endl;

	int Transt = Transition(matr_otn, size);
	if (Transt == 1) cout << "Отношение обладает свойством транзитивности" << endl;
	if (Transt == 0) cout << "Отношение не обладает свойством транзитивности" << endl;

	return 0;
}