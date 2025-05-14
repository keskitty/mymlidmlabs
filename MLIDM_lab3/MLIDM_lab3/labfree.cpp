#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"
#define PAIR 2
using namespace std;


void InputSet(vector<char>& set, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Введите " << i + 1 << " элемент множества: ";
		char ch = 0;
		cin >> ch;
		if(('0' <= ch && ch <= '9') || ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z'))
			set.push_back(ch);
	
		else
		{
			cout << "Неверно введены значения. Попробуте еще раз." << endl;
			i--;
		}
	}

	cout << endl;
}

void InputRelate(vector<vector<char>>& set, int size, vector<char>& first_set, vector<char>& second_set)
{

	for (int i = 0; i < size; i++)
	{
		cout << "Введите элементы " << i + 1 << " пары:" << endl;
		vector <char> pair;
		for (int j = 0; j < PAIR; j++)
		{
			cout << "Введите " << j + 1 << " элемент пары отношения: ";
			char ch = 0;
			cin >> ch;

			if (j == 0) 
			{
				if (find(first_set.begin(), first_set.end(), ch) == first_set.end()) 
				{
					cout << "Элемент не принадлежит первому множеству. Попробуйте еще раз." << endl;
					j--;
					continue;
				}
			}

			else 
			{
				if (find(second_set.begin(), second_set.end(), ch) == second_set.end())
				{
					cout << "Элемент не принадлежит второму множеству. Попробуйте еще раз." << endl;
					j--;
					continue;
				}
			}

			pair.push_back(ch);
		
		}
		set.push_back(pair);
		cout << endl;
	}
	cout << endl;
}

void OutputSet(vector<char>& set)
{
	cout << "{ ";
	for (int i = 0; i < set.size(); i++)
	{
		cout << set[i];
		if (i + 1 != set.size()) cout << ", ";

	}
	cout << " }" << endl;
}

void OutputRelat(vector<vector<char>>& set, int size)
{
	cout << "{ ";

	for (int i = 0; i < size; i++) 
	{
		cout << "(";
		for (int j = 0; j < PAIR; j++) 
		{
			cout << set[i][j];
			if (j == 0) cout << ", ";
		}
		cout << ")";
		if (i + 1 != size) cout << ", ";
	}

	cout << " }" << endl;
}

int RelatIsFunc(vector<vector<char>>& set, int size, vector<char>& first_set)
{
	if (size == first_set.size())
	{
		for (int i = 0; i < size - 1; ++i)
		{
			if (set[i][0] == set[i + 1][0])
			{
				return 0;
			}
		}
	}

	else 
	{ 
		return 0;
	}

	return 1;

}
int main()
{
	setlocale(LC_ALL, "Russian");

	ios_base::sync_with_stdio(0); cin.tie(0);
	cout.setf(ios::fixed); cout.precision(8);

	int size_1 = 0;
	cout << "Введите количество элементов первого множества: ";
	cin >> size_1;
	cout << endl;
	vector<char>first_set;
	InputSet(first_set, size_1);
	sort(first_set.begin(), first_set.end());
	auto last1 = unique(first_set.begin(), first_set.end());
	first_set.resize(distance(first_set.begin(), last1));

	int size_2 = 0;
	cout << "Введите количество элементов второго множества: ";
	cin >> size_2;
	cout << endl;
	vector<char>second_set;
	InputSet(second_set, size_2);
	sort(second_set.begin(), second_set.end());
	auto last2 = unique(second_set.begin(), second_set.end());
	second_set.resize(distance(second_set.begin(), last2));


	int size_relat = 0;
	cout << "Введите количество пар элементов отношения: ";
	cin >> size_relat;
	cout << endl;
	vector < vector <char> > relat;
	InputRelate(relat, size_relat, first_set, second_set);

	cout << "Элементы первого множества: ";
	OutputSet(first_set);

	cout << "Элементы второго множества: ";
	OutputSet(second_set);

	cout << "Отношение двух множеств: ";
	OutputRelat(relat, size_relat);

	int FcRlt = RelatIsFunc(relat, size_relat, first_set);
	if (FcRlt == 1)
		cout << "Отношение является функцией" << endl;
	else
		cout << "Отношение не является функцией" << endl;
	return 0;

}