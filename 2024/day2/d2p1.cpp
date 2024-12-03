#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

bool differ(const vector<int> &num)
{
	for (int i = 0; i < num.size() - 1; i++)
	{
		int diff = abs(num[i + 1] - num[i]);
		if (!(1 <= diff && diff <= 3))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ifstream file("input.txt");

	if (!file.is_open())
	{
		cerr << "Error opening the file!" << std::endl;
		return 1;
	}

	string line;
	int count = 0;
	int diff;
	int number;
	vector<vector<int>> num;
	int j = 0;

	while (getline(file, line))
	{
		stringstream s(line);
		num.push_back(vector<int>());
		while (s >> number)
		{
			num[j].push_back(number);
		}
		j++;
	}

	for (int i = 0; i < num.size(); i++)
	{
		if (is_sorted(num[i].begin(), num[i].end()) && differ(num[i]))
		{
			count++;
		}

		else if (is_sorted(num[i].rbegin(), num[i].rend()) && differ(num[i]))
		{
			count++;
		}
		else
			continue;
	}
	cout << count << endl;

	file.close();
	return 0;
}
