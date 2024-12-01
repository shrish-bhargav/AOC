#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	
	ifstream file("input.txt");

	if(!file.is_open()) {
		cerr << "Error opening the file!";
		return 1;
	}

	int num1, num2;
	int distance, sum = 0;
	vector<int> one; vector<int> two;
	while(file >> num1 >> num2) {
		one.push_back(num1);
		two.push_back(num2);
	}


	file.close();

	sort(one.begin(), one.end());
	sort(two.begin(), two.end());
	
	for(auto num = 0; num < one.size(); num++) {
		distance = max(one[num], two[num]) - min(one[num], two[num]);
		sum += distance;
	}
	cout << sum << endl;

	return 0;
}
