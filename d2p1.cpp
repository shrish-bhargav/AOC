#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
	ifstream file("test.txt");

	if(!file.is_open()) {
		cerr << "Error opening the file!" << std::endl;
		return 1;
	}

	string line;
	int count  = 0;
	vector<int> num;
	while(getline(file, line)) {
		for(int i = 0; i < line.size(); i++)
			num.push_back(stoi(line));
	}
	for(int i = 0; i < num.size(); i++) {
		cout << num[i] << " " ;
	}
	cout << endl;

	file.close();
	return 0;
}


