#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int find_word(vector<string> &a, int i, int j) {
    int count = 0;

    if(a[i-1][j-1] == 'M' && a[i-1][j+1] == 'S' && a[i+1][j-1] == 'M' && a[i+1][j+1] == 'S') {
        count++;
    }
    if(a[i-1][j-1] == 'S' && a[i-1][j+1] == 'S' && a[i+1][j-1] == 'M' && a[i+1][j+1] == 'M') {
        count++;
    }
    if(a[i-1][j-1] == 'M' && a[i-1][j+1] == 'M' && a[i+1][j-1] == 'S' && a[i+1][j+1] == 'S') {
        count++;
    }
    if(a[i-1][j-1] == 'S' && a[i-1][j+1] == 'M' && a[i+1][j-1] == 'S' && a[i+1][j+1] == 'M') {
        count++;
    }
    return count;
}

int main() {
    ifstream file("input.txt");

    if(!file.is_open()) {
        cerr << "Error opening file!";
        return 1;
    }

    string line;
    int num_found = 0;
    vector<string> a;
    while(getline(file, line)) {
        a.push_back(line);
    }

    for(int i = 1; i < a.size()-1; i++) {
        for(int j = 1; j < a[i].size()-1; j++) {
           
                 if(a[i][j] == 'A')
                    num_found += find_word(a,i,j);
        
        }
    }
    cout << num_found << endl;

    return 0;
}
