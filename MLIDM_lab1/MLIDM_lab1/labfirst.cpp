#include <iostream>
#include <vector>
#include <cstdbool>

#define endl "\n"

using namespace std;
//jcbi
struct MySet {
	char nedigit; 
	char digit; 
	char letter; 
	char edigit; 
};
//изменение
void InputSet(vector<MySet>& sets, int size) 
{
	MySet elem_S;
	for (int i = 0; i < size; i++)
	{
		cout << "Input Elem_Set " << i + 1 << ": ";
		string el_set;
		cin >> el_set;

		if (el_set.length() == 4 &&
			(el_set[0] >= '0' && el_set[0] <= '9' && ((el_set[0] - '0') % 2 != 0)) &&
			(el_set[1] >= '0' && el_set[1] <= '9') &&
			(el_set[2] >= 'a' && el_set[2] <= 'z') &&
			((el_set[3] >= '0' && el_set[3] <= '9' && ((el_set[3] - '0') % 2 == 0))))
		{
			elem_S.nedigit = el_set[0];
			elem_S.digit = el_set[1];
			elem_S.letter = el_set[2];
			elem_S.edigit = el_set[3];
			sets.push_back(elem_S);
		}

		else
		{
			cout << "Error Input. Try again" << endl;
			i--;
		}
	}

	cout << endl;
}

void OutputSet(vector<MySet>& sets)
{
	cout << "{ ";
	for (int i = 0; i < sets.size(); i++)
	{
		cout << sets[i].nedigit << sets[i].digit << sets[i].letter << sets[i].edigit;
		if(i + 1 != sets.size()) cout << ", ";

	}
	cout << " }" << endl;
}

void UniqueSet(vector<MySet>& sets) 
{
	vector<MySet> UniqueElSet;

	for (int i = 0; i < sets.size(); i++)
	{
		bool unique = true;

		for (size_t j = 0; j < UniqueElSet.size(); j++)
		{
			if (sets[i].nedigit == UniqueElSet[j].nedigit &&
				sets[i].digit == UniqueElSet[j].digit &&
				sets[i].letter == UniqueElSet[j].letter &&
				sets[i].edigit == UniqueElSet[j].edigit)
			{
				unique = false;
				break;
			}
		}

		if (unique) {
			UniqueElSet.push_back(sets[i]);
		}

	}

	sets.clear();
	for (int i = 0; i < UniqueElSet.size(); i++)
	{
		sets.push_back(UniqueElSet[i]);
	}
}

void UnionSets(vector<MySet>& set1, vector<MySet>& set2, vector<MySet>& sets)
{
	for (int i = 0; i < set1.size(); i++)
	{
		sets.push_back(set1[i]);
	}

	for (int i = 0; i < set2.size(); i++)
	{
		sets.push_back(set2[i]);
	}

	UniqueSet(sets);
}

void CrossingSets(vector<MySet>& set1, vector<MySet>& set2, vector<MySet>& sets)
{
	bool cross = true;
	for (int i = 0; i < set1.size(); i++)
	{
		for (int j = 0; j < set2.size(); j++)
		{
			if (set1[i].nedigit == set2[j].nedigit &&
				set1[i].digit == set2[j].digit &&
				set1[i].letter == set2[j].letter &&
				set1[i].edigit == set2[j].edigit)
			{
				sets.push_back(set1[i]);
				cross = false;
			}
		}
	}

	if (cross) cout << "The intersection of two sets does not exist" << endl;

}

void AdditionSet(vector<MySet>& set1, vector<MySet>& set2, vector<MySet>& sets)
{

	for (int i = 0; i < set1.size(); i++)
	{
		bool add = true;

		for (int j = 0; j < set2.size(); j++)
		{
			if (set1[i].nedigit == set2[j].nedigit &&
				set1[i].digit == set2[j].digit &&
				set1[i].letter == set2[j].letter &&
				set1[i].edigit == set2[j].edigit)
			{
				add = false;
				break;
			}
		}

		if(add) sets.push_back(set1[i]);
	}
}

void DifSet(vector<MySet>& set1, vector<MySet>& set2, vector<MySet>& sets)
{

	for (int i = 0; i < set1.size(); i++)
	{
		bool dif = true;
		for (int j = 0; j < set2.size(); j++)
		{
			if (set1[i].nedigit == set2[j].nedigit &&
				set1[i].digit == set2[j].digit &&
				set1[i].letter == set2[j].letter &&
				set1[i].edigit == set2[j].edigit)
			{
				dif = false;
				break;
			}
		}

		if (dif) sets.push_back(set1[i]);
	}

	for (int i = 0; i < set2.size(); i++)
	{
		bool dif = true;
		for (int j = 0; j < set1.size(); j++)
		{
			if (set2[i].nedigit == set1[j].nedigit &&
				set2[i].digit == set1[j].digit &&
				set2[i].letter == set1[j].letter &&
				set2[i].edigit == set1[j].edigit)
			{
				dif = false;
				break;
			}
		}

		if (dif) sets.push_back(set2[i]);
	}
	
}

int main()
{
	cout << "The elements should be entered in this order:\n \
		first elem (j) no even digit\n \
		second elem (c) - digit\n  \
		third elem (b) - letter\n \
		fourth elem (i) - even digit\n " << endl;

	int size_s1 = 0, size_s2 = 0;
	vector<MySet> set1;
	vector<MySet> set2;

	cout << "Input size first set: ";
	cin >> size_s1;
	cout << endl;
	InputSet(set1, size_s1);

	cout << "Input size second set: ";
	cin >> size_s2;
	cout << endl;
	InputSet(set2, size_s2);

	UniqueSet(set1);
	cout << "Elements first set: ";
	OutputSet(set1);

	UniqueSet(set2);
	cout << "Elements second set: ";
	OutputSet(set2);

	cout << endl;
	vector<MySet> set_union;
	UnionSets(set1, set2, set_union);
	cout << "Combining two sets: ";
	OutputSet(set_union);

	vector<MySet> set_intersection;
	cout << "Intersection two sets: ";
	CrossingSets(set1, set2, set_intersection);
	OutputSet(set_intersection);

	vector<MySet> set_addition12;
	AdditionSet(set1, set2, set_addition12);
	cout << "Addition Set1\\Set2: ";
	OutputSet(set_addition12);

	vector<MySet> set_addition21;
	AdditionSet(set2, set1, set_addition21);
	cout << "Addition Set2\\Set1: ";
	OutputSet(set_addition21);

	vector<MySet> set_difference;
	DifSet(set1, set2, set_difference);
	cout << "Symmetric difference two sets: ";
	OutputSet(set_difference);

	return 0;
}
