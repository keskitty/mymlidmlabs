//����������� ��������� �� (C++) ���������� ����������� ���� � �����. ��� ����� ������������ ��������. �������� ������������ ��������������. 
// � ��������� ������ �������� ��������� � �������� �������. ��� ������ ���������� ���������� ���� �������, ����� ������������ ������ � ��������� ��������� ����.

#include <iostream>
#include <locale.h>
#include <vector>
#include <map>
#include <set>
#include <limits>
#include <algorithm>

#define endl "\n"
#define PAIR 2

using namespace std;



void InputVGElem(vector<char>& VG, int size)
{
	cout << "���� �������� ������: " << endl;
	for (int i = 0; i < size; i++)
	{
		char elem = 0;
		cout << "������� �������� ������� �����: ";
		cin >> elem;
		if (('0' <= elem && elem <= '9') || ('a' <= elem && elem <= 'z') || ('A' <= elem && elem <= 'Z'))
		{ 
			VG.push_back(elem);
		}

		else
		{
			cout << "�������� ����������� �������� ������� �����. ���������� ��� ���." << endl;
			i--;
		}

	}
	cout << endl;
}

void InputEGPair(vector<vector<char >>& EG, vector<char>& VG, int size, vector<int>& coastpath)
{
	cout << "���� �����: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "������� ������� " << i + 1 << " �����: " << endl;
		vector <char> pair_ribs;
		for (int j = 0; j < PAIR; j++)
		{
			cout << "������� " << j + 1 << " ������� �����: ";
			char elem = 0;
			cin >> elem;

			if (j == 0)
			{
				if (find(VG.begin(), VG.end(), elem) == VG.end() ||
					!(('0' <= elem && elem <= '9') || ('a' <= elem && elem <= 'z') || ('A' <= elem && elem <= 'Z')))
				{
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "����� ������� � ����� �� �������." << endl;
					j--;
					continue;
				}
			}

			pair_ribs.push_back(elem);

		}

		EG.push_back(pair_ribs);
		int coast = 0;
		cout << "������� ��������� ������� ����: ";
		cin >> coast;
		coastpath.push_back(coast);

		cout << endl;
	}
	cout << endl;
}

void OutputTop(vector<char>& VG)
{
	cout << "{ ";
	for (int i = 0; i < VG.size(); i++)
	{
		cout << VG[i];
		if (i + 1 != VG.size()) cout << ", ";

	}
	cout << " }" << endl;
}

void OutputRibs(vector<vector<char>>& EG)
{
	cout << "{ ";

	for (int i = 0; i < EG.size(); i++)
	{
		cout << "(";
		for (int j = 0; j < PAIR; j++)
		{
			cout << EG[i][j];
			if (j == 0) cout << ", ";
		}
		cout << ")";
		if (i + 1 != EG.size()) cout << ", ";
	}

	cout << " }" << endl;
}



void SearchPath(char start, char end, const vector<vector<char>>& EG, const vector<int>& coastpath, const vector<char>& VG) 
{
	const int nopath = numeric_limits<int>::max();
	map<char, int> dist;
	map<char, char> prev;
	set<char> unvisited;


	for (char v : VG) {
		dist[v] = nopath;
		unvisited.insert(v);
	}
	dist[start] = 0;

	while (!unvisited.empty()) {
		char u = *unvisited.begin();
		for (char v : unvisited) {
			if (dist[v] < dist[u]) {
				u = v;
			}
		}


		if (u == end || dist[u] == nopath) {
			break;
		}

		unvisited.erase(u);

		for (int i = 0; i < EG.size(); ++i) {
			if (EG[i][0] == u) {
				char v = EG[i][1];
				int alt = dist[u] + coastpath[i];
				if (alt < dist[v]) {
					dist[v] = alt;
					prev[v] = u;
				}
			}
			else if (EG[i][1] == u) {
				char v = EG[i][0];
				int alt = dist[u] + coastpath[i];
				if (alt < dist[v]) {
					dist[v] = alt;
					prev[v] = u;
				}
			}
		}
	}

	if (dist[end] == nopath) {
		cout << "���� ����� ��������� " << start << " � " << end << " �� ����������" << endl;
		return;
	}

	vector<char> path;
	char current = end;
	while (current != start) {
		path.push_back(current);
		current = prev[current];
	}
	path.push_back(start);
	reverse(path.begin(), path.end());


	cout << "���������� ����: ";
	for (int i = 0; i < path.size(); ++i) {
		cout << path[i];
		if (i != path.size() - 1) {
			cout << " -> ";
		}
	}
	cout << endl << "��������� ��������� ����: " << dist[end] << endl;
}



int main() {
	setlocale(LC_ALL, "Russian");

	int size_top = 0;
	cout << "������� ���������� ������ � �����: ";
	cin >> size_top;
	vector<char> VG;
	InputVGElem(VG, size_top);
	cout << endl;

	int size_ribs = 0;
	cout << "������� ���������� ����� � �����: ";
	cin >> size_ribs;
	vector<vector<char>> EG;
	vector<int> coastpath;
	InputEGPair(EG, VG, size_ribs, coastpath);

	cout << "������� �����: " << endl;
	OutputTop(VG);
	cout << "����� �����: " << endl;
	OutputRibs(EG);
	cout << endl;

	cout << "����� ��������� ����: " << endl;
	char start = 0;
	cout << "������� ��������� �������: ";
	cin >> start;
	char end = 0;
	cout << "������� �������� �������: ";
	cin >> end;

	SearchPath(start, end, EG, coastpath, VG);



	return 0;
}