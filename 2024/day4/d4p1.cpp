#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int find_word(vector<string> &a, int i, int j) {
    int count = 0;
    //right
    if( j+3 < a[i].size() && a[i][j+1] == 'M' && a[i][j+2] == 'A' && a[i][j+3] == 'S') {
        count++;
    }
    //left
    if( !(j-3 < 0)  && a[i][j-1] == 'M' && a[i][j-2] == 'A' && a[i][j-3] == 'S') {
        count++;
    }
    //up
    if( !(i-3 < 0) && a[i-1][j] == 'M' && a[i-2][j] == 'A' && a[i-3][j] == 'S') {
        count++;
    }
    //down
    if( i+3 < a[i].size() && a[i+1][j] == 'M' && a[i+2][j] == 'A' && a[i+3][j] == 'S') {
        count++;
    }
    //up-right
    if( !(i-3 < 0) && j+3 < a[i].size() && a[i-1][j+1] == 'M' && a[i-2][j+2] == 'A' && a[i-3][j+3] == 'S') {
        count++;
    }
    //up-left
    if(!(i-3 < 0) && !(j-3 < 0) &&a[i-1][j-1] == 'M' && a[i-2][j-2] == 'A' && a[i-3][j-3] == 'S') {
        count++;
    }
    //down-left
    if(!(j-3 < 0) && i+3 < a[i].size() && a[i+1][j-1] == 'M' && a[i+2][j-2] == 'A' && a[i+3][j-3] == 'S') {
        count++;
    }
    //down-right
    if((i+3 < a[i].size()) && (j+3 < a[i].size()) && a[i+1][j+1] == 'M' && a[i+2][j+2] == 'A' && a[i+3][j+3] == 'S') {
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

    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[i].size(); j++) {
            if(a[i][j] == 'X') {
                num_found += find_word(a,i,j);
            }
        }
    }
    cout << num_found << endl;

    return 0;
}
