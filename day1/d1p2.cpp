#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	ifstream file("input.txt");

	if(!file.is_open()) {
		cerr << "Error opening the file!";
		return 1;
	}

	int num1,num2, similarity = 0, counter = 0, sum = 0;
	vector<int> one;
	vector<int> two;
	vector<int> count;
	while(file >> num1 >> num2) {
		one.push_back(num1);
		two.push_back(num2);
	}

	unordered_map<int,int> frequencyMap1;
	unordered_map<int,int> frequencyMap2;

	for(int i = 0; i < two.size(); i++) {
		frequencyMap1[one[i]]++;
		frequencyMap2[two[i]]++;

	}

	for(const auto& i : frequencyMap1) {
		sum += i.first*frequencyMap2[i.first]*frequencyMap1[i.first];
	}
	cout << sum << endl;
	file.close();
	return 0;
}


